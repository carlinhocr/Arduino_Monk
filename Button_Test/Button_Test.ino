
#include <Bounce2.h> 

#define button_pin 4
#define button_pin_led 5
#define led_pin 6

int ledState = LOW;

Bounce b = Bounce(); //instantiate object button

void setup() {
b.attach(button_pin,INPUT_PULLUP);
b.interval(25); //debounce interval 25 milliseconds

pinMode(button_pin_led, OUTPUT);
digitalWrite(button_pin_led,HIGH);

pinMode(led_pin, OUTPUT);
digitalWrite(led_pin,ledState);
}

void loop() {
  b.update();
  if (b.fell()){ //call code if button transtion from high to low
    ledState = !ledState; //toggle the led state
    digitalWrite(led_pin,ledState);
  }
}
