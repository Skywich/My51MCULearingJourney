#include <REGX52.H>
void Delayxms(unsigned int time)	//@12.000MHz
{
	unsigned char data i, j;
	
	while(time--) 
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}


int main ()
{
	unsigned int i;
		while (1)
	{
		P2 = 0xFC;
		for(i=0;i<3;i++)
		{
			P2 = P2 << 2 | 0x03;
			Delayxms(100);
		}
		
		for (i=0;i<3;i++)
		{
			P2 = P2 >> 2 | 0xC0;
			Delayxms(100);
			
		}
		
	}
}