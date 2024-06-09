#include <avdweb_Switch.h>

const byte BUTTON_PIN = 2;
const byte BELL_PIN = 3;

const byte rings = 3;        // Number of rings of the bell
const long ringDelay = 800;  // Delay between rings of the bell
const long onDelay = 7;      // Milliseconds for the solenoid turned on
const long offDelay = 30;    // Milliseconds for the solenoid turned off
const long duration = 250;   // Milliseconds duration for solenoid oscillation


Switch button = Switch(BUTTON_PIN, INPUT_PULLUP, LOW);


void ringBell()
{
    byte cycles = duration / (onDelay + offDelay);

    for(byte r=0; r<rings; r++) {
        for(byte c=0; c<cycles; c++) {
            digitalWrite(BELL_PIN, HIGH);
            delay(onDelay);
            digitalWrite(BELL_PIN, LOW);
            delay(offDelay);
        }

        delay(ringDelay);
    }
}

void setup()
{
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(BELL_PIN, OUTPUT);
}

void loop()
{
    button.poll();
    if (button.pushed()) {
        ringBell();
    }
}



