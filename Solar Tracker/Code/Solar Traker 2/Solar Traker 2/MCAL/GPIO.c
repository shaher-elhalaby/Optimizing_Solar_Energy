/*
 * GPIO.c
 *
 * Created: 5/28/2020 11:15:25 PM
 *  Author: shaher
 */ 

#include "GPIO.h"

/*
typedef struct{
	callBackFunction func;
	void *Data;
	}interruptTypedef;
	
interruptTypedef IT0CallBack;
interruptTypedef IT1CallBack;
interruptTypedef IT2CallBack;
*/
callBackFunction IT0CallBackFunc;
callBackFunction IT1CallBackFunc;
callBackFunction IT2CallBackFunc;

void GPIO_pinInit( GPIO * G ,GPIO_initTypedef *GPIO_initStruct)
{
	switch(GPIO_initStruct->mode)
	{
		case OUTPUT:
			G->ddr  |=  (GPIO_initStruct->pin);
			break;
		case INPUTFLOAT:
			G->ddr  &= ~(GPIO_initStruct->pin);
			G->port &= ~(GPIO_initStruct->pin);
			break;
		case INPUTPULLUP:
			G->ddr  &= ~(GPIO_initStruct->pin);
			G->port |=  (GPIO_initStruct->pin);
			break;
	}
}
void GPIO_pinWrite( GPIO * G , uint8_t pin ,  functionalState state)
{
	switch (state)
	{
		case DISABLE:
			G->port &= ~(pin); 
			break;
		case ENABLE:
			G->port |=  (pin);
			break;
	}	
}
functionalState GPIO_pinRead( GPIO * G , uint8_t pin)
{
	return ((G->pin & pin) == pin) ;
}


void GPIO_ITinit(uint8_t it,uint8_t mode,callBackFunction func)
{
	switch (it)
	{
		case IT0:
			_INT_->mcucr |= mode;
			IT0CallBackFunc = func;
			break;
		case IT1:
			_INT_->mcucr |= mode;
			IT1CallBackFunc = func;
			break;
		case IT2:
			_INT_->mcucsr |= mode;
			IT2CallBackFunc = func;
			break;
		default:
			return;
			
	}
_INT_->gicr |=it;	
}
void GPIO_ITdeInit(uint8_t it)
{
	_INT_->gicr &=(~(it));
}

uint8_t getITstatus(uint8_t it)
{
	return (_INT_->gifr & it)==it;
}
void clearITflag(uint8_t it)
{
	_INT_->gifr |= it;
}


ISR(INT0_vect)
{
	IT0CallBackFunc();
}

ISR(INT1_vect)
{
	IT1CallBackFunc();
}

ISR(INT2_vect)
{
	IT2CallBackFunc();
}















/*
void IT0_callBack(callBackFunction func,void *data)
{
	IT0CallBack.func = func;
	IT0CallBack.Data = data;
}
void IT1_callBack(callBackFunction func,void *data)
{
	IT1CallBack.func = func;
	IT1CallBack.Data = data;
}
void IT2_callBack(callBackFunction func,void *data)
{
	IT2CallBack.func = func;
	IT2CallBack.Data = data;
}

ISR(INT0_vect)
{
	IT0CallBack.func(IT0CallBack.Data);
}

ISR(INT1_vect)
{
	IT1CallBack.func(IT1CallBack.Data);
}

ISR(INT2_vect)
{
	IT2CallBack.func(IT2CallBack.Data);
}*/