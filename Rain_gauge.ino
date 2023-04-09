#define RAIN_PULSE 15
 
long rainPulseCount = 0L;
volatile bool rainFlag = false;
 
void setup()
{
    Serial.begin(115200);
    Serial.println("Started");
    // clipping relay grounds the pin, causing it to go down
   pinMode(RAIN_PULSE, INPUT_PULLUP);
//    pinMode(RAIN_PULSE, INPUT); 
    attachInterrupt(digitalPinToInterrupt(RAIN_PULSE), rain_ISR, FALLING);
}
 
ICACHE_RAM_ATTR void rain_ISR() {
  rainFlag = true;
}
 
void loop() 
{



    if (rainFlag) {
        // Just bump the rain counter. Each bump is 0.01" of rain.
        // Will reset after reporting
        Serial.println("RAIN!");
        rainPulseCount++;
        Serial.println(rainPulseCount);
        rainFlag = false;
    }

}
