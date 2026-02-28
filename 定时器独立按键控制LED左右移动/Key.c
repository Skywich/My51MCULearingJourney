#include "Delay.h"
#include <REGX52.H>

/**
  *@brief  获取独立按键的信息
  *@param  无
  *@revtal 从左到右分别为1，2，3，4.无按键则返回0
  */
unsigned char GetKeyNum()
{
	unsigned char KeyNum=0;
	if(P3_0==0)
	{
		Delay(20);
		while(P3_0==0);
		Delay(20);
		KeyNum=1;
	}
	if(P3_1==0)
	{
		Delay(20);
		while(P3_1==0);
		Delay(20);
		KeyNum=2;
	}
	if(P3_2==0)
	{
		Delay(20);
		while(P3_2==0);
		Delay(20);
		KeyNum=3;
	}
	if(P3_3==0)
	{
		Delay(20);
		while(P3_3==0);
		Delay(20);
		KeyNum=4;
	}
	return KeyNum;
}