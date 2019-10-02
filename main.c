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

        unsigned int mode;
        unsigned char currBtn, currKey;

        for(;;){
            ADC12CTL0 |= ADC12SC;
            currBtn = getBtn();

            if(currBtn==BIT0){
                mode = 1;
                Graphics_clearDisplay(&g_sContext);
                Graphics_drawStringCentered(&g_sContext, "Producing DC Voltage", AUTO_STRING_LENGTH, 48,48, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }else if(currBtn==BIT6){
                mode = 2;
                Graphics_clearDisplay(&g_sContext);
                Graphics_drawStringCentered(&g_sContext, "Producing Square Wave", AUTO_STRING_LENGTH, 48,48, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }else if(currBtn==BIT2){
                mode = 3;
                Graphics_clearDisplay(&g_sContext);
                Graphics_drawStringCentered(&g_sContext, "Producing Sawtooth Wave", AUTO_STRING_LENGTH, 48,48, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }else if(currBtn==BIT4){
                mode = 4;
                Graphics_clearDisplay(&g_sContext);
                Graphics_drawStringCentered(&g_sContext, "Producing Triangle Wave", AUTO_STRING_LENGTH, 48,48, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }else{
                Graphics_drawString(&g_sContext, "Button 1: DC", AUTO_STRING_LENGTH, 10,12, OPAQUE_TEXT);
                Graphics_drawString(&g_sContext, "Button 2: Square Wave", AUTO_STRING_LENGTH, 10,24, OPAQUE_TEXT);
                Graphics_drawString(&g_sContext, "Button 3: Sawtooth Wave", AUTO_STRING_LENGTH, 10,36, OPAQUE_TEXT);
                Graphics_drawString(&g_sContext, "Button 4: Triangle Wave", AUTO_STRING_LENGTH, 10,48, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }
        }
}
