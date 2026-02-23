#include <reg52.h>

// ???????(???????)
sbit Buzzer = P1^5;

// ??????
void Delay(unsigned int ms) {
    unsigned int i, j;
    for(i = ms; i > 0; i--)
        for(j = 120; j > 0; j--);
}

void main() {
    while(1) {
     /*
        Buzzer = 1;      // ?????
        Delay(1000);     // ??1?
        Buzzer = 0;      // ??
        Delay(1000);     */
        
        // ????1??,????2(????,????????)
        
        unsigned int i;
        for(i = 0; i < 1000; i++) {  // ???1kHz??
            Buzzer = 1;
            Delay(1);     // 1ms???
            Buzzer = 0;
            Delay(1);     // 1ms???
        }
        Delay(1000);      // ??1?
        
    }
}