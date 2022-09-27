/*
 * Solar_Traker_2.c
 *
 * Created: 11/24/2019 7:10:19 PM
 *  Author: shaher
 *program 1
              the program will calculate the position of the sun by entering the time and the date.
			  then moving the servos to this position.
			  the Equations :
			  Number_Of_Days=(Month*30)+Days-30
			   Local_Time=((float)Hours+((float)Minutes/60.0))
			   Local_Standard_Time_Mederation=15.0*Difference_Between_Local_Time_and_GMT
			   B_parameter=((360.0/365.0)*((float)Number_Of_Days-81.0))
			   Equation_of_Time=((9.87*sin(2*B_parameter))-(7.53*cos(B_parameter))-(1.5*sin(B_parameter)))
			   Time_Correction=(4*(Long_Tude-Local_Standard_Time_Mederation))+Equation_of_Time
			   Local_Solar_Time=(Local_Time+(Time_Correction/60.0))
			   Hour_Angle=(15.0*(Local_Solar_Time-12.0))
			   Decleration_Angle=(23.54*sin(B_parameter))
			   Altitude_Angle=asin((sin(Decleration_Angle)*sin(Latitude))-(cos(Decleration_Angle)*cos(Latitude)*cos(Hour_Angle)))
			   Azmiuth_Angle=acos(((sin(Decleration_Angle)*cos(Latitude))-(cos(Decleration_Angle)*sin(Latitude)*cos(Hour_Angle)))/cos(Altitude_Angle))
			   if(Hour_Angle>0)
			   {
				   Azmiuth_Angle=360-Azmiuth_Angle;
			   }
 ###############################################################################################################################################################
 
 *Program 2 
              ->first of all we initiate the timer1 to work in phase coorect mode that suitable for motors
              ->when the TCNT1 =OCR1 THE the signal will reset and set at Second compare because of using Non-inverting.
               ->the frequancy of the cpu is 1Mhz.
               ->the top of TCNT1 IS 10K that seted by ICR1 .
               ->BY USING THE Equation FREQpwm=F_cpu/(2*N*TOP).the frequany will be 50Hz.
                                N: is the prescaller that =1.
               ->Second intiate the ADC that will take two cycle of Conversion.
                       then
                            ->Top: is the reading of LDR at the Top.
                            ->Right: is the reading of LDR at the Right.
                            ->Left: is the reading of LDR at the Left.
                            ->Bottom: is the reading of LDR at the Bottom.
 
                            ->Servo_Vertical : is A veriable that save the Angle of Vertical Servo.
                            ->Servo_Horizontal : is A veriable that save the Angle of Horizontal Servo.
 
 then:
 the loop is Start:
 the Servos will Move by the initial value  Servo_Vertical=110 degree & Servo_Horizontal=90 degree.
 
 The ADC will read the LDR values and convert them from 0 : 1023.
 
 the CPU will compare the values of of LDR variable :
 
 there are an Accuercy Limit the deference between the values must cross 50.
 
 if top < Bottom  will increment the value of vertical Servo by 1 degree. else derement it.
 if Left > Right  will increment the value of Horizontal Servo by 1 degree. else derement it.
 
 then repeat the loop>
 
 */ 

#include "main.h"

uint16 Time=0;

ISR(TIMER1_COMPB_vect)
{
   Time++;	
}

int main(void)
{
	INT_Enable();
	Timer1_Init(Phase_Correct_PWM_ICR1, Phase_Correct_PWM_Non_Inverting_OC1A, Phase_Correct_PWM_Non_Inverting_OC1B, F_CPU_);
	  ADC_Init();
	 ICR1=10000;
	 //OCR1B=5000;
	 DDRD&=~(1<<7);
	 DDRD |=(1<<5)|(1<<4);
	 LCD_INIT();
	  
	 
	 float Sec=0.0,Minutes=0.0,Hours=7.0;  //entered by the user
	 
	 float month=3.0,day=20.0,rday,LSTM,rB,rd,rw,ra,rlatitude;
	 float longitude=31.0552,latitude=29.9246,LT,B,EOT,TC,LST,W,d,a,AZ,rAZ,xx,AZZ;
	 
	vuint16 Top=0,Right=0,Left=0,Bottom=0; //define Variables to Host sensors' Reading
	vuint16 Top_Avg=0,Left_Avg=0,Right_Avg=0,Bottom_Avg=0;
	vuint16 Servo_Vertical=45,Servo_Horizontal=90;  //define Variables to Host Degrees of Servos
	
	LCD_RowCol(0,0);
	LCD_Send_String("Welcome shaher");
	LCD_Clear();
    while(1)
    {
		/*start Clock*/
		if (Time>=95)
		{
			Sec++;
			Time=0;
		}
		if (Sec>=60)
		{
			Minutes++;
			Sec=00;
		}
		if (Minutes>=60)
		{
			Hours++;
			Minutes=00;
		}
		if (Hours>=24)
		{
			Hours=00;
		}
		
		
		if ((PIND&0x80)==0x80)
		{
		
		/*Start Calculating the Position of The Sun*/
				 LT=(Minutes/60.0)+Hours;
				 rday=day+((month-1)*31);
				 LSTM=30;
				 B=0.9863*(rday-81);
				 rB=(B*M_PI)/180;
				 EOT=(9.78*sin(2*rB))-(7.53*cos(rB))-(1.5*sin(rB));
				 TC=4*(longitude-LSTM)+EOT;
				 LST=LT+TC/60;
				 W=15*(LST-12);
				 rw=(W*M_PI)/180;
				 d=23.45*sin(rB);
				 rd=(d*M_PI)/180;
				 rlatitude=(latitude*M_PI)/180;
				 a=(asin((sin(rd)*sin(rlatitude))+(cos(rd)*cos(rlatitude)*cos(rw))));
				 xx=(a*180)/M_PI;
				 AZ=(acos(((sin(rd)*cos(rlatitude))-(cos(rd)*sin(rlatitude)*cos(rw)))/cos(ra)));
				 AZZ=(AZ*180)/M_PI;
				 if(LST<12)
				 rAZ=AZZ;
				 else
				 rAZ=360-AZZ;
				
		
        LCD_RowCol(0,0);
        LCD_Send_String("CLk:");
		LCD_RowCol(0,6);
		LCD_DisplayInt(Hours);
		LCD_RowCol(0,8);
		LCD_Send_String(":");
		LCD_RowCol(0,9);
		LCD_DisplayInt(Minutes);
		LCD_RowCol(0,11);
		LCD_Send_String(":");
		LCD_RowCol(0,12);
		LCD_DisplayInt(Sec);
		LCD_RowCol(1,0);
		LCD_Send_String("AZmi:");
		LCD_RowCol(1,5);
		LCD_DisplayInt(abs(180-(rAZ-90)));
		LCD_RowCol(1,9);
		LCD_Send_String("Alti:");
		LCD_RowCol(1,14);
		LCD_DisplayInt(abs(xx));
		/*Display the clock and the position of the sun on LCD*/
		Servo_PWM_2(abs(xx));
		
		Servo_PWM_1(abs(180-(rAZ-90)));
		/*move the Servos Toward the sun*/
		}
		
		
		
		else if ((PIND&0x80)==0x00){
			if (Servo_Vertical<=5)
			{
				Servo_Vertical=5;
			}
			if (Servo_Vertical>=180)
			{
				Servo_Vertical=180;
			}
			if (Servo_Horizontal<=5)
			{
				Servo_Horizontal=5;
			}
			if (Servo_Horizontal>=180)
			{
				Servo_Horizontal=180;
			}
			
			Servo_PWM_1(Servo_Horizontal);
			Servo_PWM_2(Servo_Vertical);
			/*start move */
			
			_delay_ms(80);
			
			LCD_RowCol(0,0);
			LCD_Send_String("CLk:");
			LCD_RowCol(0,6);
			LCD_DisplayInt(Hours);
			LCD_RowCol(0,8);
			LCD_Send_String(":");
			LCD_RowCol(0,9);
			LCD_DisplayInt(Minutes);
			LCD_RowCol(0,11);
			LCD_Send_String(":");
			LCD_RowCol(0,12);
			LCD_DisplayInt(Sec);
			LCD_RowCol(1,2);
			LCD_Send_String("Closed loop");
				
				/*Reading from Sensors Start*/
				Top=analog_Read(_PA0_);
				Right=analog_Read(_PA1_);
				Left=analog_Read(_PA2_);
				Bottom=analog_Read( _PA3_);
				
				Top_Avg=abs(Top-Bottom);
				Bottom_Avg=abs(Bottom-Top);
				Right_Avg=abs(Right-Left);
				Left_Avg=abs(Left-Right);
				
				/*compare between the readings*/
				if ((Top_Avg>=50) ||(Bottom_Avg>=50))
				{
					
					if (Top>Bottom)
					{
						Servo_Vertical++;
						_delay_ms(1);
					}
					if(Bottom>Top)
					{
						Servo_Vertical--;
						_delay_ms(1);
					}
					
				}
				if ((Left_Avg>=50) ||(Right_Avg>=50))
				{
					if (Left>Right)
					{
						Servo_Horizontal--;
						_delay_ms(1);
					}
					if(Right>Left)
					{
						Servo_Horizontal++;
						_delay_ms(1);
					}
					
				}
		}
		}
	
	
}


