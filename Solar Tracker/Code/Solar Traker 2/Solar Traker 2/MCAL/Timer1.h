/*
 * Timer1.h
 *
 * Created: 8/13/2019 8:25:30 AM
 *  Author: shaher
 *THis file to Config. Timer 1.
 *Timer1 is 16 bit Timer.
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

      #include "MACROSH.h"
	  #include "StandardTypes.h"
	  #include "MC_Config.h"
	  
	  
	  
	  #define TCCR1A      (*(vuint8*)0x4F)
	  #define TCCR1B      (*(vuint8*)0x4E)
	  
	  #define TCNT1H      (*(vuint8*)0x4D)
	  #define TCNT1L      (*(vuint8*)0x4C)
	  #define OCR1AH      (*(vuint8*)0x4B)
	  #define OCR1AL      (*(vuint8*)0x4A)
	  #define OCR1BH      (*(vuint8*)0x49)
	  #define OCR1BL      (*(vuint8*)0x48)
	  #define ICR1H       (*(vuint8*)0x47)
	  #define ICR1L       (*(vuint8*)0x46)
	  
	  #define TIFR        (*(vuint8*)0x58)
	  #define TIMSK       (*(vuint8*)0x59)
	  
	  #define TCNT1       (*(vuint16*)0x4C)
	  #define OCR1A       (*(vuint16*)0x4A)
	  #define OCR1B       (*(vuint16*)0x48)
	  #define ICR1        (*(vuint16*)0x46)
	  
	  



             /*Timer/Counter Interrupt Flag Register  (TIFR)*/
             #define TOV1         (2)    /*Timer/Counter1 Overflow Flag*/
             #define OCF1A        (4)    /*Output Compare Flag 1 A*/
			 #define OCF1B        (3)    /*Output Compare Flag 1 B*/
			 #define ICF1         (5)
             
             
             /*Timer/Counter Interrupt Mask Register  (TIMSK)*/
			 #define TICIE1       (0)    /*Timer/Counter1 Input Capture Interrupt Enable*/
             #define OCIE1A       (0)    /*Timer/Counter1A Output Compare Match Interrupt Enable*/
			 #define OCIE1B       (1)    /*Timer/Counter1B Output Compare Match Interrupt Enable*/
             #define TOIE1        (0)    /*Timer/Counter1 Overflow Interrupt Enable*/

             /*Timer/Counter Control Register (TCCR1A)*/
             #define FOC1A        (0)    /*Force Output Compare (non-PWM mode)*/
             #define FOC1B        (0)    /*Force Output Compare (non-PWM mode)*/
			 
			 /*Timer/Counter1 Control Register B (TCCR1B) ICR*/
			 #define ICNC1        (0)    /*Input Capture Noise Canceler*/
			 #define ICES1        (1)    /*Input Capture Edge Select 0 a falling (negative) edge ,1 a rising (positive) edge*/

         /****************************************************/


       /*PreScalar Setting  in TCCR1B*/
       typedef enum{
	       
	       No_CLK_No_Timer,       /*No clock source (Timer/Counter stopped)*/
	       F_CPU_,                
	       F_CPU_8,               
	       F_CPU_64,
	       F_CPU_256,
	       F_CPU_1024,
	       EX_CLK_Rising_Edge,    /*T1 Pin*/
	       EX_CLK_Falling_Edge,   /*T1 Pin*/
	       
       }Timer_Prescaler;
	   
	   /************************************************************/
	   
	   /*COM 1A1:1A0 IN TCCR1A*/
	   typedef enum{
		   
		   /*----------OC1A---------------*/
		   
		   Noraml_NO_OC1A=0x00,                      /*Normal port operation, OC1 disconnected*/
		   
		   NO_PWM_Toggle_OC1A=0x40,                   /*Toggle OC1 on compare match*/
		   NO_PWM_Clear_OC1A=0x80,                    /*Clear OC1 on compare match*/
		   NO_PWM_Set_OC1A=0xC0,                      /*Set OC1 on compare match*/
		   
		   Fast_PWM_Non_Inverting_OC1A=0x80,              /*Clear OC1 on compare match, set OC1 at BOTTOM*/
		   Fast_PWM_Inverting_OC1A=0xC0,                  /*Set OC1 on compare match, clear OC1 at BOTTOM*/
		   
		   Phase_Correct_PWM_Non_Inverting_OC1A=0x80,     /*Clear OC1 on compare match when up-counting. Set OC1 on compare match when down counting*/
		   Phase_Correct_PWM_Inverting_OC1A=0xC0,         /*Set OC1 on compare match when up-counting. Clear OC1 on compare match when down counting*/
		   
		   
	   }T1_Compare_OC1A_Mode;
	   
	   
	   /*COM 1B1:1B0 IN TCCR1A*/
	   typedef enum{
	   /*----------OC1B---------------*/
	   
	   Noraml_NO_OC1B=0x00,                      /*Normal port operation, OC1 disconnected*/
	   
	   NO_PWM_Toggle_OC1B=0x10,                   /*Toggle OC1 on compare match*/
	   NO_PWM_Clear_OC1B=0x20,                    /*Clear OC1 on compare match*/
	   NO_PWM_Set_OC1B=0x30,                      /*Set OC1 on compare match*/
	   
	   Fast_PWM_Non_Inverting_OC1B=0x20,              /*Clear OC1 on compare match, set OC1 at BOTTOM*/
	   Fast_PWM_Inverting_OC1B=0x30,                  /*Set OC1 on compare match, clear OC1 at BOTTOM*/
	   
	   Phase_Correct_PWM_Non_Inverting_OC1B=0x20,     /*Clear OC1 on compare match when up-counting. Set OC1 on compare match when down counting*/
	   Phase_Correct_PWM_Inverting_OC1B=0x30,         /*Set OC1 on compare match when up-counting. Clear OC1 on compare match when down counting*/
	   
	   }T1_Compare_OC1B_Mode;
	   
	   typedef enum{
		   Normal=0x00,
		   Phase_Correct_PWM_8Bit=0x01,
		   Phase_Correct_PWM_9Bit=0x02,
		   Phase_Correct_PWM_10Bit=0x03,
		   CTC_OCR1A=0x04,
		   Fast_PWM_8Bit=0x05,
		   Fast_PWM_9Bit=0x06,
		   Fast_PWM_10Bit=0x07,
		   Phase_Freq_Correct_PWM_ICR1=0x08,
		   Phase_Freq_Correct_PWM_OCR1A=0x09,
		   Phase_Correct_PWM_ICR1=0x0A,
		   Phase_Correct_PWM_OCR1A=0x0B,
		   CTC_ICR1=0x0C,
		   
		   Fast_PWM_ICR1=0x0E,
		   Fast_PWM_OCR1A=0x0F,
		   }Timer1_Mode;
	  
	   
	   
	   void Timer1_Init( Timer1_Mode T1_Mode ,T1_Compare_OC1A_Mode  CMP_OC1A_Mode , T1_Compare_OC1B_Mode CMP_OC1B_Mode ,  Timer_Prescaler CLK );
	   void T1_WaveGeneration_CTC_OC1A( Timer1_Mode T1_Mode , float32 Max ,float64 F_Timer ,float32 F_OutSignal );
	   void T1_PWM_OC1A( float32 Duty , float32 Max , Timer1_Mode T1_Mode ,T1_Compare_OC1A_Mode  CMP_OC1A_Mode );
	   void T1_PWM_OC1B( float32 Duty , float32 Max , Timer1_Mode T1_Mode ,T1_Compare_OC1B_Mode  CMP_OC1B_Mode );
	   
	   
#endif /* TIMER1_H_ */