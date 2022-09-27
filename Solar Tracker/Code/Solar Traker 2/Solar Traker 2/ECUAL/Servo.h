/*
 * Servo.h
 *
 * Created: 7/30/2019 6:32:53 AM
 *  Author: shaher
 */ 


#ifndef SERVO_H_
#define SERVO_H_
   #include "Timer1.h"
   
   
   #define Position_0  (300)
   #define postion_180 (1050)
   
   
   void Servo_PWM_1(float32 DutyCycle);
   void Servo_PWM_2(float32 DutyCycle);

#endif /* SERVO_H_ */