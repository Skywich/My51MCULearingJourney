#include "regx52.h"
#include "intrins.h"

sbit LED1=P2^0;

void Delay(unsigned int xms)	//@11.0592MHz
{
	unsigned char data i, j;
	while(xms){
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main()
{
	while(1){
		if(P3_1==0)
		{
			Delay(20);
			while(P3_1==0);
			Delay(20);
			LED1=~LED1;
		}
			
			
		
	}
	
}
