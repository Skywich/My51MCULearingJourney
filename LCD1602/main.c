#include <REGX52.H>
#include "LCD1602.h"


void main ()
{
	LCD_Init();
	LCD_ShowChar(1,1,'A');
	LCD_ShowString(1,3,"ABC");
	LCD_ShowNum(1,7,1,2);
	LCD_ShowSignedNum(1,10,-1,1);
	LCD_ShowHexNum(2,1,0xFF,2);
	LCD_ShowBinNum(2,4,3,2);
	while(1)
	{
	}
}