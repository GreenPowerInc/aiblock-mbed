#ifndef MBED_PERIPHERALNAMES_H
#define MBED_PERIPHERALNAMES_H

#include "cmsis.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    ADC_1 = (int)ADC1_BASE,
    ADC_2 = (int)ADC2_BASE,
    ADC_3 = (int)ADC3_BASE
} ADCName;

typedef enum {
    DAC_1 = DAC_BASE
} DACName;

typedef enum {
    UART_1 = (int)USART1_BASE,
    UART_2 = (int)USART2_BASE,
    UART_3 = (int)USART3_BASE,
    UART_4 = (int)UART4_BASE,
    UART_5 = (int)UART5_BASE,
    UART_6 = (int)USART6_BASE,
    UART_7 = (int)UART7_BASE,
    UART_8 = (int)UART8_BASE
} UARTName;

#define DEVICE_SPI_COUNT 6
typedef enum {
    SPI_1 = (int)SPI1_BASE,
    SPI_2 = (int)SPI2_BASE,
    SPI_3 = (int)SPI3_BASE,
    SPI_4 = (int)SPI4_BASE,
    SPI_5 = (int)SPI5_BASE,
    SPI_6 = (int)SPI6_BASE
} SPIName;

typedef enum {
    I2C_1 = (int)I2C1_BASE,
    I2C_2 = (int)I2C2_BASE,
    I2C_3 = (int)I2C3_BASE,
    I2C_4 = (int)I2C4_BASE
} I2CName;

typedef enum {
    PWM_1  = (int)TIM1_BASE,
    PWM_2  = (int)TIM2_BASE,
    PWM_3  = (int)TIM3_BASE,
    PWM_4  = (int)TIM4_BASE,
    PWM_5  = (int)TIM5_BASE,
    PWM_8  = (int)TIM8_BASE,
    PWM_9  = (int)TIM9_BASE,
    PWM_10 = (int)TIM10_BASE,
    PWM_11 = (int)TIM11_BASE,
    PWM_12 = (int)TIM12_BASE,
    PWM_13 = (int)TIM13_BASE,
    PWM_14 = (int)TIM14_BASE
} PWMName;

typedef enum {
    CAN_1 = (int)CAN1_BASE,
    CAN_2 = (int)CAN2_BASE
} CANName;

typedef enum {
    QSPI_1 = (int)QSPI_R_BASE,
} QSPIName;

typedef enum {
    USB_FS = (int)USB_OTG_FS_PERIPH_BASE,
    USB_HS = (int)USB_OTG_HS_PERIPH_BASE
} USBName;

#ifdef __cplusplus
}
#endif

#endif
