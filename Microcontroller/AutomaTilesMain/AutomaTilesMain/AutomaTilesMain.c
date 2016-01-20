/*
 * AutomaTilesMain.c
 *
 * Created: 7/14/2015 15:53:13
 *  Author: Joshua
 */ 


#include <inttypes.h>

#include "AutomaTiles.h"

const uint8_t colors[48][3] = {
	{0x00, 0x00, 0xFF},
	{0x00, 0x10, 0xF0},
	{0x00, 0x20, 0xE0},
	{0x00, 0x30, 0xD0},
	{0x00, 0x40, 0xC0},
	{0x00, 0x50, 0xB0},
	{0x00, 0x60, 0xA0},
	{0x00, 0x70, 0x90},
	{0x00, 0x80, 0x80},
	{0x00, 0x90, 0x70},
	{0x00, 0xA0, 0x60},
	{0x00, 0xB0, 0x50},
	{0x00, 0xC0, 0x40},
	{0x00, 0xD0, 0x30},
	{0x00, 0xE0, 0x20},
	{0x00, 0xF0, 0x10},
	{0x00, 0xFF, 0x00},
	{0x10, 0xF0, 0x00},
	{0x20, 0xE0, 0x00},
	{0x30, 0xD0, 0x00},
	{0x40, 0xC0, 0x00},
	{0x50, 0xB0, 0x00},
	{0x60, 0xA0, 0x00},
	{0x70, 0x90, 0x00},
	{0x80, 0x80, 0x00},
	{0x90, 0x70, 0x00},
	{0xA0, 0x60, 0x00},
	{0xB0, 0x50, 0x00},
	{0xC0, 0x40, 0x00},
	{0xD0, 0x30, 0x00},
	{0xE0, 0x20, 0x00},
	{0xF0, 0x10, 0x00},
	{0xFF, 0x00, 0x00},
	{0xF0, 0x00, 0x10},
	{0xE0, 0x00, 0x20},
	{0xD0, 0x00, 0x30},
	{0xC0, 0x00, 0x40},
	{0xB0, 0x00, 0x50},
	{0xA0, 0x00, 0x60},
	{0x90, 0x00, 0x70},
	{0x80, 0x00, 0x80},
	{0x70, 0x00, 0x90},
	{0x60, 0x00, 0xA0},
	{0x50, 0x00, 0xB0},
	{0x40, 0x00, 0xC0},
	{0x30, 0x00, 0xD0},
	{0x20, 0x00, 0xE0},
	{0x10, 0x00, 0xF0}
};

uint8_t color = 0;
uint8_t inc = 1;
uint32_t doubleTime = 0;
uint8_t sent = 0;

void button(){
	setState(1);
	inc = 29;
	doubleTime = getTimer();
	sent = 0;
}

void click(){
	uint8_t states[6];
	getStates(states);
	uint8_t total = states[0]+states[1]+states[2]+states[3]+states[4]+states[5];
	if (total>0&&getState()==0)
	{
		setState(1);
		inc = 5;
		doubleTime = getTimer();
		sent = 0;
	}
}

int main(void)
{
	tileSetup();
	setTimeout(60);
	setButtonCB(button);
	setClickCB(click);
	setMic(0);
	
	uint32_t tLast = getTimer();
	uint32_t t = tLast;
	uint8_t dim = 1;
    while(1)
    {	
		t = getTimer();
		if (t-tLast>100)
		{
			color+=inc;
			if (dim<32)
			{
				dim++;
			}
			
			if (color>=48)
			{
				color=0;
			}
			setColor(colors[color]);
			tLast=t;
		}
		
		if(getState()==1){
			dim = 0;
			if (t-doubleTime>2000)
			{
				inc = 1;
				setState(0);
			}
			
			if(t-doubleTime>1000&&sent==0){
				sendClick();
				sent=1;
			}
		}
		
	}
}