///
/// NOTE On Desktop systems, compile with -D NO_PI flag.
///

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>

#ifndef NO_PI
#include <wiringPi.h>
#endif

using namespace std;

///
/// Configuration
///

const int led_Red = 0;
const int led_Yellow = 1;
const int led_Green = 2;
const int timeoutMs = 1000;

///
/// Utils
///
void init()
{
#ifndef NO_PI
    wiringPiSetup();
    pinMode(led_Red, OUTPUT);
    pinMode(led_Green, OUTPUT);
    pinMode(led_Yellow, OUTPUT);
#endif
}

void setLed(int ledNumber, bool value)
{
#ifndef NO_PI
    digitalWrite(ledNumber, value);
#else
    cout << "Setting led " << ledNumber << " to " << (value ? "ON" : "OFF") << endl;
#endif
}

void normalCycle(){
    unsigned int countRed = 0;
    unsigned int countRed = 0;
    unsigned int countRed = 0;
    unsigned int countRed = 0;

}

int main()
{
    init();

    bool onoff = true;
    unsigned int count = 0;

    while(1)
    {

#ifndef NO_PI
        delay(timeoutMs);
#else
        usleep(timeoutMs * 1000); // this func from unistd expects microseconds
#endif
    } // main loop

    return 0;
}
