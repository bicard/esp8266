/************************ Adafruit IO Config *******************************/

#define IO_USERNAME "bicard"
#define IO_KEY "aio_YzOq20J7tN0LY0GymKBdzOjcahzL"

/******************************* WIFI **************************************/

#define WIFI_SSID "Is this a joke?"
#define WIFI_PASS "Yes it is"

#include "AdafruitIO_WiFi.h"

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
