// BSD 2-Clause License
//
// Copyright (c) 2020, GreenPower 貝里斯商環能綠力生技
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

//
// SYSCLK   216 MHz
// AHBCLK   216 MHz
// APB1CLK  54  MHz
// APB2CLK  108 MHz
// USB      48  MHz
//

// The on board HSE freq is equals to HSI (16MHz), settings of PLL is the same.

#include "stm32f7xx.h"
#include "nvic_addr.h"
#include "mbed_error.h"

// 在 mbed_app.json 中設定 CLOCK_SOURCE
#define USE_PLL_HSE_XTAL 0x4 // Use external crystal
#define USE_PLL_HSI 0x2      // Use HSI internal clock

#define ENABLE_PLL_HSE_XTAL ((CLOCK_SOURCE)&USE_PLL_HSE_XTAL)
#define ENABLE_PLL_HSI ((CLOCK_SOURCE)&USE_PLL_HSI)

#if ENABLE_PLL_HSE_XTAL
uint8_t SetSysClock_PLL_HSE();
#endif /* #if ENABLE_PLL_HSE_XTAL */

#if ENABLE_PLL_HSI
uint8_t SetSysClock_PLL_HSI(void);
#endif /* #if ENABLE_PLL_HSI */

void SystemInit(void)
{
    SCB->CPACR |= ((3UL << 10 * 2) | (3UL << 11 * 2));
    RCC->CR |= (uint32_t)0x00000001;
    RCC->CFGR = 0x00000000;
    RCC->CR &= (uint32_t)0xFEF6FFFF;
    RCC->PLLCFGR = 0x24003010;
    RCC->CR &= (uint32_t)0xFFFBFFFF;
    RCC->CIR = 0x00000000;
    SCB->VTOR = NVIC_FLASH_VECTOR_ADDRESS;
}

void SetSysClock(void)
{
#if ((CLOCK_SOURCE)&USE_PLL_HSE_XTAL)
    // 嘗試使用外部高速晶振
    if (SetSysClock_PLL(USE_PLL_HSE_XTAL) == 0)
#endif
    {
#if ((CLOCK_SOURCE)&USE_PLL_HSI)
        // 如果外部高速晶振啟動失敗，改用內部高速RC震盪
        if (SetSysClock_PLL(USE_PLL_HSI) == 0)
#endif
        {
            error("SetSysClock failed\n");
        }
    }
}

uint8_t SetSysClock_PLL(int source)
{
    RCC_OscInitTypeDef RCC_OscInitStruct;

    __PWR_CLK_ENABLE();
#if ENABLE_PLL_HSE_XTAL
    if (source & ENABLE_PLL_HSE_XTAL)
    {
        __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    }

    if (source & ENABLE_PLL_HSE_XTAL)
    {
        // 使用外部高速晶體 = 16 MHz
        RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
        RCC_OscInitStruct.HSEState = RCC_HSE_ON;
        RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
        RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    }
    else
#endif // #if ENABLE_PLL_HSE_XTAL
    {
        // 使用內部高速RC震盪 = 16 MHz
        RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
        RCC_OscInitStruct.HSIState = RCC_HSI_ON;
        RCC_OscInitStruct.HSEState = RCC_HSE_OFF;
        RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
        RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
        RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    }

    RCC_OscInitStruct.PLL.PLLM = 8;             // PLL 預除頻 8 倍  = 2 MHz (16 MHz / 8)，PLL 輸入頻率必須為 1 或 2 MHZ
    RCC_OscInitStruct.PLL.PLLN = 216;           // PLL 倍頻 216 倍  = 432 MHz (2 MHz * 216)
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2; // PLLCLK 除頻 2 倍 = 216 MHz (432 MHz / 2)，提供系統頻率，STM32F756ZG 最大為 216 MHz
    RCC_OscInitStruct.PLL.PLLQ = 9;             // PLLQ 除頻 9 倍   = 48 MHz，這是給 USB, SDMMC, RNG 用的頻率

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        return 0; // FAIL
    }

    // 啟用 OverDrive 模式以使用 216 MHz
    if (HAL_PWREx_EnableOverDrive() != HAL_OK)
    {
        return 0; // FAIL
    }

    // 使用 PLLCLK 作為系統時鐘，以及設定 APB1 APB2 除頻以符合外圍設備頻率
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; // 216 MHz
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;        // 216 MHz
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;         //  54 MHz
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;         // 108 MHz

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
    {
        return 0; // FAIL
    }

    RCC_PeriphCLKInitTypeDef RCC_PeriphClkInitStruct;
    RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_CLK48;
    RCC_PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48SOURCE_PLL;
    if (HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInitStruct) != HAL_OK)
    {
        return 0; // FAIL
    }

    return 1; // OK
}
