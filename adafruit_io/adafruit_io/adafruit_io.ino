
// TFT LCD graphics
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include "config.h"

#define IO_LOOP_DELAY 5000

#define STMPE_CS 16
#define TFT_CS   0
#define TFT_DC   15
#define SD_CS    2


Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

// set up the 'counter' feed
AdafruitIO_Feed *button = io.feed("button");

void setup() {
  
  Serial.begin(115200);
  
  delay(10);

  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(1);
  tft.println("Hello World!");
  
  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  button->onMessage(handleMessage);
  
  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

  tft.setTextColor(ILI9341_YELLOW);  tft.setTextSize(1);
  tft.println(io.statusText());
  
  button->get();
}

void loop()
{
    io.run();
    
    return;
}

void handleMessage(AdafruitIO_Data *data) {

  Serial.print("received <- ");

  char *string = data->value();
  Serial.println(string);

  if (string[1] == 'N')
    tft.fillScreen(ILI9341_GREEN);
  else
    tft.fillScreen(ILI9341_RED);
}
