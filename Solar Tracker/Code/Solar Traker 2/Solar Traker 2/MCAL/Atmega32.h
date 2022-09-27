/*
 * Atmega32.h
 *
 * Created: 7/3/2022 9:14:05 PM
 *  Author: SHAHER
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/io.h>

/*****************************************gpio*******************************************/
/*Creating Data type for GPIO*/
typedef struct{
	volatile uint8_t pin;
	volatile uint8_t ddr;
	volatile uint8_t port;
}GPIO;

/*define GPIOs for atmega32*/
#define GPIOA  ((GPIO*)0x39)
#define GPIOB  ((GPIO*)0x36)
#define GPIOC  ((GPIO*)0x33)
#define GPIOD  ((GPIO*)0x30)
/**********************************GPIO Interrupt *****************************************/
/*Creating Data type for Interrupt */
typedef struct{
	volatile uint8_t mcucsr;
	volatile uint8_t mcucr;
	volatile uint8_t Reserved[4];
	volatile uint8_t gifr;
	volatile uint8_t gicr;
}intTypedef;
//define ex-Interrupt register for atmega32
#define _INT_ ((intTypedef*)0x54)

//GPIO Interrupt
#define IT0			0x40
#define IT1			0x80
#define IT2			0x20

//IT Mode
#define	LVL_INT0     0x00
#define	LowLVL_INT0  0x01
#define	Failing_INT0 0x02
#define	Raising_INT0 0x03
		
#define	LVL_INT1	 0x00
#define	LowLVL_INT1  0x04
#define	Failing_INT1 0x08
#define	Raising_INT1 0x0c
		
#define	Failing_INT2 0x00
#define	Raising_INT2 0x40

#define INT_ENABLE()   (SREG |=  (1<<7))
#define INT_DISABLE()  (SREG &= ~(1<<7))
/*********************************************EEPROM***************************************/
typedef struct {
	volatile uint8_t   eecr;
	volatile uint8_t   eedr;
	volatile uint16_t  eear;
}EEPROMTypedef;

#define EEPROM ((EEPROMTypedef*)0x3c)
#define EEPROM_IT_READY ((uint8_t)0x08)

#define EEPROM_EERE		(0x01)
#define EEPROM_EEWE		(0x02)
#define EEPROM_EEMWE	(0x04)

/************************************************ADC***************************************/
typedef struct {
	uint16_t adcdr;
	uint8_t adcsra;
	uint8_t adcmux;
	uint8_t Reserved[40];
	uint8_t sfior;
	}ADCtypedef	;

#define ADC1  ((ADCtypedef*)0x24)	

//define channel selector and gain
#define ADC_PA0    (0x00)
#define ADC_PA1    (0x01)
#define ADC_PA2    (0x02)
#define ADC_PA3    (0x03)
#define ADC_PA4    (0x04)
#define ADC_PA5    (0x05)
#define ADC_PA6    (0x06)
#define ADC_PA7    (0x07)
#define ADC_PA0X10 (0x08)
#define ADC_PA1X10 (0x09)
		//future adding Gain.
		
//define Triggering Mode
#define	freeRunning			(0x00)
#define analogComparator    (0x20)
#define EX_INT0				(0x40)
#define T0CompareMatch		(0x60)
#define T0OverFlow			(0x80)
#define T1CompareMatchB		(0xA0)
#define T1OverFlow			(0xC0)
#define T1CaptureEvent		(0xE0)

//define ADC Prescaler
#define ADCby2		(0x01)
#define ADCby4		(0x02)
#define ADCby8		(0x03)
#define ADCby16		(0x04)
#define ADCby32		(0x05)
#define ADCby64		(0x06)
#define ADCby128	(0x07)

//define ADC Reference voltage
#define AREF		(0x00)
#define AVCC		(0x40)
#define Internal	(0xC0)

/*************************************************Timer************************************/
typedef struct{
	volatile uint8_t tcnt;
	volatile uint8_t tccr;
	volatile uint8_t Resrved1[4];
	volatile uint8_t tifr;
	volatile uint8_t timsk;
	volatile uint8_t Resrved2[2];
	volatile uint8_t ocr;	
}timTypedef;

#define TIM0	((timTypedef*)0x52)

#define TIM_TOV		(0X01)  /*output compare flag*/
#define TIM_OCF		(0X02)	/*overflow flag*/

/*************************************************General**********************************/
//define MCU frequency
#define F_CPU (1000000UL)
#include <util/delay.h>


/*define data type for Function state*/
typedef enum{
	DISABLE= 0X00,
	ENABLE = !(DISABLE),
	}functionalState;
	
typedef void (*callBackFunction)(void); 	




#endif /* ATMEGA32_H_ */