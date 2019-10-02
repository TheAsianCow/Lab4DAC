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
            currKey = getKey();
            if(currKey=='*'){
                mode = 0;
                Graphics_clearDisplay(&g_sContext);
            }
            else if(currBtn==BIT0){
                mode = 1;
                Graphics_clearDisplay(&g_sContext);
                Graphics_drawStringCentered(&g_sContext, "DC Voltage", AUTO_STRING_LENGTH, 48,48, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }else if(currBtn==BIT6){
                mode = 2;
                Graphics_clearDisplay(&g_sContext);
                Graphics_drawStringCentered(&g_sContext, "Square Wave", AUTO_STRING_LENGTH, 48,48, OPAQUE_TEXT);
                Graphics_flushBuffer(&g_sContext);
            }else if(currBtn==BIT2){
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
        }
}
