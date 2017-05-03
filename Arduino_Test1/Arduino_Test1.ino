int brightness = 0;
int fadeAmount = 10;
int delayDuration = 30;
int ledPins[] = {3, 4, 5, 6, 7};
int arrLength = sizeof(ledPins) / sizeof(int);

void setup()  {
  for (int thisLed = 0; thisLed < arrLength; thisLed++)
  {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop()  {
  int thisLed = 0;
  while (thisLed < arrLength)
  {
    analogWrite(ledPins[thisLed], brightness);
    brightness = brightness + fadeAmount;
    if (brightness <= 0)
    {
      if (thisLed == arrLength - 1)
      {
        brightness = 0;
      }
      else
      {
        brightness = 255;
      }
      thisLed++;
    }
    else if (brightness >= 255)
    {
      if (thisLed == arrLength - 1)
      {
        brightness = 255;
      }
      else
      {
        brightness = 0;
      }
      thisLed++;
    }
    delay(delayDuration);
  }
  fadeAmount = -fadeAmount;

  int potValue = analogRead(A0);
  delayDuration = map(potValue, 0, 1023, 1, 50);
}
