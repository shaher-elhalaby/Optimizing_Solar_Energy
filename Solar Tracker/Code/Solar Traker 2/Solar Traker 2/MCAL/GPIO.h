/*
 * GPIO.h
 *
 * Created: 5/28/2020 11:15:10 PM
 *  Author: shaher
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "Atmega32.h"


   
/*define pins from 0 to all*/     
#define GPIO_PIN0		((uint8_t)0x01)
#define GPIO_PIN1		((uint8_t)0x02)
#define GPIO_PIN2		((uint8_t)0x04)
#define GPIO_PIN3		((uint8_t)0x08)
#define GPIO_PIN4		((uint8_t)0x10)
#define GPIO_PIN5		((uint8_t)0x20)
#define GPIO_PIN6		((uint8_t)0x40)
#define GPIO_PIN7		((uint8_t)0x80) 
#define GPIO_ALLPINS	((uint8_t)0xFF) 
	  
/*define Mode */
#define OUTPUT		(0x00)
#define INPUTFLOAT	(0x01)
#define INPUTPULLUP	(0x02)        	
			
/*create Data Type for Initiating GPIO*/
typedef struct {
	uint8_t mode;
	uint8_t pin;
}GPIO_initTypedef;
				

void GPIO_pinInit( GPIO * G ,GPIO_initTypedef *GPIO_initStruct);
void GPIO_pinWrite( GPIO * G , uint8_t pin ,  functionalState state);
functionalState GPIO_pinRead( GPIO * G ,uint8_t pin);

void GPIO_ITinit(uint8_t it,uint8_t mode,callBackFunction func);
void GPIO_ITdeInit(uint8_t it);

uint8_t getITstatus(uint8_t it);
void clearITflag(uint8_t it);
/*
void IT0_callBack(callBackFunction func,void *data);
void IT1_callBack(callBackFunction func,void *data);
void IT2_callBack(callBackFunction func,void *data);
*/
#endif /* GPIO_H_ */