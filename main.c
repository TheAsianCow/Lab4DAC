/************** ECE2049 DEMO CODE ******************/
/**************  13 March 2019   ******************/
/***************************************************/

#include <msp430.h>
#include "peripherals.h"

// Function Prototypes

// Declare globals here

// Main
void main(void){
        WDTCTL = WDTPW | WDTHOLD;

        initLeds();
        configDisplay();
        configKeypad();
        initADC();
        configBtn();

        unsigned char currBtn;

        for(;;){
            ADC12CTL0 |= ADC12SC;
            currBtn = getBtn();
        }
}
