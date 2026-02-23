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
#DEFINE TRIEIGH 8333

//pitch unit is 10us
#define C3 764
#define Cs3  722
#define D3   681
#define Ds3  643
#define E3   607
#define F3   573
#define Fs3  541     // F#3: 185.00 Hz, ?? 5.405ms = 5405µs = 540.5 ? 541
#define G3   510     // G3: 196.00 Hz, ?? 5.102ms = 5102µs = 510.2 ? 510
#define Gs3  482     // G#3: 207.65 Hz, ?? 4.816ms = 4816µs = 481.6 ? 482
#define A3   455     // A3: 220.00 Hz, ?? 4.545ms = 4545µs = 454.5 ? 455
#define As3  429     // A#3: 233.08 Hz, ?? 4.290ms = 4290µs = 429.0 ? 429
#define B3   405     // B3: 246.94 Hz, ?? 4.049ms = 4049µs = 404.9 ? 405

#define C4   382     // C4: 261.63 Hz, ?? 3.822ms = 3822µs = 382.2 ? 382
#define Cs4  361     // C#4: 277.18 Hz, ?? 3.609ms = 3609µs = 360.9 ? 361
#define D4   341     // D4: 293.66 Hz, ?? 3.406ms = 3406µs = 340.6 ? 341
#define Ds4  322     // D#4: 311.13 Hz, ?? 3.215ms = 3215µs = 321.5 ? 322
#define E4   303     // E4: 329.63 Hz, ?? 3.034ms = 3034µs = 303.4 ? 303
#define F4   286     // F4: 349.23 Hz, ?? 2.863ms = 2863µs = 286.3 ? 286
#define Fs4  270     // F#4: 369.99 Hz, ?? 2.703ms = 2703µs = 270.3 ? 270
#define G4   255     // G4: 392.00 Hz, ?? 2.551ms = 2551µs = 255.1 ? 255
#define Gs4  241     // G#4: 415.30 Hz, ?? 2.408ms = 2408µs = 240.8 ? 241
#define A4   227     // A4: 440.00 Hz, ?? 2.273ms = 2273µs = 227.3 ? 227
#define As4  215     // A#4: 466.16 Hz, ?? 2.145ms = 2145µs = 214.5 ? 215
#define B4   203     // B4: 493.88 Hz, ?? 2.025ms = 2025µs = 202.5 ? 203

#define C5   191     // C5: 523.25 Hz, ?? 1.911ms = 1911µs = 191.1 ? 191
#define Cs5  180     // C#5: 554.37 Hz, ?? 1.804ms = 1804µs = 180.4 ? 180
#define D5   170     // D5: 587.33 Hz, ?? 1.703ms = 1703µs = 170.3 ? 170
#define Ds5  161     // D#5: 622.25 Hz, ?? 1.608ms = 1608µs = 160.8 ? 161
#define E5   152     // E5: 659.25 Hz, ?? 1.517ms = 1517µs = 151.7 ? 152
#define F5   143     // F5: 698.46 Hz, ?? 1.432ms = 1432µs = 143.2 ? 143
#define Fs5  135     // F#5: 739.99 Hz, ?? 1.351ms = 1351µs = 135.1 ? 135
#define G5   128     // G5: 783.99 Hz, ?? 1.276ms = 1276µs = 127.6 ? 128
#define Gs5  120     // G#5: 830.61 Hz, ?? 1.204ms = 1204µs = 120.4 ? 120
#define A5   114     // A5: 880.00 Hz, ?? 1.136ms = 1136µs = 113.6 ? 114
#define As5  107     // A#5: 932.33 Hz, ?? 1.073ms = 1073µs = 107.3 ? 107
#define B5   101     // B5: 987.77 Hz, ?? 1.012ms = 1012µs = 101.2 ? 101

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


void main ()
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

//新年好
//			{EIGH,C4},{EIGH,C4},{QUAR,C4},{QUAR,G3},
//			{EIGH,E4},{EIGH,E4},{QUAR,E4},{QUAR,C4},
//			{EIGH,C4},{EIGH,E4},{QUAR,G4},{QUAR,G4},
//			{EIGH,F4},{EIGH,E4},{QUAR,D4},
//
//			{EIGH,D4},{EIGH,E4},{QUAR,F4},{QUAR,F4},
//			{EIGH,E4},{EIGH,D4},{QUAR,E4},{QUAR,C4},
//			{EIGH,C4},{EIGH,E4},{QUAR,D4},{QUAR,G3},
//			{EIGH,B3},{EIGH,D4},{QUAR,C4},

//塞尔达传说：获得物品
            {EIGH,A5},{TRIEIGH,A5},{TRIEIGH,A5},{TRIEIGH,G5},{EIGH,A5},

			{0, 0}
		};
	while(1)
	{

		play_music(music);
		Delay3000ms();


	}



}
