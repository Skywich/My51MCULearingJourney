#include <REGX52.H>
#include "Timer0_Init.H"
#include "Timer1_Init.H"
#include "BuzzerPlay.H"
#include "LCD1602.H"
#include "MATRIXKEY.H"
#include "Delay.h"
#include <stdio.h>



unsigned char DownCount=40,DownCountMod=1;
unsigned long int Password=0;


unsigned long int GetPassword()
{
	unsigned char Key=16;
	Key=MatrixKey();
	if(Key!=16&&Password/1000000==0) //16代表没有按下矩阵键盘
	{
		if(Key>=0 &&Key<=9)
		{
			Password*=10;
			Password+=Key;
		}
	}
	return Password;
}


void main ()
{
	unsigned char flag=0;
	unsigned char str[7]={0};
	unsigned long int Password=0;

	LCD_Init();
	LCD_ShowString(1,8,"C4");
	LCD_ShowString(2,5,"_______");

	while(1)
	{
		
		//获取密码
		if(Password/1000000==0)
		{			
			Password=GetPassword();
			if(Password!=0)
			{
				sprintf(str,"%ld",Password);//让LCD1602可以显示7位数字
				LCD_ShowString(2,5,str);  				
			}		
		}
		
		//判断密码是否正确
		if(Password/1000000!=0)
		{
			if(Password==7355608&&flag!=1)
			{
				Timer0_Init();
				Timer1_Init();
				LCD_ShowString(1,1,"Bomb has been ");
				LCD_ShowString(2,1,"planted.        ");
				flag=1;
			}
			else if(Password!=7355608)
			{
				Password=0;
				LCD_ShowString(2,5,"       ");
				LCD_ShowString(1,6,"WRONG!");
				Delay(20000);
				LCD_ShowString(1,6,"      ");
				LCD_ShowString(1,8,"C4");
				LCD_ShowString(2,5,"_______");
			}
		}
		
		//引爆模式
		if(flag==1)
		{			
			LCD_ShowNum(2,15,DownCount,2);			
			if(DownCount==0)
			{
				LCD_ShowNum(2,1,DownCount,2);
				TR1=0;
				TR0=0;
				EA=0;
				LCD_ShowString(1,1,"!!!!!!Boom!!!!!!");
				LCD_ShowString(2,1,"!!!!!!!!!!!!!!!!");
				BuzzerPlay(65534);
			}				
		}
		
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int Counter0=0;
	TH0=0xFC;
	TL0=0x66;
	Counter0++;
	if(Counter0>=1000)
	{
		Counter0=0;
		DownCount--;
		if(DownCount<=0)
		{
			DownCountMod=4;
		}
		else if(DownCount<=10)
		{
			DownCountMod=3;
		}
		else if(DownCount<=30)
		{
			DownCountMod=2;
		}
		else if(DownCount<=40)
		{
			DownCountMod=1;
		}
		
	}
	
}

void Timer1_Routine() interrupt 3
{
	static unsigned int Counter1=0;
	TH1=0xFC;
	TL1=0x66;
	Counter1++;
	if(DownCountMod==3)
	{
		if(Counter1>=333)
		{
			BuzzerPlay(1000);
			Counter1=0;
		}
	}
	if(DownCountMod==2)
	{
		if(Counter1>=500)
		{
			BuzzerPlay(1000);
			Counter1=0;
		}
	}
	if(DownCountMod==1)
	{
		if(Counter1>=1000)
		{
			BuzzerPlay(1000);
			Counter1=0;
		}
	}
	
}