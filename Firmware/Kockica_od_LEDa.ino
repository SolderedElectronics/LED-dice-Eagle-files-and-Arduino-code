/*
 * Arduino code for DIY learn-to-solder kit Electronic dice
 * Find it here: https://e-radionica.com/en/kokica-od-leda-set-za-ucenje-lemljenja.html
 * Code by e-radionica.com
 */

int LED[] = {0, 1, 2, 3};
int pushButton = 4;
int randomBr;

void setup() {
  for(int i = 0; i < 4; i++)
  {
    pinMode(LED[i], OUTPUT);
  }
  pinMode(pushButton, INPUT);

  randomSeed(analogRead(0));
}

void loop() {
  if(digitalRead(pushButton) == HIGH)
  {
    randomBr = random(1,6);
    animation();
    toogleLEDs(randomBr);
  }
  else
  {
    delay(200);
    turnOffAllLEDs();
  }

}

void toogleLEDs(int broj)
{
  switch(broj)
  {
    case 1:
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], LOW);
      digitalWrite(LED[3], LOW);
    break;

    case 2:
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[3], LOW);
    break;

    case 3:
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], LOW);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[3], LOW);
    break;

    case 4:
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[3], LOW);
    break;

    case 5:
      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[3], LOW);
    break;

    case 6:
      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], HIGH);
      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[3], HIGH);
    break;
  }
  delay(4000);
}

void animation()
{
  for(int i = 0; i < 10; i++)
  {
    int jk = random(0,3);
    digitalWrite(jk, HIGH);
    delay(40);
    digitalWrite(jk, LOW);
  }
}

void turnOffAllLEDs()
{
  for(int i = 0; i < 4; i++)
  {
    digitalWrite(LED[i], LOW);
  }
}
