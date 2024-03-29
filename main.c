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
        REFCTL0 &= ~REFMSTR;
        _BIS_SR(GIE);
        initLeds();
        configDisplay();
        configKeypad();
        initADC();
        configBtn();
        initDAC();

        mode = 0;
        triFlag = 0;
        unsigned char currBtn, currKey;
        float DACval;

        for(;;){
            ADC12CTL0 |= ADC12SC;
            while(ADC12CTL1 & ADC12BUSY);
            pos = ADC12MEM0 & 0x0FFF;
            currBtn = getBtn();
            currKey = getKey();
            if(currKey=='*'){
                mode = 0;
                stopTimerA2();
                Graphics_clearDisplay(&g_sContext);
            }
            else if(currBtn==BIT0){
                mode = 1;
                DACval = getA1();
                Graphics_clearDisplay(&g_sContext);
                Graphics_drawStringCentered(&g_sContext, "DC Voltage", AUTO_STRING_LENGTH, 48,48, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }else if(currBtn==BIT6){
                mode = 2;
                Graphics_clearDisplay(&g_sContext);
                Graphics_drawStringCentered(&g_sContext, "Square Wave", AUTO_STRING_LENGTH, 48,48, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }else if(currBtn== BIT2){
                mode = 3;
                Graphics_clearDisplay(&g_sContext);
                Graphics_drawStringCentered(&g_sContext, "Sawtooth Wave", AUTO_STRING_LENGTH, 48,48, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }else if(currBtn==BIT4){
                mode = 4;
                Graphics_clearDisplay(&g_sContext);
                Graphics_drawStringCentered(&g_sContext, "Triangle Wave", AUTO_STRING_LENGTH, 48,48, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }else if(mode==0){
                Graphics_drawString(&g_sContext, "Button 1: ", AUTO_STRING_LENGTH, 10,10, OPAQUE_TEXT);
                Graphics_drawString(&g_sContext, "DC Voltage", AUTO_STRING_LENGTH, 10,20, OPAQUE_TEXT);
                Graphics_drawString(&g_sContext, "Button 2: ", AUTO_STRING_LENGTH, 10,30, OPAQUE_TEXT);
                Graphics_drawString(&g_sContext, "Square Wave", AUTO_STRING_LENGTH, 10,40, OPAQUE_TEXT);
                Graphics_drawString(&g_sContext, "Button 3: ", AUTO_STRING_LENGTH, 10,50, OPAQUE_TEXT);
                Graphics_drawString(&g_sContext, "Sawtooth Wave", AUTO_STRING_LENGTH, 10,60, OPAQUE_TEXT);
                Graphics_drawString(&g_sContext, "Button 4: ", AUTO_STRING_LENGTH, 10,70, OPAQUE_TEXT);
                Graphics_drawString(&g_sContext, "Triangle Wave", AUTO_STRING_LENGTH, 10,80, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }
            if(mode==1){
//                initDAC();
                stopTimerA2();
                DACsend(pos);
            }else if(mode==2){
                startTimerA2(150);
            }else if(mode==3){
                startTimerA2(75);
            }else if(mode==4){
                startTimerA2(150);
            }
        }
}
