#include <reg52.h>
#include <intrins.h>

typedef unsigned char u8;
typedef unsigned int u16;

//duration :in 120bpm unit is 10us
#define QUAR  50000
#define DOTQ  75000L
#define HALF  100000L
#define WHOL  200000L
#define EIGH  25000
#define DOTE  37500
#define SIXTE 12500
#define TRIQUAR 16667
#define TRIEIGH 8333

//pitch unit is 10us
#define C3 764
#define Cs3  722
#define D3   681
#define Ds3  643
#define E3   607
#define F3   573
#define Fs3  541     
#define G3   510     
#define Gs3  482   
#define A3   455     
#define As3  429     
#define B3   405    

#define C4   382     
#define Cs4  361     
#define D4   341     
#define Ds4  322     
#define E4   303    
#define F4   286
#define Fs4  270    
#define G4   255    
#define Gs4  241     
#define A4   227     
#define As4  215    
#define B4   203     

#define C5   191    
#define Cs5  180     
#define D5   170     
#define Ds5  161     
#define E5   152     
#define F5   143     
#define Fs5  135     
#define G5   128     
#define Gs5  120     
#define A5   114     
#define As5  107    
#define B5   101    

#define REST 0

sbit BEEP=P2^5;

void delay_10us(u16 ten_us)
{
	while (ten_us--);
}

//unit of duration is 10us
//unit of pitch is 10us
void note(u16 duration,u16 pitch)
{

	u16 total_time=0;
	if (pitch!=0)
	{
		while(total_time < duration)
		{
			BEEP = 1;
			delay_10us(pitch/2);
			BEEP = 0;
			delay_10us(pitch/2);
			total_time += pitch;
		}
	}
}

void play_music(u16 (*music)[2])
{
	u16 duration;
	u16 pitch;

	u16 (*play)[2] = music;

	while (play[0][0] !=0 || play[0][1] != 0)
	{
		duration = play[0][0];
		pitch = play[0][1];
		note(duration, pitch);
		play++;
	}
	delay_10us(100);
}

void Delay3000ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	_nop_();
	i = 127;
	j = 18;
	k = 107;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void BuzzerPlay (char YoN)
{
	if(YoN)
	{
		u16 code music[][2] = {
//Bad Apple!!
//			//1
//			{EIGH, A3}, {EIGH, B3}, {EIGH, C4}, {EIGH, D4},{QUAR,E4},{EIGH,A4},{EIGH,G4},
//			//2
//			{QUAR,E4},{QUAR,A3},{EIGH,E4},{EIGH,D4},{EIGH,C4},{EIGH,B3},
//			//3
//			{EIGH, A3}, {EIGH, B3}, {EIGH, C4}, {EIGH, D4},{QUAR,E4},{EIGH,D4},{EIGH,C4},
//			//4
//			{EIGH,B3},{EIGH,A3},{EIGH,B3},{EIGH,C4},{EIGH,B3},{EIGH,A3},{EIGH,Gs3},{EIGH,B3},
//

//			//5
//			{EIGH, A3}, {EIGH, B3}, {EIGH, C4}, {EIGH, D4},{QUAR,E4},{EIGH,A4},{EIGH,G4},
//			//6
//			{QUAR,E4},{QUAR,A3},{EIGH,E4},{EIGH,D4},{EIGH,C4},{EIGH,B3},
//			//7
//			{EIGH, A3}, {EIGH, B3}, {EIGH, C4}, {EIGH, D4},{QUAR,E4},{EIGH,D4},{EIGH,C4},
//			//8
//			{QUAR,B3},{QUAR,C4},{QUAR,D4},{QUAR,E4},
//

//			//9
//			{EIGH,G4},{EIGH,A4},{EIGH,E4},{EIGH,D4},{QUAR,E4},{EIGH,D4},{EIGH,E4},
//			//10
//			{EIGH,G4},{EIGH,A4},{EIGH,E4},{EIGH,D4},{QUAR,E4},{EIGH,D4},{EIGH,E4},
//			//11
//			{EIGH,D4},{EIGH,C4},{EIGH,B3},{EIGH,G3},{QUAR,A3},{EIGH,G3},{EIGH,A3},
//			//12
//			{EIGH,B3},{EIGH,C4},{EIGH,D4},{EIGH,E4},{QUAR,A3},{EIGH,E4},{EIGH,G4},


//			//13
//			{EIGH,G4},{EIGH,A4},{EIGH,E4},{EIGH,D4},{QUAR,E4},{EIGH,D4},{EIGH,E4},
//			//14
//			{EIGH,G4},{EIGH,A4},{EIGH,E4},{EIGH,D4},{QUAR,E4},{EIGH,A4},{EIGH,B4},
//			//15
//			{EIGH,C5},{EIGH,B4},{EIGH,A4},{EIGH,G4},{QUAR,E4},{EIGH,D4},{EIGH,E4},
//			//16
//			{EIGH,D4},{EIGH,C4},{EIGH,B3},{EIGH,G3},{QUAR,A3},
//

////新年好
//			{EIGH,C4},{EIGH,C4},{QUAR,C4},{QUAR,G3},
//			{EIGH,E4},{EIGH,E4},{QUAR,E4},{QUAR,C4},
//			{EIGH,C4},{EIGH,E4},{QUAR,G4},{QUAR,G4},
//			{EIGH,F4},{EIGH,E4},{QUAR,D4},

//			{EIGH,D4},{EIGH,E4},{QUAR,F4},{QUAR,F4},
//			{EIGH,E4},{EIGH,D4},{QUAR,E4},{QUAR,C4},
//			{EIGH,C4},{EIGH,E4},{QUAR,D4},{QUAR,G3},
//			{EIGH,B3},{EIGH,D4},{QUAR,C4},

//塞尔达传说：获得物品
            {EIGH,A4},{TRIEIGH,A4},{TRIEIGH,A4},{TRIEIGH,G4},{QUAR,A4},

			{0, 0}
		};

		play_music(music);
	}
	else
	{
		u16 code music[][2]= {
			{SIXTE,G4},{QUAR,C4},
			{0,0}
		};
		play_music(music);
	}



}
