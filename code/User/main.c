#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_SysTick.h"
#include "bsp_pwm.h"
#include "bsp_key.h"
#include "OLED_I2C.h"
#include "delay.h"

void type_1(void);
void type_2(void);
void type_3(void);
void type_4(void);
void type_5(void);
void type_6(void);

extern const unsigned char BMP1[];
extern const unsigned char BMP2[];
extern const unsigned char BMP3[];
extern const unsigned char BMP4[];
extern const unsigned char BMP5[];
extern unsigned char wait;

int main(void)
{ 		
		unsigned char a=0;	
	
		DelayInit();
		I2C_Configuration();
		OLED_Init();
		LED_GPIO_Config();
		TIM1_PWM_Init(199,7199);//(7200*200)/72000000=0.02=20ms
		
		KEY_Config();
		LED(ON);
	
//		while(1)
//		{
//			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//≤‚ ‘BMPŒªÕºœ‘ æ
//			DelayS(2);
//			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP2);//≤‚ ‘BMPŒªÕºœ‘ æ
//			DelayS(2);
//			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP3);//≤‚ ‘BMPŒªÕºœ‘ æ
//			DelayS(2);
//			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP4);//≤‚ ‘BMPŒªÕºœ‘ æ
//			DelayS(2);
//			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP5);//≤‚ ‘BMPŒªÕºœ‘ æ	
//			DelayS(2);
//		}


		while(1)
		{   
			OLED_OFF();//≤‚ ‘OLED–›√ﬂ
			LED(ON);
			wait=1;
			SysTick_Delay_Ms(1500);
			if(wait==0)
			{
				OLED_ON();
				switch(a)
				{
					case 1:type_1();break;
					case 2:type_2();break;
					case 3:type_3();break;
					case 4:type_4();break;
					case 5:type_5();break;
					case 6:type_6();break;
				}
				wait=1;
				OLED_OFF();
				a++;
				if(a==7)
				{
					a=1;
				}
			}
			
		}
			
			
}


//÷±Ω”ø™
void type_1(void)
{
			TIM_SetCompare1(TIM1,184); //45∂»,1ms
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP3);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(1500);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(1000);
			TIM_SetCompare2(TIM1,192);
			SysTick_Delay_Ms(200);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(800);
			TIM_SetCompare2(TIM1,174);
			SysTick_Delay_Ms(1000); 
			TIM_SetCompare1(TIM1,177); //90,1.5ms
			TIM_SetCompare2(TIM1,174);
			SysTick_Delay_Ms(2000);  
}

//øÏø™
void type_2(void)
{
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP5);//≤‚ ‘BMPŒªÕºœ‘ æ
			TIM_SetCompare1(TIM1,183); //45∂»,1ms
			TIM_SetCompare2(TIM1,192);
			SysTick_Delay_Ms(1000);
			
			
			TIM_SetCompare2(TIM1,174);
			TIM_SetCompare2(TIM1,174);
			SysTick_Delay_Ms(500); 
			TIM_SetCompare1(TIM1,177); //90,1.5ms
			SysTick_Delay_Ms(2000);          
}

//∞§¥Ú

void type_3(void)
{
			TIM_SetCompare1(TIM1,184); //45∂»,1ms
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP3);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(700);
			
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(700);

			TIM_SetCompare1(TIM1,184);
			SysTick_Delay_Ms(200);
			TIM_SetCompare1(TIM1,182);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(170);
			TIM_SetCompare1(TIM1,184);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP5);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(200);
			TIM_SetCompare1(TIM1,182);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(170);
			TIM_SetCompare1(TIM1,184);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP2);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(200);
			TIM_SetCompare1(TIM1,182);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(170);
			TIM_SetCompare1(TIM1,184);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP2);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(200);
			TIM_SetCompare1(TIM1,182);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(170);
			TIM_SetCompare1(TIM1,184);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP2);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(200);
			TIM_SetCompare1(TIM1,182);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP1);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(170);
			
			
			TIM_SetCompare1(TIM1,184);
			TIM_SetCompare2(TIM1,186);
			SysTick_Delay_Ms(1500);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP4);//≤‚ ‘BMPŒªÕºœ‘ æ
			TIM_SetCompare2(TIM1,186);
			TIM_SetCompare2(TIM1,188);
			SysTick_Delay_Ms(600);
			TIM_SetCompare2(TIM1,186);
			SysTick_Delay_Ms(500);
			TIM_SetCompare2(TIM1,188);
			SysTick_Delay_Ms(300);
			TIM_SetCompare2(TIM1,186);
			SysTick_Delay_Ms(500);
			TIM_SetCompare2(TIM1,188);
			SysTick_Delay_Ms(300);
			TIM_SetCompare2(TIM1,186);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP5);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(500);
			
			TIM_SetCompare2(TIM1,192);
			SysTick_Delay_Ms(300);
			TIM_SetCompare2(TIM1,174);
			SysTick_Delay_Ms(600); 
			TIM_SetCompare1(TIM1,177); //90,1.5ms
			SysTick_Delay_Ms(2000); 
}

//Õµø¥

void type_4(void)
{
			TIM_SetCompare1(TIM1,182); //45∂»,1ms
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP4);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(2000);
			TIM_SetCompare1(TIM1,184);
			SysTick_Delay_Ms(1000);
			TIM_SetCompare1(TIM1,179);
			TIM_SetCompare2(TIM1,176);
			SysTick_Delay_Ms(1500);
			
			TIM_SetCompare1(TIM1,183);
			TIM_SetCompare2(TIM1,190);
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP3);//≤‚ ‘BMPŒªÕºœ‘ æ
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,192);
			SysTick_Delay_Ms(700);
			TIM_SetCompare2(TIM1,174);
			SysTick_Delay_Ms(600);
			TIM_SetCompare1(TIM1,177); //90,1.5ms
			SysTick_Delay_Ms(5000);
}

//µ˜œ∑
void type_5(void)
{
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP3);//≤‚ ‘BMPŒªÕºœ‘ æ
			TIM_SetCompare1(TIM1,183); //45∂»,1ms
			SysTick_Delay_Ms(1500);
			TIM_SetCompare2(TIM1,187);
			SysTick_Delay_Ms(1500);
			
			OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP4);//≤‚ ‘BMPŒªÕºœ‘ æ
			TIM_SetCompare2(TIM1,188);
			SysTick_Delay_Ms(500);
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(300);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(100);
			TIM_SetCompare2(TIM1,190);
			SysTick_Delay_Ms(100);
			
			TIM_SetCompare2(TIM1,188);
			SysTick_Delay_Ms(1300);
			TIM_SetCompare2(TIM1,192);
			SysTick_Delay_Ms(400);
			
	
			TIM_SetCompare2(TIM1,174);
			SysTick_Delay_Ms(600);
			TIM_SetCompare1(TIM1,177);
			SysTick_Delay_Ms(2000);
	}

void type_6(void)
{
				OLED_DrawBMP(0,0,128,8,(unsigned char *)BMP5);//≤‚ ‘BMPŒªÕºœ‘ æ
			TIM_SetCompare1(TIM1,183); //45∂»,1ms
			TIM_SetCompare2(TIM1,192);
			SysTick_Delay_Ms(1000);
			
			TIM_SetCompare2(TIM1,174);
			SysTick_Delay_Ms(500); 
			TIM_SetCompare1(TIM1,177); //90,1.5ms
			SysTick_Delay_Ms(2000);    
			TIM_SetCompare1(TIM1,183); //45∂»,1ms
			
			TIM_SetCompare2(TIM1,191);
			SysTick_Delay_Ms(500); 
			
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(200); 
			TIM_SetCompare2(TIM1,188);
			SysTick_Delay_Ms(200); 
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(200); 
			TIM_SetCompare2(TIM1,188);
			SysTick_Delay_Ms(200); 
			TIM_SetCompare2(TIM1,189);
			SysTick_Delay_Ms(200); 
			TIM_SetCompare2(TIM1,188);
			SysTick_Delay_Ms(200); 
			TIM_SetCompare2(TIM1,188);
			SysTick_Delay_Ms(200); 
			TIM_SetCompare2(TIM1,187);
			SysTick_Delay_Ms(500); 
			
			TIM_SetCompare2(TIM1,174);
			SysTick_Delay_Ms(500); 
			TIM_SetCompare1(TIM1,177); //90,1.5ms
			SysTick_Delay_Ms(2000);    
}
	