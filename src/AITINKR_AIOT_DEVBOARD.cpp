#include "AITINKR_AIOT_DEVBOARD.h"
#include "Wire.h"

uint8_t pbf[] = { 37, 38, 39, 40, 41, 42 };
uint8_t dof[] = { 6, 7, 8, 9, 10, 11 };
uint8_t dif[] = { 12, 13, 14, 15, 16, 17 };
uint8_t aif[] = { 18,19,20,21,22,23,24,25 };
uint8_t aof[] = { 33,34,35,36 };
uint8_t swf[] = { 29,30,31,32 };
uint8_t ssf[] = { 43,44,45,46 };

bool ioBegin() {
	  delay(1000);
  return Wire.begin(SDA, SCL);
}

bool pinType(uint8_t pin, uint8_t set) {
  return write88(pbf[pin - 1], set);
}

bool digitalOut(uint8_t pin, uint8_t state) {
 return write88(dof[pin - 1], state);   
}

bool digitalIn(uint8_t pin) {
  return read8(dif[pin - 1]);
}

uint8_t analogIn(uint8_t pin) {	
	return read8(aif[pin - 1]);
 }
bool DHTBegin() {

  return write8(48);
}
uint8_t DHTTemp() {

  return read8(27);
}
uint8_t DHTHum() {

  return read8(26);
}
uint8_t USRead() {
	
	int ub =read8(28);
	
if(!(ub==255)){
	return ub;
}	else{
	
	return 0;
		
	
	}
}
bool servoOut(uint8_t pin, uint8_t state) {
return write88(swf[pin - 1], state);
}
bool analogOut(uint8_t pin, uint8_t state) {
return write88(aof[pin - 1], state); 
}

bool servoSet(uint8_t pin) {
return write8(ssf[pin - 1] );
}



bool motorSetup() {
  return write8(47);
}
bool motorForward() {
  return write8(1);
}
bool motorBackword() {
  return write8(2);
}
bool motorLeft() {
  return write8(3);
}
bool motorRight() {
  return write8(4);
}
bool motorStop() {
  return write8(5);
}
bool motorSpeed(int spd) {
  return write88(49, spd);
}


uint8_t read8(uint8_t rd) {
  Wire.beginTransmission(IO_ADDRESS);

  Wire.write(rd);
  Wire.endTransmission(true);              
  Wire.requestFrom(IO_ADDRESS, 1, true);   
 
  while (Wire.available()) {   
    return Wire.read();        
                                
  }
}

uint8_t read8w(uint8_t rd) {
  Wire.beginTransmission(IO_ADDRESS);

  Wire.write(rd);
  Wire.endTransmission(true);              
  Wire.requestFrom(IO_ADDRESS, 1, true);   
 while (!Wire.available());
  while (Wire.available()) {   
    return Wire.read();        
                                
  }
}


bool write8(uint8_t reg) {
  Wire.beginTransmission(IO_ADDRESS);

  Wire.write(reg);



  if (Wire.endTransmission(true) == 0) return true;
  return false;   
}




bool write88(uint8_t reg, uint8_t control) {
  Wire.beginTransmission(IO_ADDRESS);

  Wire.write(reg);
  Wire.write(control);


  if (Wire.endTransmission(true) == 0) return true;
  return false;   
}
bool write8b(uint8_t reg, bool control) {
  Wire.beginTransmission(IO_ADDRESS);

  Wire.write(reg);
  Wire.write(control);


  if (Wire.endTransmission(true) == 0) return true;
  return false;  
}
