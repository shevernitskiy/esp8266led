#include "esp8266led.h"

esp8266led::esp8266led(uint8_t pin)
{
    pinMode(pin, OUTPUT);
    time = millis();
    blinkFlag = false;
    msdelay = 1000;
    _pin = pin;
}

void esp8266led::on()
{
    blinkFlag = false;
    digitalWrite(_pin, LOW);
}

void esp8266led::off()
{
    blinkFlag = false;
    digitalWrite(_pin, HIGH);
}

void esp8266led::blinkOn()
{
    blinkFlag = true;
}

void esp8266led::blinkOff()
{
    blinkFlag = false;
    esp8266led::off();
}

void esp8266led::blinkDelay(int ms)
{
    msdelay = ms;
}

void esp8266led::blink()
{
    unsigned long currentm = millis();
    if (blinkFlag && (currentm - time) >  msdelay)
    {
        time = millis();
        digitalWrite(_pin, !digitalRead(_pin));
    }
}


