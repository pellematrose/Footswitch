#include <BleKeyboard.h>

// shorter 15 character name seems to work better w. iPad
BleKeyboard bleKeyboard("NextSong", "DIY", 100);

#define button11_PIN 4
#define LED 22
#define button12_PIN 16


void setup() {
  pinMode(button11_PIN, INPUT_PULLDOWN);
  pinMode(button12_PIN, INPUT_PULLDOWN);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  digitalWrite(LED, 1);
  
  static int debug = 0, counter1 = 0, counter2 = 0;
  char button1 = digitalRead(button11_PIN) == LOW;
  char button2 = digitalRead(button12_PIN) == LOW;
  
  if(button1) counter1++;
  
  if(bleKeyboard.isConnected() && !button1 && counter1 > 1) 
  {
    Serial.println(counter1);
    
    bleKeyboard.write(counter1 < 10 ? KEY_RIGHT_ARROW : KEY_UP_ARROW);
    digitalWrite(LED, 0);
    delay(100);
    digitalWrite(LED, 1);
    bleKeyboard.releaseAll();

    counter1 = 0;
  }

  if(button2) counter2++;
  
  if(bleKeyboard.isConnected() && !button2 && counter2 > 1) 
  {
    Serial.println(counter2);

    bleKeyboard.write(counter2 < 10 ? KEY_LEFT_ARROW : KEY_DOWN_ARROW);
    digitalWrite(LED, 0);
    delay(100);
    digitalWrite(LED, 1);
    bleKeyboard.releaseAll();
  
    counter2 = 0;
  }
  if(++debug % 20 == 0) Serial.println("sec");
  delay(50);
}
