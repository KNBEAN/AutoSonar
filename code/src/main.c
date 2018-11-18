#include <avr/io.h>
#include <util/delay.h>
#include <usound.h>
#include <uart.h>
// #include <

#ifndef F_CPU  
#define F_CPU 1000000UL  
#endif 

int main(void)
{
    DDRB = 0xFF;
    ICR1=20000;
	TCCR1A  = (0<<COM1A0)|(1<<COM1A1)|(0<<COM1B0)|(0<<COM1B1)|(0<<FOC1A)|(0<<FOC1B)|(1<<WGM11)|(0<<WGM10);
	TCCR1B =  (0<<ICNC1)|(0<<ICES1)|(1<<WGM13)|(1<<WGM12)|(0<<CS12)|(0<<CS11)|(1<<CS10);

    uint32_t distance;

    usound_init();
    UART_Init(4800);
    _delay_ms(500);
    while (1)
    {
        for(OCR1A = 800; OCR1A != 2200; OCR1A+=10){
            UART_Printf("%u; ", OCR1A);
            distance = readDistance();
            UART_TxNumber(C_DECIMAL_U8, distance, C_DefaultDigitsToTransmit_U8);
            UART_Printf("\n\r");
        }
        for(OCR1A = 2200; OCR1A != 800; OCR1A-=10){
            UART_Printf("%u\r\n", OCR1A);
            distance = readDistance();
            UART_TxNumber(C_DECIMAL_U8, distance, C_DefaultDigitsToTransmit_U8);
            UART_Printf("\n\r");
        }
    }

    return 0;
}
