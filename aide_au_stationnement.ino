#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define USONIC_DIV 58.0
#define MEASURE_SAMPLE_DELAY 5
#define MEASURE_SAMPLES 15
#define MEASURE_DELAY 15
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int GND1 = 12;
int GND2 = 11;
int GND3 = 10;
int GND4 = 9;
int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;
int j;
int num;
int buzzer = 13;
void setup()
{
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  delay(MEASURE_DELAY);
  long distance = measure() / 10;
  j = distance;
  Serial.println(distance);

  num = j;
  dig1 = num / 1000;
  num = num - (dig1 * 1000);
  dig2 = num / 100;
  num = num - (dig2 * 100);
  dig3 = num / 10;
  dig4 = num - (dig3 * 10);
  if (distance < 40 && distance >= 21) {
    digitalWrite( buzzer , millis() / 50 % 2 );  // fait clignoter la led avec le modulo de millis() de 2, soit 1 ou 0
    Serial.println(distance);
  }
  if (distance <= 20) {
    digitalWrite( buzzer , HIGH );
    Serial.println(distance);
  }
  if (distance > 40) {
    digitalWrite(buzzer, LOW);
  }

  for (int y = 1; y <= 100; y++)
  {

    if (j >= 1000)
    {
      digitalWrite( GND4, HIGH);    //digit 4
      DisplayNumber(dig4);
      delay(4);
      digitalWrite( GND4, LOW);

      digitalWrite( GND3, HIGH);    //digit 3
      DisplayNumber(dig3);
      delay(4);
      digitalWrite( GND3, LOW);

      digitalWrite( GND2, HIGH);   //digit 2
      DisplayNumber(dig2);
      delay(4);
      digitalWrite( GND2, LOW);

      digitalWrite( GND1, HIGH);   //digit 1
      DisplayNumber(dig1);
      delay(4);
      digitalWrite( GND1, LOW);
    }
    else if  (j >= 100)
    {
      digitalWrite( GND4, HIGH);    //digit 4
      DisplayNumber(dig4);
      delay(4);
      digitalWrite( GND4, LOW);

      digitalWrite( GND3, HIGH);    //digit 3
      DisplayNumber(dig3);
      delay(4);
      digitalWrite( GND3, LOW);

      digitalWrite( GND2, HIGH);   //digit 2
      DisplayNumber(dig2);
      delay(4);
      digitalWrite( GND2, LOW);

      digitalWrite( GND1, LOW);   //digit 1
      DisplayNumber(dig1);
      delay(4);
      digitalWrite( GND1, LOW);
    }
    else if  (j >= 10)
    {
      digitalWrite( GND4, HIGH);    //digit 4
      DisplayNumber(dig4);
      delay(4);
      digitalWrite( GND4, LOW);

      digitalWrite( GND3, HIGH);    //digit 3
      DisplayNumber(dig3);
      delay(4);
      digitalWrite( GND3, LOW);

      digitalWrite( GND2, LOW);   //digit 2
      DisplayNumber(dig2);
      delay(4);
      digitalWrite( GND2, LOW);

      digitalWrite( GND1, LOW);   //digit 1
      DisplayNumber(dig1);
      delay(4);
      digitalWrite( GND1, LOW);
    }

    else if  (j >= 0)
    {
      digitalWrite( GND4, HIGH);    //digit 4
      DisplayNumber(dig4);
      delay(4);
      digitalWrite( GND4, LOW);

      digitalWrite( GND3, LOW);    //digit 3
      DisplayNumber(dig3);
      delay(4);
      digitalWrite( GND3, LOW);

      digitalWrite( GND2, LOW);   //digit 2
      DisplayNumber(dig2);
      delay(4);
      digitalWrite( GND2, LOW);

      digitalWrite( GND1, LOW);   //digit 1
      DisplayNumber(dig1);
      delay(4);
      digitalWrite( GND1, LOW);
    }
  }
}
long measure()
{
  long measureSum = 0;
  for (int i = 0; i < MEASURE_SAMPLES; i++)
  {
    delay(MEASURE_SAMPLE_DELAY);
    measureSum += singleMeasurement();
  }
  return measureSum / MEASURE_SAMPLES;
}

long singleMeasurement()
{
  long duration = 0;
  // Measure: Put up Trigger...
  digitalWrite(TRIGGER_PIN, HIGH);
  // ... wait for 11 µs ...
  delayMicroseconds(11);
  // ... put the trigger down ...
  digitalWrite(TRIGGER_PIN, LOW);
  // ... and wait for the echo ...
  duration = pulseIn(ECHO_PIN, HIGH);
  return (long) (((float) duration / USONIC_DIV) * 10.0);
}

void DisplayNumber(int x) {
  switch (x) {
    case 0: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
  }
}

void zero()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, HIGH);
}

void one()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void two()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, HIGH);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, HIGH);
  digitalWrite( g, LOW);
}

void three()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, LOW);
}

void four()
{
  digitalWrite( a, HIGH);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void five()
{
  digitalWrite( a, LOW);
  digitalWrite( b, HIGH);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void six()
{
  digitalWrite( a, LOW);
  digitalWrite( b, HIGH);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void seven()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, HIGH);
  digitalWrite( e, HIGH);
  digitalWrite( f, HIGH);
  digitalWrite( g, HIGH);
}

void eight()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, LOW);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}

void nine()
{
  digitalWrite( a, LOW);
  digitalWrite( b, LOW);
  digitalWrite( c, LOW);
  digitalWrite( d, LOW);
  digitalWrite( e, HIGH);
  digitalWrite( f, LOW);
  digitalWrite( g, LOW);
}
