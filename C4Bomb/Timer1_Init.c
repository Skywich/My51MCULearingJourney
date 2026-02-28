#include <REGX52.H>

/**
  *@brief 11.0592mhz一毫秒定时器2初始化
  *@param 无
  *@retval 无
  */
void Timer1_Init() 
{
	TMOD=TMOD&0x0F;
	TMOD|=0x10;
	TF1=0;	
	TH1=0xFC;
	TL1=0x66;
	TR1=1;
	ET1=1;
	EA=1;
	PT1=0;
}