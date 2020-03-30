#ifndef MBED_PINNAMES_H
#define MBED_PINNAMES_H

#include "cmsis.h"
#include "PinNamesTypes.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef enum
{
    ALT0 = 0x100,
    ALT1 = 0x200,
    ALT2 = 0x300,
    ALT3 = 0x400
} ALTx;

typedef enum
{
    PA_0 = 0x00,
    PA_0_ALT0 = PA_0 | ALT0,
    PA_0_ALT1 = PA_0 | ALT1,
    PA_1 = 0x01,
    PA_1_ALT0 = PA_1 | ALT0,
    PA_1_ALT1 = PA_1 | ALT1,
    PA_2 = 0x02,
    PA_2_ALT0 = PA_2 | ALT0,
    PA_2_ALT1 = PA_2 | ALT1,
    PA_3 = 0x03,
    PA_3_ALT0 = PA_3 | ALT0,
    PA_3_ALT1 = PA_3 | ALT1,
    PA_4 = 0x04,
    PA_4_ALT0 = PA_4 | ALT0,
    PA_5 = 0x05,
    PA_5_ALT0 = PA_5 | ALT0,
    PA_6 = 0x06,
    PA_6_ALT0 = PA_6 | ALT0,
    PA_7 = 0x07,
    PA_7_ALT0 = PA_7 | ALT0,
    PA_7_ALT1 = PA_7 | ALT1,
    PA_7_ALT2 = PA_7 | ALT2,
    PA_8 = 0x08,
    PA_9 = 0x09,
    PA_10 = 0x0A,
    PA_11 = 0x0B,
    PA_12 = 0x0C,
    PA_13 = 0x0D,
    PA_14 = 0x0E,
    PA_15 = 0x0F,
    PA_15_ALT0 = PA_15 | ALT0,

    PB_0 = 0x10,
    PB_0_ALT0 = PB_0 | ALT0,
    PB_0_ALT1 = PB_0 | ALT1,
    PB_1 = 0x11,
    PB_1_ALT0 = PB_1 | ALT0,
    PB_1_ALT1 = PB_1 | ALT1,
    PB_2 = 0x12,
    PB_3 = 0x13,
    PB_3_ALT0 = PB_3 | ALT0,
    PB_4 = 0x14,
    PB_4_ALT0 = PB_4 | ALT0,
    PB_4_ALT1 = PB_4 | ALT1,
    PB_5 = 0x15,
    PB_5_ALT0 = PB_5 | ALT0,
    PB_5_ALT1 = PB_5 | ALT1,
    PB_6 = 0x16,
    PB_7 = 0x17,
    PB_8 = 0x18,
    PB_8_ALT0 = PB_8 | ALT0,
    PB_8_ALT1 = PB_8 | ALT1,
    PB_9 = 0x19,
    PB_9_ALT0 = PB_9 | ALT0,
    PB_9_ALT1 = PB_9 | ALT1,
    PB_10 = 0x1A,
    PB_11 = 0x1B,
    PB_12 = 0x1C,
    PB_13 = 0x1D,
    PB_14 = 0x1E,
    PB_14_ALT0 = PB_14 | ALT0,
    PB_14_ALT1 = PB_14 | ALT1,
    PB_15 = 0x1F,
    PB_15_ALT0 = PB_15 | ALT0,
    PB_15_ALT1 = PB_15 | ALT1,

    PC_0 = 0x20,
    PC_0_ALT0 = PC_0 | ALT0,
    PC_0_ALT1 = PC_0 | ALT1,
    PC_1 = 0x21,
    PC_1_ALT0 = PC_1 | ALT0,
    PC_1_ALT1 = PC_1 | ALT1,
    PC_2 = 0x22,
    PC_2_ALT0 = PC_2 | ALT0,
    PC_2_ALT1 = PC_2 | ALT1,
    PC_3 = 0x23,
    PC_3_ALT0 = PC_3 | ALT0,
    PC_3_ALT1 = PC_3 | ALT1,
    PC_4 = 0x24,
    PC_4_ALT0 = PC_4 | ALT0,
    PC_5 = 0x25,
    PC_5_ALT0 = PC_5 | ALT0,
    PC_6 = 0x26,
    PC_6_ALT0 = PC_6 | ALT0,
    PC_7 = 0x27,
    PC_7_ALT0 = PC_7 | ALT0,
    PC_8 = 0x28,
    PC_8_ALT0 = PC_8 | ALT0,
    PC_9 = 0x29,
    PC_9_ALT0 = PC_9 | ALT0,
    PC_10 = 0x2A,
    PC_11 = 0x2B,
    PC_12 = 0x2C,
    PC_13 = 0x2D,
    PC_14 = 0x2E,
    PC_15 = 0x2F,

    PD_0 = 0x30,
    PD_1 = 0x31,
    PD_2 = 0x32,
    PD_3 = 0x33,
    PD_4 = 0x34,
    PD_5 = 0x35,
    PD_6 = 0x36,
    PD_7 = 0x37,
    PD_8 = 0x38,
    PD_9 = 0x39,
    PD_10 = 0x3A,
    PD_11 = 0x3B,
    PD_12 = 0x3C,
    PD_13 = 0x3D,
    PD_14 = 0x3E,
    PD_15 = 0x3F,

    PE_0 = 0x40,
    PE_1 = 0x41,
    PE_2 = 0x42,
    PE_3 = 0x43,
    PE_4 = 0x44,
    PE_5 = 0x45,
    PE_6 = 0x46,
    PE_7 = 0x47,
    PE_8 = 0x48,
    PE_9 = 0x49,
    PE_10 = 0x4A,
    PE_11 = 0x4B,
    PE_12 = 0x4C,
    PE_13 = 0x4D,
    PE_14 = 0x4E,
    PE_15 = 0x4F,

    PF_0 = 0x50,
    PF_1 = 0x51,
    PF_2 = 0x52,
    PF_3 = 0x53,
    PF_4 = 0x54,
    PF_5 = 0x55,
    PF_6 = 0x56,
    PF_7 = 0x57,
    PF_8 = 0x58,
    PF_9 = 0x59,
    PF_10 = 0x5A,
    PF_11 = 0x5B,
    PF_12 = 0x5C,
    PF_13 = 0x5D,
    PF_14 = 0x5E,
    PF_15 = 0x5F,

    PG_0 = 0x60,
    PG_1 = 0x61,
    PG_2 = 0x62,
    PG_3 = 0x63,
    PG_4 = 0x64,
    PG_5 = 0x65,
    PG_6 = 0x66,
    PG_7 = 0x67,
    PG_8 = 0x68,
    PG_9 = 0x69,
    PG_10 = 0x6A,
    PG_11 = 0x6B,
    PG_12 = 0x6C,
    PG_13 = 0x6D,
    PG_14 = 0x6E,
    PG_15 = 0x6F,

    PH_0 = 0x70,
    PH_1 = 0x71,

    // ADC internal channels
    ADC_TEMP = 0xF0,
    ADC_VREF = 0xF1,
    ADC_VBAT = 0xF2,

    // GPIO 1
    D0 = PE_0,
    D1 = PE_1,
    D2 = PE_2,
    D3 = PE_3,
    D4 = PE_4,
    D5 = PE_5,
    D6 = PE_6,
    D7 = PE_7,
    D8 = PE_8,
    D9 = PE_9,
    D10 = PE_10,
    D11 = PE_11,
    D12 = PE_12,
    D13 = PE_13,
    D14 = PE_14,
    D15 = PE_15,

    // GPIO 2
    D16 = PF_0,
    D17 = PF_1,
    D18 = PF_2,
    D19 = PF_3,
    D20 = PF_4,  // A6
    D21 = PF_5,  // A7
    D22 = PF_6,  // A8
    D23 = PF_7,  // A9
    D24 = PF_8,  // A10
    D25 = PF_9,  // A11
    D26 = PF_10,
    D27 = PF_11,
    D28 = PF_12,
    D29 = PF_13,
    D30 = PF_14,
    D31 = PF_15,

    // ADC
    A0 = PA_3,
    A1 = PB_0,
    A2 = PB_1,
    A3 = PC_0,
    A4 = PC_2,
    A5 = PC_3,
    // ADC on GPIO
    A2_ALT = D19,
    A6 = D20,
    A7 = D21,
    A8 = D22,
    A9 = D23,
    A10 = D24,
    A11 = D25,
    A1_ALT = D26,

    // USART3
    USART1_TX = PD_8,
    USART1_RX = PD_9,
    USART_TX = USART1_TX,
    USART_RX = USART1_RX,
    // USART2
    USART2_TX = PD_5,
    USART2_RX = PD_6,
    // USART6
    USART3_TX = PC_6,
    USART3_RX = PC_7,

    // STDIO for console print
    STDIO_UART_TX = USART1_TX,
    STDIO_UART_RX = USART1_RX,
    //SERIAL_TX = STDIO_UART_TX,
    //SERIAL_RX = STDIO_UART_RX,
    USBTX = USART1_TX,
    USBRX = USART1_RX,

    // On board LED
    LED1 = PG_2,
    LED2 = PG_3,
    LED3 = PG_4,
    LED4 = PG_5,

    // I2C1
    I2C1_SCL = PB_8,
    I2C1_SDA = PB_9,
    I2C_SCL = I2C1_SCL,
    I2C_SDA = I2C1_SDA,
    // I2C2
    I2C2_SCL = PB_10,
    I2C2_SDA = PB_11,
    I2C2_SCL_ALT = D16,
    I2C2_SDA_ALT = D17,

    // SPI1
    SPI1_SCK = PA_5,
    SPI1_MISO = PA_6,
    SPI1_MOSI = PB_5,
    SPI1_CS = PD_14,
    SPI_SCK = SPI1_SCK,
    SPI_MISO = SPI1_MISO,
    SPI_MOSI = SPI1_MOSI,
    SPI_CS = SPI1_CS,
    // SPI4
    SPI2_SCK = D12,
    SPI2_SCK_ALT = D2,
    SPI2_MISO = D13,
    SPI2_MISO_ALT = D5,
    SPI2_MOSI = D14,
    SPI2_MOSI_ALT = D6,
    SPI2_CS = D15,
    // SPI5
    SPI3_SCK = D23, // A4
    SPI3_MISO = D24,    // A5
    SPI3_MOSI = D25,    // A6
    SPI3_CS = D28,

    // CAN1
    CAN1_RX = PD_0,
    CAN1_TX = PD_1,
    CAN_RX = CAN1_RX,
    CAN_TX = CAN1_TX,
    // CAN2
    CAN2_RX = PB_12,
    CAN2_TX = PB_13,

    // PWM
    PWM_OUT1 = D9,
    PWM_OUT2 = D11,
    PWM_OUT3 = D13, // SPI2_MISO, use SPI2_MISO_ALT instead
    PWM_OUT4 = D14, // SPI2_MOSI, use SPI2_MOSI_ALT instead

    /**** USB FS pins ****/
    USB_OTG_FS_DM = PA_11,
    USB_OTG_FS_DP = PA_12,
    USB_OTG_FS_ID = PA_10,
    USB_OTG_FS_VBUS = PA_9,

    /**** USB HS not available ****/

    /**** ETHERNET pins ****/
    ETH_REF_CLK = PA_1,
    ETH_MDIO = PA_2,
    ETH_MDC = PC_1,
    ETH_CRS_DV = PA_7,
    ETH_RXD0 = PC_4,
    ETH_RXD1 = PC_5,
    ETH_RXER = PG_2,
    ETH_TX_EN = PG_11,
    ETH_TXD0 = PG_13,
    ETH_TXD1 = PG_14,

    /**** OSCILLATOR pins ****/
    RCC_OSC32_IN = PC_14,
    RCC_OSC32_OUT = PC_15,
    RCC_OSC_IN = PH_0,
    RCC_OSC_OUT = PH_1,

    // Not connected
    NC = (int)0xFFFFFFFF
} PinName;

#ifdef __cplusplus
}
#endif

#endif
