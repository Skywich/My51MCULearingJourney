#include <REGX52.H>

/**
  *@brief 11.0592mhz一毫秒定时器初始化
  *@param 无
  *@retval 无
  */
void Timer0_Init() 
{
	TMOD=TMOD&0xF0;
	TMOD=0x01;
	TF0=0;	
	TH0=0xFC;
	TL0=0x66;
	TR0=1;
	ET0=1;
	EA=1;
	PT0=0;
}