#include <REGX52.H>
#include "Timer0_Init.h"



void main()
{
	Timer0_Init();
	while(1)
	{
		
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int Timer0_Count=0;
	Timer0_Count++;
	TH0=0xFC;
	TL0=0x66;
	if(Timer0_Count>=1000) //1s
	{
		P2_0=~P2_0;
		Timer0_Count=0;
	}
}