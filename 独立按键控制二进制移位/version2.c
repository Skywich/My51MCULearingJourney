#include <REGX52.H>
#include <intrins.h>


typedef unsigned int u16;

void Delay1ms(u16 xms)	//@11.0592MHz
{
	while (xms--){
	unsigned char data i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}
}

char LEDNum=0;

void press_1()
{
	Delay1ms(20);
	while(P3_0==0);
	Delay1ms(20);
	
	LEDNum++;
	if(LEDNum==8)
	{
		LEDNum = 0;
	}
	P2=~(0x01 << LEDNum);
}

void press_2()
{
	Delay1ms(20);
	while(P3_0==0);
	Delay1ms(20);
	
	LEDNum--;
	if(LEDNum==-1)
	{
		LEDNum = 7;
	}
	P2=~(0x01 << LEDNum);
}




void main ()
{
	P2 = ~0x01;

	while(1)
	{
		if(P3_0==0)
		{
			press_1();
		}
		if(P3_1==0)
		{
			press_2();
		}
	}
}
