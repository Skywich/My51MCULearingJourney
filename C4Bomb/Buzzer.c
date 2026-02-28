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


void BuzzerPlay (char Mod)
{
	if(Mod==1)
	{
		u16 code music[][2] = {
			{HALF,E5},
			{0, 0}
		};

		play_music(music);
	}
	else if(Mod==2)
	{
		u16 code music[][2]= {
			{QUAR,E5},
			{0,0}
		};
		play_music(music);
	}
	else if(Mod==3)
	{
		u16 code music[][2]= {
			{SIXTE,E5},
			{0,0}
		};
		play_music(music);
	}
	else if(Mod==4)
	{
		u16 code music[][2]= {
			{WHOL,E5},
			{0,0}
		};
		play_music(music);
	}



}
