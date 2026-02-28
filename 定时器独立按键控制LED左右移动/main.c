#include <REGX52.H>
#include "Timer0_Init.h"
#include <intrins.h>

unsigned char KeyNum,LEDMod=1;
void main ()
{

	Timer0_Init();
	P2=~0x80;
	while(1)
	{
		KeyNum=GetKeyNum();
		if(KeyNum==1)
		{
//			P2_0=~P2_0;
			LEDMod=1;
		}
		if(KeyNum==2)
		{
//			P2_1=~P2_1;
			LEDMod=2;
		}
	}
	
}

void Timer0_Routine() interrupt 1
{
	static unsigned int Counter=0;
	TH0=0xFC;
	TL0=0x66;
	Counter++;
	
	if(Counter>=500)
	{
		Counter=0;
		if(LEDMod==1)
		{
			P2=_crol_(P2,1);
		}
		else if(LEDMod==2)
		{
			P2=_cror_(P2,1);
		}
	}
}
