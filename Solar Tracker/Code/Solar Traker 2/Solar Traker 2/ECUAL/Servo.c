/*
 * Servo.c
 *
 * Created: 7/30/2019 6:33:06 AM
 *  Author: shaher
 */ 

 #include "Servo.h"
 
 void Servo_PWM_1(float32 DutyCycle)
 {
	 OCR1A=(Position_0+((DutyCycle/180)*postion_180));
 }
 void Servo_PWM_2(float32 DutyCycle)
 {
	 OCR1B=(Position_0+((DutyCycle/180)*postion_180));
 }