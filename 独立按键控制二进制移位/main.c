//#include <REGX52.H>
//#include <intrins.h>


//typedef unsigned int u16;

//void Delay1ms(u16 xms)	//@11.0592MHz
//{
//	while (xms--){
//	unsigned char data i, j;

//	_nop_();
//	_nop_();
//	_nop_();
//	i = 11;
//	j = 190;
//	do
//	{
//		while (--j);
//	} while (--i);
//}
//}

//void left_move()
//{
//		P2 = P2 << 1 | 0x01;
//		if(P2==0xFF)
//			P2=0xFE;

//}

//void right_move()
//{
//	P2=P2>>1 | 0x80;
//	if(P2==0xFF)
//		P2=0x7F;
//}

//void main ()
//{
//	P2 = 0xFF;
//	while(1)
//	{
//		if(P3_0==0)
//		{
//			Delay1ms(20);
//			while(P3_1==0);
//			Delay1ms(20);
//			if(P2==0xFF)
//				P2=0xFE;
//			else
//				left_move();
//		}
//		if(P3_1==0)
//		{
//			Delay1ms(20);
//			while(P3_0==0);
//			Delay1ms(20);
//			if(P2==0xFF)
//				P2=0x7F;
//			else
//				right_move();
//		}
//	}
//}



//Version2 below  
//without blank
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
	P2 = ~0x80;

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
