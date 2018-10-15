int encoder0PinA = 10;
int encoder0PinB = 11;

int val;
int prev_val = 0;
int t, cur_t;
int resolution = 1000;
int rpm;
int prev_rpm = 0;

void setup()
{
  pinMode (encoder0PinA, INPUT_PULLUP);
  pinMode (encoder0PinB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(10), encoder_rpm, CHANGE);
  
  Serial.begin(9600);
}

void encoder_rpm()
{
  detachInterrupt(0);
  val = digitalRead(encoder0PinA);
  if (prev_val == 0 && val == 1)
  { 
    cur_t = micros();
    rpm = ((1000000 * 60 / (cur_t - t)));
    t = micros();
  }
  prev_val = val;
  attachInterrupt(digitalPinToInterrupt(0), encoder_rpm, CHANGE);
}

void loop()
{
  
  if (prev_rpm != rpm)
  {
    Serial.println(rpm);
  }
  prev_rpm = rpm;
  
  //Serial.println(rpm);
  delay(100);
}
