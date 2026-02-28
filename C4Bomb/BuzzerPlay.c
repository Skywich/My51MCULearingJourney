#include <REGX52.H>

void Delay10us(unsigned char x10us)	//@11.0592MHz
{
	unsigned char data i;
	while(x10us--)
	{
		i = 2;
		while (--i);		
	}
}



void BuzzerPlay(unsigned int xms)
{
	unsigned int Duration=0;
	while(Duration<=xms)
	{
		P2_5=1;
		Delay10us(12);
		P2_5=0;
		Delay10us(12);
		Duration+=25;
	}
}