#ifndef AITINKR_AIOT_DEVBOARD_h
#define AITINKR_AIOT_DEVBOARD_h

#include "Arduino.h"


#define SP1 1
#define SP2 2
#define SP3 3
#define SP4 4
#define DP1 5
#define DP2 6

#define PWM1 1
#define PWM2 2
#define PWM3 3
#define PWM4 4

#define ePot 7
#define eVol 8
#define IO_ADDRESS 2

#define SDA 26
#define SCL 27


bool ioBegin();
uint8_t read8(uint8_t reg);
uint8_t read8w(uint8_t reg);
bool write8(uint8_t reg);
bool write88(uint8_t reg, uint8_t control);
bool write8b(uint8_t reg, bool control);
bool pinType(uint8_t pin, uint8_t set); 
bool digitalOut(uint8_t pin, uint8_t state); 
bool digitalIn(uint8_t pin); 
uint8_t analogIn(uint8_t pin); 
bool DHTBegin();
uint8_t DHTTemp();
uint8_t DHTHum();
uint8_t USRead();
bool servoOut(uint8_t pin, uint8_t state); 
bool analogOut(uint8_t pin, uint8_t state); 
bool servoSet(uint8_t pin); 
bool motorSetup();
bool motorForward();
bool motorBackword();
bool motorLeft();
bool motorRight();
bool motorStop( );
bool motorSpeed(int spd);

#endif  