#include <ezTime.h>
#include <WiFi.h>

Timezone myTz;



void time_setup()
{
    Serial.println("🛜WiFi....");
    WiFi.begin(SSID, PASSWORD);
    Serial.println("🕰️Clock....");
    waitForSync();
    myTz.setLocation(F("Europe/Paris"));
    Serial.println("👌Time is up!");
}

void time_serial()
{
    Serial.print(myTz.hour());
    Serial.print(":");
    Serial.println(myTz.minute());
    delay(1000);
}

int time_hour(){
    return myTz.hour();
}

int time_minute(){
    return myTz.minute();
}

int time_second(){
    return myTz.second();
}

void time_loop()
{
    events();
}