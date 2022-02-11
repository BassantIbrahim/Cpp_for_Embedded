#include "GPIO.hpp"
#include "GPIO_ARM.h"


extern "C"
{
    extern void AVR_pinMode(int pinNum , int pinMode);
    extern void AVR_digitalWrite(int pinNum , int pinMode);
    extern int AVR_digitalRead(int pinNum);

    extern void ARM_pinMode(int pinNum , int pinMode);
    extern void ARM_digitalWrite(int pinNum , int pinMode);
    extern int ARM_digitalRead(int pinNum);
}
void GPIO::pinMode(int pinNum , int pinMode)
{
    #ifdef _GPIO_AVR_H_
        AVR_pinMode(pinNum , pinMode);
    #endif
    #ifdef _GPIO_ARM_H_
        ARM_pinMode(pinNum , pinMode);
    #endif
}
void digitalWrite(int pinNum , int pinMode)
{
    #ifdef _GPIO_AVR_H_
        AVR_digitalWrite(pinNum , pinMode);
    #endif
    #ifdef _GPIO_ARM_H_
        ARM_digitalWrite(pinNum , pinMode);
    #endif
}
int  digitalRead(int pinNum)
{
    #ifdef _GPIO_AVR_H_
        AVR_digitalRead(pinNum);
    #endif
    #ifdef _GPIO_ARM_H_
        ARM_digitalRead(pinNum);
    #endif
}