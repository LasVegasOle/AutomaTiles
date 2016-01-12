/*
 * AutomaTiles.h
 *
 * Created: 1/6/2016 11:56:26
 *  Author: Joshua
 */ 


#ifndef AUTOMATILES_H_
#define AUTOMATILES_H_

typedef void (*cb_func)(void);

void tileSetup(void);
void getStates(uint8_t * result);
void setColor(const uint8_t color[3]);
void setClickCB(cb_func cb);
void setButtonCB(cb_func cb);
void setTimeout(uint8_t t);


#endif /* AUTOMATILES_H_ */