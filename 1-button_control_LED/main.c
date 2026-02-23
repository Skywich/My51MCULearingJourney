#include "regx52.h"

sbit LED1=P2^0;
sbit button1=P3^1;

void main ()
{	
	while(1)
	{
		if(button1==0)
		{
			LED1=0;
		} 
		else
		{
			LED1=1;
		}
	
	}
}