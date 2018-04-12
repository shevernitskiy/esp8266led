#ifndef esp8266led_h
#define esp8266led_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

class esp8266led
{
    public:
        esp8266led(uint8_t pin);
        void on();
        void off();
        void blinkDelay(int ms = 1000);
        void blinkOn();
        void blinkOff();
        void run();
    private:
        uint8_t _pin;
        boolean blinkFlag = false;
        unsigned long time;
        int msdelay = 1000;
};

#endif