#include <REGX52.H>


void Delay1ms(unsigned int xms)	//@11.0592MHz
{
	unsigned char i, j;

	while(xms--){

		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

unsigned char Reverse(unsigned char x)
{
	x = (x & 0xF0) >> 4 | (x & 0x0F) << 4;
	x = (x & 0xCC) >> 2 | (x & 0x33) << 2;
	x = (x & 0xAA) >> 1 | (x & 0x55) << 1;
	return x;
}

void main ()
{
	unsigned char LEDNumber=0, ReverseLEDNumber;
	while (1)
	{
		if(P3_1==0)
		{
			Delay1ms(20);
			while(P3_1==0);
			Delay1ms(20);
			
			LEDNumber++;
			ReverseLEDNumber = Reverse(LEDNumber);
			P2=~ReverseLEDNumber;
		}
	}
}
