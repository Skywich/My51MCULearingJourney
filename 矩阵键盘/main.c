#include <REGX52.H>
#include "DELAY.h"
#include "LCD1602.h"
#include "MATRIXKEY.H"

void main()
{
	unsigned int KeyNumber=0;
	
	LCD_Init();
	LCD_ShowString(1,1,"MatrixKey!");
	
	while(1)
	{
		KeyNumber=MATRIXKEY();
		if(KeyNumber)
		{
			LCD_ShowNum(2,1,KeyNumber,2);
		}
		
	}
}