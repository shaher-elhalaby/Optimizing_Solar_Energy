/*
 * Timer1.c
 *
 * Created: 8/13/2019 8:25:47 AM
 *  Author: shaher
 */ 

#include "Timer1.h"

void Timer1_Init( Timer1_Mode T1_Mode ,T1_Compare_OC1A_Mode  CMP_OC1A_Mode , T1_Compare_OC1B_Mode CMP_OC1B_Mode ,  Timer_Prescaler CLK )
{
	switch (T1_Mode)
	{
	  case Normal:
	       TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3);
	       TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(CLK);
	       TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
		   break;
		   
	 case Phase_Correct_PWM_8Bit:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3)|(1<<0);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		  
	 case Phase_Correct_PWM_9Bit:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3)|(1<<1);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		  	
	 case Phase_Correct_PWM_10Bit:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3)|(1<<1)|(1<<0);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		  	
	 case CTC_OCR1A:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(1<<3)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		  	
	 case Fast_PWM_8Bit:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3)|(1<<0);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(1<<3)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
	 case Fast_PWM_9Bit:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3)|(1<<1);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(1<<3)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		  
	 case Fast_PWM_10Bit:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3)|(1<<1)|(1<<0);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(1<<3)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		  	  	  	        	   
	 case Phase_Freq_Correct_PWM_ICR1:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(1<<4)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		  
	 case Phase_Freq_Correct_PWM_OCR1A:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3)|(1<<0);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(1<<4)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		  
	 case Phase_Correct_PWM_ICR1:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3)|(1<<1);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(1<<4)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		  	
     case Phase_Correct_PWM_OCR1A:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3)|(1<<1)|(1<<0);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(1<<4)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		    
	 case CTC_ICR1:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(1<<4)|(1<<3)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		  
	 case Fast_PWM_ICR1:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3)|(1<<1);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(1<<4)|(1<<3)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
		  
	 case Fast_PWM_OCR1A:
	      TCCR1A|= (CMP_OC1A_Mode) | (CMP_OC1B_Mode) | (FOC1B<<2) | (FOC1A<<3)|(1<<1)|(1<<0);
	      TCCR1B|=(ICNC1<<7)|(ICES1<<6)|(1<<4)|(1<<3)|(CLK);
	      TIMSK |=(TICIE1<<5)|(OCIE1A<<4)|(OCIE1B<<3)|(TOIE1<<2);
	      break;
	 default:
	      return;	  	  
	}
}



void T1_WaveGeneration_CTC_OC1A( Timer1_Mode T1_Mode , float32 Max ,float64 F_Timer ,float32 F_OutSignal )
{
	switch (T1_Mode)
	{
		case CTC_OCR1A:
		     OCR1A =(uint16)(Max);
             OCR1A = ((F_Timer/(2*F_OutSignal))-1) ;
			 break;
		case CTC_ICR1:
		     ICR1 =(uint16)(Max);
			 OCR1A = ((F_Timer/(2*F_OutSignal))-1) ;
			  break;
		default:
		      return;	  
	}
}

 
void T1_PWM_OC1A( float32 Duty , float32 Max , Timer1_Mode T1_Mode ,T1_Compare_OC1A_Mode  CMP_OC1A_Mode )
{
	switch (T1_Mode)
	{
		
		case Phase_Correct_PWM_8Bit:
		       switch (CMP_OC1A_Mode)
		       {
			       case Phase_Correct_PWM_Non_Inverting_OC1A :
			            OCR1A = (uint16)((Duty/100)*2*(0x00FF)) + 0.5 ;
			            break;
			       case Phase_Correct_PWM_Inverting_OC1A :
			            OCR1A = (uint16)(((100 - Duty)/100)*2*(0x00FF)) + 0.5 ;
			            break;
			       default:
			            return;
		       }
		     break;
			 
		case Phase_Correct_PWM_9Bit:
		      switch (CMP_OC1A_Mode)
		      {
			      case Phase_Correct_PWM_Non_Inverting_OC1A :
			           OCR1A = (uint16)((Duty/100)*2*(0x01FF)) + 0.5 ;
			           break;
			      case Phase_Correct_PWM_Inverting_OC1A :
			           OCR1A = (uint16)(((100 - Duty)/100)*2*(0x01FF)) + 0.5 ;
			           break;
			      default:
			           return;
		      }
		     break;
			 
		case Phase_Correct_PWM_10Bit:
		      switch (CMP_OC1A_Mode)
		      {
			      case Phase_Correct_PWM_Non_Inverting_OC1A :
			           OCR1A = (uint16)((Duty/100)*2*(0x03FF)) + 0.5 ;
			           break;
			      case Phase_Correct_PWM_Inverting_OC1A :
			           OCR1A = (uint16)(((100 - Duty)/100)*2*(0x03FF)) + 0.5 ;
			           break;
			      default:
			           return;
		      }
		     break;
		
		case Fast_PWM_8Bit:
		      switch (CMP_OC1A_Mode)
		      {
			      case Fast_PWM_Non_Inverting_OC1A :
			           OCR1A = (uint16)((Duty/100)*(0x00FF)) + 0.5 ;
			           break;
			      case Fast_PWM_Inverting_OC1A :
			           OCR1A = (uint16)(((100 - Duty)/100)*(0x00FF)) + 0.5 ;
			           break;
			      default:
			           return;
		      }
		     break;
			 
		case Fast_PWM_9Bit:
		      switch (CMP_OC1A_Mode)
		      {
			      case Fast_PWM_Non_Inverting_OC1A :
			           OCR1A = (uint16)((Duty/100)*(0x01FF)) + 0.5 ;
			           break;
			      case Fast_PWM_Inverting_OC1A :
			           OCR1A = (uint16)(((100 - Duty)/100)*(0x01FF)) + 0.5 ;
			           break;
			      default:
			           return;
		      }
		     break;
			 
		case Fast_PWM_10Bit:
		      switch (CMP_OC1A_Mode)
		      {
			      case Fast_PWM_Non_Inverting_OC1A :
			           OCR1A = (uint16)((Duty/100)*(0x03FF)) + 0.5 ;
			           break;
			      case Fast_PWM_Inverting_OC1A :
			           OCR1A = (uint16)(((100 - Duty)/100)*(0x03FF)) + 0.5 ;
			           break;
			      default:
			           return;
		      }
		     break;
			 
		case Phase_Freq_Correct_PWM_ICR1:
		      ICR1 =(uint16)(Max);
		      switch (CMP_OC1A_Mode)
		      {
			      case Phase_Correct_PWM_Non_Inverting_OC1A :
			           OCR1A = (uint16)(((Duty/100)*2*(Max)) + 0.5) ;
			           break;
			      case Phase_Correct_PWM_Inverting_OC1A :
			           OCR1A = (uint16)(((100 - Duty)/100)*2*(Max)) + 0.5 ;
			           break;
			      default:
			           return;
		      }
		     break;
			 
		case Phase_Freq_Correct_PWM_OCR1A:
		    OCR1A =(uint16)(Max);
		    switch (CMP_OC1A_Mode)
		    {
			    case Phase_Correct_PWM_Non_Inverting_OC1A :
			         OCR1A = (uint16)(((Duty/100)*2*(Max)) + 0.5) ;
			         break;
			    case Phase_Correct_PWM_Inverting_OC1A :
			         OCR1A = (uint16)(((100 - Duty)/100)*2*(Max)) + 0.5 ;
			         break;
			    default:
			         return;
		    }
		     break;
			 
		case Phase_Correct_PWM_ICR1:
		     ICR1 =(uint16)(Max);
		     switch (CMP_OC1A_Mode)
		     {
			     case Phase_Correct_PWM_Non_Inverting_OC1A :
			          OCR1A = (uint16)(((Duty/100)*2*(Max)) + 0.5) ;
			          break;
			     case Phase_Correct_PWM_Inverting_OC1A :
			          OCR1A = (uint16)(((100 - Duty)/100)*2*(Max)) + 0.5 ;
			          break;
			     default:
			          return;
		     }
		     break;
			 
		case Phase_Correct_PWM_OCR1A:
		      OCR1A =(uint16)(Max);
		      switch (CMP_OC1A_Mode)
		      {
			      case Phase_Correct_PWM_Non_Inverting_OC1A :
			           OCR1A = (uint16)(((Duty/100)*2*(Max)) + 0.5) ;
			           break;
			      case Phase_Correct_PWM_Inverting_OC1A :
			           OCR1A = (uint16)(((100 - Duty)/100)*2*(Max)) + 0.5 ;
			           break;
			      default:
			           return;
		      }
	         break;
			 
		case Fast_PWM_ICR1:
		   ICR1 =(uint16)(Max);
		      switch (CMP_OC1A_Mode)
		      {
			      case Fast_PWM_Non_Inverting_OC1A :
			           OCR1A = (uint16)(((Duty/100)*(Max)) + 0.5) ;
			           break;
			      case Fast_PWM_Inverting_OC1A :
			           OCR1A = (uint16)(((100 - Duty)/100)*(Max)) + 0.5 ;
			           break;
			      default:
			           return;
		      }
		     break;
			 
		case Fast_PWM_OCR1A:
		    OCR1A =(uint16)(Max);
		      switch (CMP_OC1A_Mode)
		      {
			      case Fast_PWM_Non_Inverting_OC1A :
			           OCR1A = (uint16)((Duty/100)*(Max)) + 0.5 ;
			           break;
			      case Fast_PWM_Inverting_OC1A :
			           OCR1A = (uint16)(((100 - Duty)/100)*(Max)) + 0.5 ;
			           break;
			      default:
			           return;
		      }
		     break;
		default:
		     return;	 
	}
}
void T1_PWM_OC1B( float32 Duty , float32 Max , Timer1_Mode T1_Mode ,T1_Compare_OC1B_Mode  CMP_OC1B_Mode )
{
	switch (T1_Mode)
	{
		
		case Phase_Correct_PWM_8Bit:
		     switch (CMP_OC1B_Mode)
		     {
			    case Phase_Correct_PWM_Non_Inverting_OC1B :
			         OCR1B = (uint16)((Duty/100)*2*(0x00FF)) + 0.5 ;
			         break;
			    case Phase_Correct_PWM_Inverting_OC1B :
			         OCR1B = (uint16)(((100 - Duty)/100)*2*(0x00FF)) + 0.5 ;
			         break;
			    default:
			         return;
		     }
		     break;
		
		  case Phase_Correct_PWM_9Bit:
		     switch (CMP_OC1B_Mode)
		        {
			     case Phase_Correct_PWM_Non_Inverting_OC1B :
			          OCR1B = (uint16)((Duty/100)*2*(0x01FF)) + 0.5 ;
			          break;
			     case Phase_Correct_PWM_Inverting_OC1B :
			          OCR1B = (uint16)(((100 - Duty)/100)*2*(0x01FF)) + 0.5 ;
			          break;
			     default:
			          return;
		       }
		      break;
		
		  case Phase_Correct_PWM_10Bit:
		     switch (CMP_OC1B_Mode)
		      {
			     case Phase_Correct_PWM_Non_Inverting_OC1B :
			          OCR1B = (uint16)((Duty/100)*2*(0x03FF)) + 0.5 ;
			          break;
			     case Phase_Correct_PWM_Inverting_OC1B :
			          OCR1B = (uint16)(((100 - Duty)/100)*2*(0x03FF)) + 0.5 ;
			          break;
			    default:
			          return;
		       }
		      break;
		
		  case Fast_PWM_8Bit:
		     switch (CMP_OC1B_Mode)
		      {
			     case Fast_PWM_Non_Inverting_OC1B :
			          OCR1B = (uint16)((Duty/100)*(0x00FF)) + 0.5 ;
			          break;
			     case Fast_PWM_Inverting_OC1B :
			          OCR1B = (uint16)(((100 - Duty)/100)*(0x00FF)) + 0.5 ;
			          break;
			     default:
			          return;
		       }
		      break;
		
		  case Fast_PWM_9Bit:
		     switch (CMP_OC1B_Mode)
		      {
			     case Fast_PWM_Non_Inverting_OC1B :
			          OCR1B = (uint16)((Duty/100)*(0x01FF)) + 0.5 ;
			          break;
			     case Fast_PWM_Inverting_OC1B :
			          OCR1B = (uint16)(((100 - Duty)/100)*(0x01FF)) + 0.5 ;
			          break;
			     default:
			          return;
		    }
		   break;
		
		  case Fast_PWM_10Bit:
		    switch (CMP_OC1B_Mode)
		     {
		    	case Fast_PWM_Non_Inverting_OC1B :
		           	 OCR1B = (uint16)((Duty/100)*(0x03FF)) + 0.5 ;
			         break;
			    case Fast_PWM_Inverting_OC1B :
			         OCR1B = (uint16)(((100 - Duty)/100)*(0x03FF)) + 0.5 ;
			         break;
			    default:
			         return;
		     }
		    break;
		
		  case Phase_Freq_Correct_PWM_ICR1:
		      ICR1 =(uint16)(Max);
		      switch (CMP_OC1B_Mode)
		       {
			      case Phase_Correct_PWM_Non_Inverting_OC1B :
			           OCR1B = (uint16)(((Duty/100)*2*(Max)) + 0.5) ;
			           break;
			      case Phase_Correct_PWM_Inverting_OC1B :
			           OCR1B = (uint16)(((100 - Duty)/100)*2*(Max)) + 0.5 ;
			           break;
			      default:
			           return;
		       }
		       break;
		
		  case Phase_Freq_Correct_PWM_OCR1A:
		     OCR1A =(uint16)(Max);
		     switch (CMP_OC1B_Mode)
		      {
			     case Phase_Correct_PWM_Non_Inverting_OC1B :
			          OCR1B = (uint16)(((Duty/100)*2*(Max)) + 0.5) ;
			          break;
			     case Phase_Correct_PWM_Inverting_OC1B :
			          OCR1B = (uint16)(((100 - Duty)/100)*2*(Max)) + 0.5 ;
			          break;
			     default:
			          return;
		       }
		      break;
		
		   case Phase_Correct_PWM_ICR1:
		    ICR1 =(uint16)(Max);
		     switch (CMP_OC1B_Mode)
	          {
			     case Phase_Correct_PWM_Non_Inverting_OC1B :
			          OCR1B = (uint16)(((Duty/100)*2*(Max)) + 0.5) ;
			          break;
			     case Phase_Correct_PWM_Inverting_OC1B :
			          OCR1B = (uint16)(((100 - Duty)/100)*2*(Max)) + 0.5 ;
			          break;
			     default:
			          return;
		     }
		    break;
		
		  case Phase_Correct_PWM_OCR1A:
		    OCR1A =(uint16)(Max);
		     switch (CMP_OC1B_Mode)
		      {
			     case Phase_Correct_PWM_Non_Inverting_OC1B :
			          OCR1B = (uint16)(((Duty/100)*2*(Max)) + 0.5) ;
			          break;
			     case Phase_Correct_PWM_Inverting_OC1B :
			          OCR1B = (uint16)(((100 - Duty)/100)*2*(Max)) + 0.5 ;
			          break;
			     default:
			           return;
		     }
		    break;
		
		  case Fast_PWM_ICR1:
		   ICR1 =(uint16)(Max);
		    switch (CMP_OC1B_Mode)
		     {
			    case Fast_PWM_Non_Inverting_OC1B :
			         OCR1B = (uint16)(((Duty/100)*(Max)) + 0.5) ;
			         break;
			     case Fast_PWM_Inverting_OC1B :
			          OCR1B = (uint16)(((100 - Duty)/100)*(Max)) + 0.5 ;
			          break;
			     default:
			          return;
		    }
		   break;
		
		  case Fast_PWM_OCR1A:
		    OCR1A =(uint16)(Max);
		     switch (CMP_OC1B_Mode)
		      {
			     case Fast_PWM_Non_Inverting_OC1B :
			          OCR1B = (uint16)((Duty/100)*(Max)) + 0.5 ;
			          break;
			     case Fast_PWM_Inverting_OC1B :
			          OCR1B = (uint16)(((100 - Duty)/100)*(Max)) + 0.5 ;
			          break;
			     default:
			          return;
		      }
		     break;
		  default:
		        return;
	}
}