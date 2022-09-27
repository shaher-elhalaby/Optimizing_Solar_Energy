/*
 * ADC.h
 *
 * Created: 7/9/2019 9:27:08 PM
 *  Author: shaher
 */ 



/* ADC for Simple using */


#ifndef ADC_H_
#define ADC_H_

#include "StandardTypes.h"
#include "MACROSH.h"
#include "MC_Config.h"

#define ADMUX       (*(vuint8*)0x27)
#define ADCSREG     (*(vuint8*)0x26)
#define ADCH        (*(vuint8*)0x25)
#define ADCL        (*(vuint8*)0x24)
#define SFIOR       (*(vuint8*)0x50)

#define ADIF  (4)
#define ADSC  (6)
#define ADEN  (7)

typedef enum {
	_PA0_=0x00,
	_PA1_,
	_PA2_,
	_PA3_,
	_PA4_,
	_PA5_,
	_PA6_,
	_PA7_,
	}Channel_Sel;

void ADC_Init(void);
uint16 analog_Read(Channel_Sel Channel);
	
#endif /* ADC_H_ */