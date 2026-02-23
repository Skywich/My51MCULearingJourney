#include <REGX52.H>
#include <intrins.h>

void light_Nixie(unsigned char Position, unsigned char Number)
{
	//unsigned char PositionTable[8]={111, 110, 101, 100, 011, 010, 001, 000};
	unsigned char NumberTable[10]={0x3F, 0x06,0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
	//unsigned char PB;
	//PB=PositionTable[Position];
	//version1
//	P2_2=PB%10;
//	PB/=10;
//	P2_3=PB%10;
//	PB/=10;
//	P2_4=PB;
	
	//version2
	switch(Position)
	{
		case 1:P2_4=1;P2_3=1;P2_2=1;break;
		case 2:P2_4=1;P2_3=1;P2_2=0;break;
		case 3:P2_4=1;P2_3=0;P2_2=1;break;
		case 4:P2_4=1;P2_3=0;P2_2=0;break;
		case 5:P2_4=0;P2_3=1;P2_2=1;break;
		case 6:P2_4=0;P2_3=1;P2_2=0;break;
		case 7:P2_4=0;P2_3=0;P2_2=1;break;
		case 8:P2_4=0;P2_3=0;P2_2=0;break;
		
		
	}
	
	P0=NumberTable[Number];
}

void main ()
{
	unsigned char Position, Number;
	Position = 1;
	Number = 8;
	light_Nixie(Position,Number);
	while(1)
	{
		
	}
}