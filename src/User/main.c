#include "debug.h"
#include "game500.h"
int main(void)
{

    my_rcc_init();
    Delay_Init();
    gpio_init();
    Delay_Ms(1);
    flash_init1();
    GPIO_SetBits(GPIOC, LED_R);
    GPIO_SetBits(GPIOA, LED_G);
    GPIO_SetBits(GPIOA, LED_B);

// ENTER MODE1
MODE1:
    MODE2_FLAG = 0;
    while(MODE2_FLAG != 2)
    {
        if(GPIO_ReadInputDataBit(GPIOA, PLAY) == Bit_RESET) play_loader();
        PU_addr=0;
        PU_addr_in = ((uint16_t)GPIOB->INDR);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR0) >> 9);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR1) >> 7);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR2) >> 5);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR3) >> 3);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR4) >> 1);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR5) << 1);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR6) >> 4);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR7) >> 4);
        if(PU_addr == 0xaa)
        {
            MODE2_FLAG = 1;
        }
        else if(PU_addr == 0x55)
        {
            if(MODE2_FLAG == 1)
            {
                MODE2_FLAG = 2;
            }
            else
            {
                MODE2_FLAG = 0;
            }
        }
        else
        {
            MODE2_FLAG = 0;
        }
        PU_data = ROM_menu[PU_addr];
        PU_data_out=0;
        PU_data_out |= ((PU_data & 0x01) << 3);
        PU_data_out |= ((PU_data & 0x02) << 4);
        PU_data_out |= ((PU_data & 0x04) << 2);
        PU_data_out |= ((PU_data & 0x08) << 3);
        PU_data_out |= ((PU_data & 0x10) << 3);
        PU_data_out |= ((PU_data & 0x20) << 3);
        PU_data_out |= ((PU_data & 0x40) << 5);
        PU_data_out |= ((PU_data & 0x80) << 5);
        PU_data_out |= LED_B;
        GPIOA->OUTDR = (uint32_t)PU_data_out;
    }
    GPIO_SetBits(GPIOC, LED_R);
    GPIO_SetBits(GPIOA, LED_G);
    GPIO_ResetBits(GPIOA, LED_B);

// MODE2
    MODE1_FLAG = 0;
    byte_addr = 0;
    while((((uint16_t)GPIOB->INDR) & ADDR12) == 0) // wait clock
    {
    }
    while((((uint16_t)GPIOB->INDR) & ADDR12) !=0 )
    {
    }
    PU_addr=0; // read H byte
    PU_addr_in = ((uint16_t)GPIOB->INDR);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR0) >> 9);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR1) >> 7);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR2) >> 5);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR3) >> 3);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR4) >> 1);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR5) << 1);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR6) >> 4);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR7) >> 4);
    file_addrH = PU_addr;
    while((((uint16_t)GPIOB->INDR) & ADDR12) == 0) // wait clock
    {
    }
    while((((uint16_t)GPIOB->INDR) & ADDR12) !=0 )
    {
    }
    PU_addr=0; // read L byte
    PU_addr_in = ((uint16_t)GPIOB->INDR);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR0) >> 9);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR1) >> 7);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR2) >> 5);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR3) >> 3);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR4) >> 1);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR5) << 1);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR6) >> 4);
    PU_addr |= (uint8_t)((PU_addr_in & ADDR7) >> 4);
    file_addrL = PU_addr;
    file_addr = file_addrH * 0x100 + file_addrL;
    while(byte_addr != 0xe000)
    {
        while((((uint16_t)GPIOB->INDR) & ADDR12) == 0) // wait clock
        {
        }
        while((((uint16_t)GPIOB->INDR) & ADDR12) !=0 )
        {
        }
        PU_addr=0;
        PU_addr_in = ((uint16_t)GPIOB->INDR);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR0) >> 9);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR1) >> 7);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR2) >> 5);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR3) >> 3);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR4) >> 1);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR5) << 1);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR6) >> 4);
        PU_addr |= (uint8_t)((PU_addr_in & ADDR7) >> 4);
        file_byte = read_flash(file_addr, byte_addr);
        write_PU2(file_byte);
        if(PU_addr == 0x81)
        {
            MODE1_FLAG = 1;
        }
        else if((PU_addr == 0x66) && (MODE1_FLAG == 1))
        {
            MODE1_FLAG = 2;
        }
        else
        {
            MODE1_FLAG = 0;
        }
        byte_addr = byte_addr+1;
        if(MODE1_FLAG == 2)
        {
            GPIO_ResetBits(GPIOA, LED_G);
            GPIO_SetBits(GPIOA, LED_B);
            goto MODE1;
        }
    }
    while(1) // what's going wrong
    {
        GPIO_ResetBits(GPIOC, LED_R);
        GPIO_SetBits(GPIOA, LED_G);
        GPIO_SetBits(GPIOA, LED_B);
    }
}

//--------------------------------------------------------------------------- subroutines
void play_byte(uint8_t byte)
{
    uint8_t x;
    for(x=0; x<8; x++)
    {
        if((byte & 0x80) == 0)
        {
            GPIO_SetBits(GPIOB, AUDIO);
            Delay_Us(NW);
            GPIO_ResetBits(GPIOB, AUDIO);
            Delay_Us(NW);
        }
        else
        {
            GPIO_ResetBits(GPIOB, AUDIO);
            Delay_Us(NW);
            GPIO_SetBits(GPIOB, AUDIO);
            Delay_Us(NW);
        }
        byte = byte << 1;
    }
}

//----------------------------------------------------------------------
void play_loader(void)
{
    GPIO_SetBits(GPIOA, LED_G);
    GPIO_ResetBits(GPIOA, LED_B);
    uint8_t send_byte;
    uint16_t b;
    for(b=0;b<580;b++)
    {
        send_byte = loader1[b];
        play_byte(send_byte);
    }
    GPIO_SetBits(GPIOA, LED_G);
    GPIO_ResetBits(GPIOA, LED_B);
}

//----------------------------------------------------------------------
void flash_init1(void)
{
    int i;
    uint8_t tx_data8;
    GPIO_ResetBits(GPIOB, SPI_DI);
    GPIO_ResetBits(GPIOB, SPI_CLK);
    GPIO_SetBits(GPIOB, SPI_CS);
    Delay_Ms(1);
// send ENABLE RESET command
        i=8;
        tx_data8=0x66;
        GPIO_ResetBits(GPIOB, SPI_CS);
        while(i!=0)
        {
            if((tx_data8 & 0x80) != 0)
            {
                GPIO_SetBits(GPIOB, SPI_DI);
            }
            else
            {
                GPIO_ResetBits(GPIOB, SPI_DI);
            }
            tx_data8 = tx_data8 << 1;
            i=i-1;
            GPIO_SetBits(GPIOB, SPI_CLK);
            GPIO_ResetBits(GPIOB, SPI_CLK);
        }
        i=0;
        while(i<5)
        {
            i=i+1;
        }
        GPIO_SetBits(GPIOB, SPI_CS);
// send RESET command
        i=8;
        tx_data8=0x99;
        GPIO_ResetBits(GPIOB, SPI_CS);
        while(i!=0)
        {
            if((tx_data8 & 0x80) != 0)
            {
                GPIO_SetBits(GPIOB, SPI_DI);
            }
            else
            {
                GPIO_ResetBits(GPIOB, SPI_DI);
            }
            tx_data8 = tx_data8 << 1;
            i=i-1;
            GPIO_SetBits(GPIOB, SPI_CLK);
            GPIO_ResetBits(GPIOB, SPI_CLK);
        }
        GPIO_SetBits(GPIOB, SPI_CS);
        GPIO_ResetBits(GPIOB, SPI_DI);
        GPIO_ResetBits(GPIOB, SPI_CLK);
        Delay_Ms(1);
}

//------------------------------- read byte from flash
uint8_t read_flash(uint16_t f_addr, uint16_t b_addr) // f_addr - 扼技快投快扶我快 志 扼快忍技快扶找忘抒 (0x2000 忌忘抄找), b_addr - 扼技快投快扶我快 志 忌忘抄找忘抒
{
    int i;
    uint8_t tx_data8;
    uint32_t tx_data32=0;
    uint8_t rx_data;
    tx_data32 = 0x2000 * f_addr; // calculate flash address
    tx_data32 = tx_data32 + (uint32_t)b_addr; // calculate flash address
    GPIO_ResetBits(GPIOB, SPI_CS);
// send CMD
    i=8;
    tx_data8=0x03; // 0x03 - command to read 1 byte from flash
    while(i!=0)
    {
        if((tx_data8 & 0x80) != 0)
        {
            GPIO_SetBits(GPIOB, SPI_DI);
        }
        else
        {
            GPIO_ResetBits(GPIOB, SPI_DI);
        }
        tx_data8 = tx_data8 << 1;
        i=i-1;
        GPIO_SetBits(GPIOB, SPI_CLK);
        GPIO_ResetBits(GPIOB, SPI_CLK);
    }
// send ADDR
    i=24;
    tx_data32=tx_data32<<8;
    while(i!=0)
    {
        if((tx_data32 & 0x80000000) != 0)
        {
            GPIO_SetBits(GPIOB, SPI_DI);
        }
        else
        {
            GPIO_ResetBits(GPIOB, SPI_DI);
        }
        tx_data32 = tx_data32 << 1;
        i=i-1;
        GPIO_SetBits(GPIOB, SPI_CLK);
        GPIO_ResetBits(GPIOB, SPI_CLK);

    }
// read DATA
    i=8;
    rx_data=0;
    while(i!=0)
    {
        rx_data = rx_data << 1;
        if(GPIO_ReadInputDataBit(GPIOB, SPI_DO) != Bit_RESET)
        {
            rx_data = rx_data | 0x01;
        }
        i=i-1;
        GPIO_SetBits(GPIOB, SPI_CLK);
        GPIO_ResetBits(GPIOB, SPI_CLK);
    }
    GPIO_SetBits(GPIOB, SPI_CS);
    return rx_data;
}

//----------------------------------------------------------------------
void write_PU2(uint8_t write_data)
{
    uint16_t PU_data_out=0;
    PU_data_out |= ((write_data & 0x01) << 3);
    PU_data_out |= ((write_data & 0x02) << 4);
    PU_data_out |= ((write_data & 0x04) << 2);
    PU_data_out |= ((write_data & 0x08) << 3);
    PU_data_out |= ((write_data & 0x10) << 3);
    PU_data_out |= ((write_data & 0x20) << 3);
    PU_data_out |= ((write_data & 0x40) << 5);
    PU_data_out |= ((write_data & 0x80) << 5);
    PU_data_out |= LED_G;
    GPIOA->OUTDR = (uint32_t)PU_data_out;
    return;
}

//----------------------------------------------------------------------
void gpio_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure = {0};

    GPIO_InitStructure.GPIO_Pin = LED_R;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_G;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_B;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DATA0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DATA1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DATA2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DATA3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DATA4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DATA5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DATA6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DATA7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = ADDR0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = ADDR1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = ADDR2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = ADDR3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = ADDR4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = ADDR5;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = ADDR6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = ADDR7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = ADDR12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = SPI_CS;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = SPI_CLK;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = SPI_DI;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = SPI_DO;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = AUDIO;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = PLAY;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

//----------------------------------------------------------------------
void my_rcc_init(void)
{
    RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);                 // switch system clock to HSI
    RCC_PLLCmd(DISABLE);                                    // disable PLL
    RCC_HSICmd(ENABLE);                                     // turn on HSI
    Delay_Us(10);                                           // delay for stability
    RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_12);    // set HSI/2 as PLL source, PLL multiplication factor = 12
    RCC_PLLCmd(ENABLE);                                     // turn on PLL
    Delay_Us(10);                                           // delay for stability
    while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET){};   // wait for PLL ready
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);              // set PLL as SYSCLK source
}
