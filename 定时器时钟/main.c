#include <REGX52.H>
#include "Timer0Init.H"
#include "Delay.H"
#include "LCD1602.H"

unsigned char hour=0,minute=0,second=0;


void main ()
{
	Timer0Init();
	LCD_Init();
	LCD_ShowString(1,1,"Your clock here:");
	LCD_ShowString(2,1,"  :  :  ");
	hour=23;
	minute=59;
	second=55;
	
	while(1)
	{
		
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowNum(2,4,minute,2);
		LCD_ShowNum(2,7,second,2);
		
	}
}

void Timer0Routine() interrupt 1
{
	static unsigned int Counter=0;
	TH0=0xFC;
	TL0=0x66;	
	Counter++;
	if(Counter>=1000)
	{
		second++;
		if(second>=60)
		{
			second=0;
			minute++;
			if(minute>=60)
			{
				minute=0;
				hour++;
				if(hour>=24)
				{
					hour=0;
				}
			}
		}
		Counter=0;
	}
}

