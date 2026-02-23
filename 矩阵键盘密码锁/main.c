#include <REGX52.H>
#include "DELAY.h"
#include "LCD1602.h"
#include "MATRIXKEY.H"
#include "Buzzer.h"
/*
------------按键说明---------------
S1~9数字输入按键
S13 删除
S14 确定
S15 复位
S16 重设密码
-----------------------------------
*/

char HaltFlag=0;//标记是否处于      输入完成状态
char RightFlag=0;//标记是否处于     输入正确状态
char ResetModFlag=0;//标记是否处于  重设密码状态
char SureFlag=0;//标记是否处于      确定重设密码状态
unsigned long int InputedPassword=0,SetInputedPassword=1111,NewSetInputedPassword=0;//初始密码1111
unsigned char Count=0;	
unsigned int KeyNumber=0;
	
void IsShowSuccessStatus(char RightFlag)
	//显示输入正确才显示的星星*
{
	if(RightFlag==1)
	{
		LCD_ShowChar(2,16,'*');
	}
	else if (RightFlag==0)
	{
		LCD_ShowChar(2,16,' ');
	}	
}	

void PasswordInputStatus()
{
	LCD_ShowString(2,1,"                ");
	LCD_ShowString(2,1,"                ");
	LCD_ShowString(1,1,"Enter Password:");
	LCD_ShowChar(2,1,'{');
	LCD_ShowChar(2,6,'}');
	ResetModFlag=0;
	SureFlag=0;
	Count=0;	
	HaltFlag=0;
}

void PasswordResetStatus()
{
	LCD_ShowString(1,1,"                ");
	LCD_ShowString(1,1,"                ");	
	LCD_ShowString(1,1,"New Password:");
	LCD_ShowChar(2,1,'{');
	LCD_ShowChar(2,6,'}');
	ResetModFlag=1;
	RightFlag=0;	
	SureFlag=0;
}

void SureStatus()
{
	LCD_ShowString(1,1,"                ");
	LCD_ShowString(2,1,"                ");	
	LCD_ShowString(1,1,"Sure?");
	ResetModFlag=1;
	RightFlag=0;
	SureFlag=1;
}

void Input()
{
	if(Count<4 && ResetModFlag==0)//输入密码状态的输入
	{		
		InputedPassword*=10;
		InputedPassword+=KeyNumber;
		LCD_ShowNum(2,2,InputedPassword,4);
		Count++;
	}
	else if(Count<4 && ResetModFlag==1  && !SureFlag)//重设密码状态模式的输入
	{
		NewSetInputedPassword*=10;
		NewSetInputedPassword+=KeyNumber;
		LCD_ShowNum(2,2,NewSetInputedPassword,4);
		Count++;					
	}
}


void Comfirm_InputPassord()
{
	if(InputedPassword==SetInputedPassword)//密码正确
	{
		LCD_ShowString(1,1,"                ");
		LCD_ShowString(2,1,"      ");
		LCD_ShowString(1,1,"YEP!");
		BuzzerPlay(1);
		HaltFlag=1;
		RightFlag=1;
	}
	else//密码错误
	{
		LCD_ShowString(1,1,"                ");
		LCD_ShowString(2,1,"      ");
		LCD_ShowString(1,1,"NOPE!");
		BuzzerPlay(0);
		HaltFlag=1;
		RightFlag=0;
	}
}

void Comfirm_Resetpassword()
{
	if(SureFlag==0)//不处于确定重设状态的确定
	{
		SureStatus();
	}
	else if(SureFlag==1)//处于确定重设状态的确定
	{
		SetInputedPassword = NewSetInputedPassword;
		NewSetInputedPassword=0;
		PasswordInputStatus();
	}
}

void Comfirm()
{
	if(!ResetModFlag)//输入密码状态的确定
	{
		Comfirm_InputPassord();
	}
	else //重设密码状态的确定
	{
		Comfirm_Resetpassword();
	}
}


void Delete_Input()
{
	InputedPassword/=10;
	LCD_ShowNum(2,2,InputedPassword,4);
	if(Count>0)
	{
		Count--;
	}	
}

void Delete_Reset_BeforeSure()
{
	NewSetInputedPassword/=10;
	LCD_ShowNum(2,2,NewSetInputedPassword,4);
	if(Count>0)
	{
		Count--;
	}	
	else if(Count==0)//删除到零了就返回上一级状态:密码输入状态
	{
		PasswordInputStatus();
		RightFlag=1;
	}
}

void Delete_Reset_Sure()
{
	PasswordResetStatus();
	LCD_ShowNum(2,2,NewSetInputedPassword,4);
}

void Delete_Reset()
{
	if(SureFlag==0)//重设密码输入状态的删除
	{
		Delete_Reset_BeforeSure();
	}
	else//重设密码确定状态的删除：直接返回上一级状态
	{
		Delete_Reset_Sure();
	}
}



void Delete()
{
	if(ResetModFlag==0)//密码输入状态的删除
	{
		Delete_Input();
	}
	else//重设密码状态的删除
	{
		Delete_Reset();
	}

}

void Restart()
{
	if(ResetModFlag==0)
	{
		InputedPassword=0;
		PasswordInputStatus();	
	}
	else 
	{
		//复位在其他状态无效
	}

}


void main()
{

	//初始化
	LCD_Init();
	PasswordInputStatus();
	
	while(1)
	{
		KeyNumber = MatrixKey();//获取按键
		
		IsShowSuccessStatus(RightFlag);
		
		if(!HaltFlag)//处于非输入完成状态时，才可以进行除了复位以外的操作
		{
			
			//进入重设密码状态
			if(KeyNumber==16 && RightFlag==1)
			{
				PasswordResetStatus();
				LCD_ShowNum(2,2,0,4);
				Count=0;
			}

			//输入
			if(KeyNumber<=9 && KeyNumber>0)
			{
				Input();
			}
			
			//确定
			if(KeyNumber==14)
			{
				Comfirm();
			}
			
			//删除
			if(KeyNumber==13)
			{
				Delete();
				
			}
			
		}
		
		//复位 ： 只在密码输入完成状态有效
		else 
			if(KeyNumber==15)
			{
				Restart();
			}
		
		
		
		
		
	}
}