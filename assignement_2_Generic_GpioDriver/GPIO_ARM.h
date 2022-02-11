#ifndef _GPIO_ARM_H_
#define _GPIO_ARM_H_

extern "C"
{
extern void ARM_pinMode(int pinNum , int pinMode);
extern void ARM_digitalWrite(int pinNum , int pinMode);
extern int ARM_digitalRead(int pinNum);
}
#endif