/*
 * ADC.c
 *
 * Created: 7/9/2019 9:27:20 PM
 *  Author: shaher
 */ 
#include "ADC.h"
void ADC_Init(void)
{
	ADMUX|=(1<<6); /*AVCC AS Ref*/
	ADCSREG|=(1<<ADEN); /*pre 2*/
}
uint16 analog_Read(Channel_Sel Channel)
{
	uint16 Data=0;
	ADMUX &=0xE0;
	/*start conv*/
	ADMUX |=Channel;
	ADCSREG|=(1<<ADSC);
	while ((ADCSREG & 0x10)==0){};
	Data=ADCL;
	Data|=(ADCH<<8);
	/* ADIF must be Cleared*/
	ADCSREG|=0x10;
	return Data;
}
