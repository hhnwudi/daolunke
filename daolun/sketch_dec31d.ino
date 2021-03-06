
#include <Adafruit_NeoPixel.h>
#define humanHotSensor 4
#define PIN 8
#define key_pin 10
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, PIN, NEO_GRB + NEO_KHZ800);
#define buzzer_pin 6
bool humanHotState = false;
boolean buzzer_speak,add,a;
int i = 200;
int song[] = {
  220, 370, 370, 370, 370, 392, 440, 330, 0,
  220, 330, 330, 330, 330, 370, 392, 370, 0,
  294, 494, 494, 494, 494, 554, 587, 440, 392, 370, 0,
  246, 392, 392, 392, 392, 440, 494, 440, 330, 0,

  220, 370, 370, 370, 370, 392, 440, 330, 0,
  220, 330, 330, 330, 330, 370, 392, 370, 0,
  294, 494, 494, 494, 494, 554, 587, 440, 392, 370, 0,
  246, 330, 330, 330, 370, 330, 294, 246, 294, 0,

  294, 246, 0, 294, 494, 440, 0,
  392, 370, 330, 330, 294, 330, 370, 0,
  294, 494, 0,  554, 587, 440, 0,
  294, 294, 494, 494, 554, 587, 655, 0,

  370, 392, 440, 0, 294, 370, 392, 440, 0,
  294, 294, 494, 494, 554, 587, 440, 0,
  494, 554, 587, 587, 587, 554, 440, 494, 0,
  392, 440, 494, 440, 392, 440, 330, 0,

  370, 392, 440, 0, 294, 370, 392, 440, 0,
  294, 294, 494, 494, 554, 587, 440, 0,
  494, 554, 587, 587, 587, 554, 440, 494, 0,
  392, 440, 494, 554, 554, 494, 554, 587, 0,

  370, 392, 440, 0, 294, 370, 392, 440, 0,
  294, 294, 494, 494, 554, 587, 440, 0,
  494, 554, 587, 587, 587, 554, 440, 494, 0,
  392, 440, 494, 554, 554, 494, 554, 587, 0,
};

float noteDurations[] = {
  4, 2.666666, 8, 5.333333, 16, 5.333333, 16, 2, 4,
  4, 2.666666, 8, 5.333333, 16, 5.333333, 16, 2, 4,
  4, 2.666666, 8, 4, 12, 12, 12, 4, 4, 2.666666, 11,
  8, 2.666666, 8, 4, 12, 12, 12, 4, 2, 8,

  4, 2.666666, 8, 5.333333, 16, 5.333333, 16, 2, 4,
  4, 2.666666, 8, 5.333333, 16, 5.333333, 16, 2, 4,
  4, 2.666666, 8, 4, 12, 12, 12, 4, 4, 2.666666, 11,
  8, 2.666666, 8, 4, 12, 12, 12, 4, 2, 8,

  4, 2, 4, 8, 8, 2, 4,
  8, 8, 2.666666, 8, 4, 4, 2, 4,
  4, 2, 4, 8, 8, 2, 4,
  8, 8, 2.666666, 8, 4, 4, 2, 4,

  8, 8, 2, 8, 8, 8, 8, 2, 4,
  8, 8, 1.6, 8, 8, 8, 2, 4,
  8, 8, 8, 2, 8, 8, 8, 2, 4,
  8, 8, 1.6, 8, 8, 8, 2, 4,

  8, 8, 2, 8, 8, 8, 8, 2, 4,
  8, 8, 1.6, 8, 8, 8, 2, 4,
  8, 8, 8, 2, 8, 8, 8, 2, 4,
  8, 8, 1, 4, 4, 8, 2.666, 1.5, 4,

  8, 8, 1.666, 8, 8, 8, 8, 1.666, 4,
  8, 8, 1.666, 8, 8, 8, 1.666, 8,
  8, 8, 8, 2, 8, 8, 8, 2, 4,
  8, 8, 1, 4, 4, 8, 2.666, 2, 4,
};

void setup() {
  pinMode(humanHotSensor, INPUT);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(key_pin, INPUT);
  strip.begin();
}
void song_play()
{
  for (int thisNote = 0; thisNote < 500; thisNote++)
  {
    int noteDuration = 2000 / noteDurations[thisNote];
    tone(buzzer_pin, song[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration + 50;
    delay(noteDuration);
    noTone(buzzer_pin);
  }
}
void loop() {
    
  humanHotState = digitalRead(humanHotSensor);

  if (humanHotState){
    song_play();
    strip.setPixelColor(0, strip.Color(255, 0, 0));
    strip.show();
  }
  else{
    noTone(buzzer_pin);
    strip.setPixelColor(0, strip.Color(0, 255, 0));
    strip.show();
  
}
  }

