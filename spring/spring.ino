#include <Arduino.h>
#include "wifi.h"
#include <PubSubClient.h>
#include <string>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// MQTT
#include "wifi.h"

#define MQTT_SERVER "tailor.cloudmqtt.com"
#define MQTT_PORT 18184

#define CLIENT_ID "AllEarsClient"
#define SPRING1_TOPIC "spring1"
#define SPRING2_TOPIC "spring2"
#define SPRING3_TOPIC "spring3"
#define SPRING4_TOPIC "spring4"
#define SPRING5_TOPIC "spring5"
#define SPRING6_TOPIC "spring6"
#define RAIN_TOPIC "rain"
#define BIRD_TOPIC "bird"




#define USERNAME "kvuwrinm"
#define PASSWORD "tucVHt31q7Gx"






const char *mqtt_server = MQTT_SERVER;
PubSubClient client(espClient);

// ---------------------------------------

//#define airPump 12
//#define vacuum 14
//#define airValve 13

#define vib1 12
#define vib2 13

// D3
#define airPump2 0
// D1
#define vacuum2 5
// D2
#define airValve2 4

#define PIN 14

#define NUMPIXELS 25 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int spring1n = 0;
int spring2n = 0;
int spring3n = 0;
int spring4n = 0;
int spring5n = 0;
int spring6n = 0;
int rain = 0;
int bird = 0;

// pump air
//      pinMode (airPump, OUTPUT);
//      pinMode(airValve, OUTPUT);
//      pinMode (vacuum, INPUT);

// ---------------------------------------

void mqtt_hanlder(char *topic,
                  byte *payload,
                  unsigned int length)
{
  if (length == 0)
    return;

  char message[length + 1];
  getMessageFromPayload(message, payload, length);
  int num = std::stoi(message);

  if (strcmp(topic, SPRING1_TOPIC) == 0)
  {

    //    Serial.println(topic);
    //    Serial.println(num);
    //    Serial.println(spring1n);

    spring1n = spring1n + num;
    if (spring1n == 2) {
      pinMode (airPump2, OUTPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
      led_light_loop();
      delay(5000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
    } else if (spring1n > 100) {
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, OUTPUT);
      delay(30000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, INPUT);
    }
    pixels.clear();
  } else if (strcmp(topic, SPRING2_TOPIC) == 0)
  {
    //    Serial.println(topic);
    //    Serial.println(num);
    //    Serial.println(spring2n);

    spring2n = spring2n + num;
    if (spring2n == 2) {
      Serial.println("pump2");
      pinMode (airPump2, OUTPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
      led_light_loop();
      delay(5000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
      pixels.clear();

    } else if (spring2n > 100) {
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, OUTPUT);
      delay(30000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, INPUT);
    }
  } else if (strcmp(topic, SPRING3_TOPIC) == 0)
  {

    spring3n = spring3n + num;
    if (spring3n == 2) {
      pinMode (airPump2, OUTPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
      led_light_loop();
      delay(5000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
      pixels.clear();
    } else if (spring3n > 100) {
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, OUTPUT);
      delay(30000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, INPUT);
    }
  } else if (strcmp(topic, SPRING4_TOPIC) == 0)
  {

    spring4n = spring4n + num;
    if (spring4n == 2) {
      pinMode (airPump2, OUTPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
      led_light_loop();
      delay(5000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
      pixels.clear();
    } else if (spring4n > 100) {
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, OUTPUT);
      delay(30000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, INPUT);
    }
  } else if (strcmp(topic, SPRING5_TOPIC) == 0)
  {

    spring5n = spring5n + num;
    if (spring5n == 2) {
      pinMode (airPump2, OUTPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
      led_light_loop();
      delay(5000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
      pixels.clear();
    } else if (spring5n > 100) {
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, OUTPUT);
      delay(30000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, INPUT);
    }
  } else if (strcmp(topic, SPRING6_TOPIC) == 0)
  {

    spring6n = spring6n + num;
    if (spring6n == 2) {
      pinMode (airPump2, OUTPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
      led_light_loop();
      delay(5000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, OUTPUT);
      pinMode (vacuum2, INPUT);
      pixels.clear();
    } else if (spring6n > 100) {
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, OUTPUT);
      delay(30000);
      pinMode (airPump2, INPUT);
      pinMode(airValve2, INPUT);
      pinMode (vacuum2, INPUT);

    }
  } else if (strcmp(topic, RAIN_TOPIC) == 0)
  {

    rain = rain + num;
    if (rain == 2) {
      pinMode(vib2, OUTPUT);
      led_light_rotate();
      //      delay(5000);
      pinMode (vib2, INPUT);
      pixels.clear();
    }
  } else if (strcmp(topic, BIRD_TOPIC) == 0)
  {

    bird = bird + num;
    if (bird == 2) {
      pinMode(vib1, OUTPUT);
      led_light_rotate();
      //      delay(5000);
      pinMode (vib1, INPUT);
      pixels.clear();
    }
  }

}

void setup_mqtt()
{
  client.setServer(mqtt_server, MQTT_PORT);
  client.setCallback(mqtt_hanlder);
}

void reconnect()
{
  while (!client.connected())
  {
    String clientId = CLIENT_ID;
    if (client.connect(clientId.c_str(), USERNAME, PASSWORD))
    {
      client.subscribe(SPRING1_TOPIC);
      client.subscribe(SPRING2_TOPIC);
      client.subscribe(SPRING3_TOPIC);
      client.subscribe(SPRING4_TOPIC);
      client.subscribe(SPRING5_TOPIC);
      client.subscribe(SPRING6_TOPIC);
      client.subscribe(RAIN_TOPIC);
      client.subscribe(BIRD_TOPIC);
    }
    else
    {
      delay(5000);
    }
  }
}

void mqtt_loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
}

void getMessageFromPayload(char *message, byte * payload, unsigned int length)
{
  for (unsigned int i = 0; i < length; i++)
  {
    message[i] = payload[i];
  }
  message[length] = '\0';
}


void setup()
{
  Serial.begin(9600);

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pinMode(PIN, OUTPUT);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  setup_wifi();
  setup_mqtt();
}

void led_light () {
    pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

    //    delay(DELAYVAL); // Pause before next pass through loop
  }
}

void turn_off () {
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    //        pixels.show();
    pixels.clear();

    delay(1);
  }
}

void led_light_loop () {
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(30); // Pause before next pass through loop
  }

  pixels.clear();
  pixels.show();

  //  turn_off();
}


void led_light_rotate () {
  int num = 5;
  while (num --) {
    pixels.clear();
    for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
      pixels.setPixelColor(i, pixels.Color(0, 150, 0));
      pixels.show();
      delay(50);
    }
  }

  pixels.clear();
  pixels.show();

  //  turn_off();
}



void loop()
{
  mqtt_loop();

  if (spring1n >= 2 && spring2n >= 2 && spring3n >= 2 && spring4n >= 2 && spring5n >= 2 && spring6n >= 2 && rain >= 2 && bird >= 2) {
    led_light();
    pinMode (airPump2, INPUT);
    pinMode(airValve2, INPUT);
    pinMode (vacuum2, OUTPUT);
    delay(30000);
    pinMode (airPump2, INPUT);
    pinMode(airValve2, INPUT);
    pinMode (vacuum2, INPUT);

  }

  delay(1);        // delay in between reads for stability
}
