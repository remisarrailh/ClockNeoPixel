#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN_LEFT 5
#define PIN_RIGHT 4
#define COLOR_R 200
#define COLOR_G 0
#define COLOR_B 0

Adafruit_NeoPixel pixels_left(57, PIN_LEFT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels_right(59, PIN_RIGHT, NEO_GRB + NEO_KHZ800);

String SSID = "";
String PASSWORD = "";

#include "segment.h"
#include "clock.h"

int last_minute = -1;
int last_second = -1;
bool blinky = false;
bool setup_complete = false;

void setup_in_progress(void *parameter)
{
  while (!setup_complete)
  {
    scan();
  }
  vTaskDelete(NULL);
}

void setting_time(){
  xTaskCreatePinnedToCore(setup_in_progress,"setup_in_progress",10000,NULL,1,NULL,0); /* Core where the task should run */
  time_setup();
  setup_complete = true;
  clear();
  delay(1000);
}

void setup()
{
  Serial.begin(115200);
  begin();
  clear();
  show();
  setting_time();
}


void clock_mode()
{
  if (temperatureRead() >= 90)
  {
    clear();
    pixels_left.setPixelColor(0, pixels_left.Color(50, 0, 0));
    esp_sleep_enable_timer_wakeup(1000000); // 1 seconde = 1 000 000 µs
    esp_light_sleep_start();                // Sommeil léger
    pixels_left.setPixelColor(0, pixels_left.Color(0, 0, 0));
    esp_sleep_enable_timer_wakeup(1000000); // 1 seconde = 1 000 000 µs
    esp_light_sleep_start();                // Sommeil léger
  }
  else
  {
    if (last_second != time_second())
    {
      blinky = !blinky;
      blink(blinky);
      last_second = time_second();
    }
    if (last_minute != time_minute())
    {
      Serial.println(temperatureRead());
      clear();
      led_time(time_hour(), time_minute());
      show();
      last_minute = time_minute();
    }
  }
  time_loop();
}

void loop()
{
  clock_mode();
}
