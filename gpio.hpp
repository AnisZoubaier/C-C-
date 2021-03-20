#ifndef GPIO_H
#define GPIO_H


//#include <wiringPi>
#include <string>
#include <vector>
#include <memory>
#include <stdio.h>


//WiringPi reference:
//vwiringPiSetup(void)
// pinMode(PIN ,MODE)
// digitalWrite(PIN, VALUE)
// delay(ms)

#define INPUT 0
#define OUTPUT 1

#define ON 1
#define OFF 0


class GPIO
{

private:

    unsigned int pinMode;
    unsigned int gpioPin;
    unsigned int state;
    std::string ID;

public:

    GPIO(unsigned int _gpioPin, unsigned int _pinMode = INPUT, std::string _ID = "unnamed");
    ~GPIO();


    unsigned int read();
    void write(unsigned int digitalValue);

    void LED_Blink(); //Init Mode ?
    void LED_On(); //Running Mode ?
    void LED_Off(); //may be useful
    void LED_Toggle(); //may be useful (blinking in another loop?)

    std::string getID();
    unsigned int getState();

private:

     void init(); //needs pinMode() from wiringPi Library

};



//************class dependent functions***************


unsigned int init_gpio(std::vector<std::unique_ptr<GPIO>> &gpioField);

//-->> Used to generate a vector filled with the pointers to all GPIO's available



#endif
