#include <REGX52.h>
#include "Delay.h"
/**
	* @brief  从左到右按列扫描矩阵键盘
	* @param  没有
	* @retval KeyNumber按下的按键0~9,没按返回16

按下不放则会停留在此函数

*/

unsigned int MatrixKey ()
{
	unsigned int KeyNumber=16;
	
	//列1
	P1=0xFF;
	P1_3=0;
	if(P1_7==0)
	{
		Delay(20);
		while(P1_7==0);
		Delay(20);
		KeyNumber=1;
	}
	if(P1_6==0)
	{
		Delay(20);
		while(P1_6==0);
		Delay(20);
		KeyNumber=4;
	}
	if(P1_5==0)
	{
		Delay(20);
		while(P1_5==0);
		Delay(20);
		KeyNumber=7;
	}
	//列2
	P1=0xFF;
	P1_2=0;
	if(P1_7==0)
	{
		Delay(20);
		while(P1_7==0);
		Delay(20);
		KeyNumber=2;
	}
	if(P1_6==0)
	{
		Delay(20);
		while(P1_6==0);
		Delay(20);
		KeyNumber=5;
	}
	if(P1_5==0)
	{
		Delay(20);
		while(P1_5==0);
		Delay(20);
		KeyNumber=8;
	}
	if(P1_4==0)
	{
		Delay(20);
		while(P1_4==0);
		Delay(20);
		KeyNumber=0;
	}
	//列3
	P1=0xFF;
	P1_1=0;
	if(P1_7==0)
	{
		Delay(20);
		while(P1_7==0);
		Delay(20);
		KeyNumber=3;
	}
	if(P1_6==0)
	{
		Delay(20);
		while(P1_6==0);
		Delay(20);
		KeyNumber=6;
	}
	if(P1_5==0)
	{
		Delay(20);
		while(P1_5==0);
		Delay(20);
		KeyNumber=9;
	}

	
	return KeyNumber;

}
