#include <REGX52.H>
/**
  *@brief  初始化0定时器
  *@param  无
  *@retval 无
  */

void Timer0Init()
{
	TMOD&=0xF0;
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x66;
	TF0=0;
	TR0=1;
	ET0=1;
	EA=1;
	PT0=0;
	
}