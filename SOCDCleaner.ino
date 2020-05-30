//Controller button pins
const uint8_t leftIN = 9;
const uint8_t rightIN = 10;
const uint8_t upIN = 11;
const uint8_t downIN = 12;

//Output to other PCB pins
const uint8_t leftOUT = 6;
const uint8_t rightOUT = 8;
const uint8_t upOUT = 5;
const uint8_t downOUT = 7;

uint8_t leftRead;
uint8_t downRead;
uint8_t upRead;
uint8_t rightRead;

void setup() {
  pinMode(leftIN, INPUT_PULLUP);
  pinMode(rightIN, INPUT_PULLUP);
  pinMode(upIN, INPUT_PULLUP);
  pinMode(downIN, INPUT_PULLUP);
  pinMode(leftOUT, OUTPUT);
  pinMode(rightOUT, OUTPUT);
  pinMode(downOUT, OUTPUT);
  pinMode(upOUT, OUTPUT);
}

void loop() {
  leftRead = digitalRead(leftIN);
  rightRead = digitalRead(rightIN);
  upRead = digitalRead(upIN);
  downRead = digitalRead(downIN);
  
  //**********Horizontal inputs block**********
  if (leftRead == LOW)
  {
    if (rightRead == HIGH) //Left only
    {
      digitalWrite(rightOUT, HIGH);
      digitalWrite(leftOUT, LOW);
    }
    else //Right+Left = Neutral
    {
      digitalWrite(rightOUT, HIGH);
      digitalWrite(leftOUT, HIGH);
    }
  }
  else if (rightRead == LOW) //Right only
  {
    digitalWrite(leftOUT, HIGH);
    digitalWrite(rightOUT, LOW);
  }
  else  // No horizontal inputs
  {
    digitalWrite(rightOUT, HIGH);
    digitalWrite(leftOUT, HIGH);
  }
//**********Vertical inputs block**********
  if (upRead == LOW) // Up overrides down inputs
  {
    digitalWrite(downOUT, HIGH);
    digitalWrite(upOUT, LOW);
  }
  else if (downRead == LOW) // Down only
  {
    {
      digitalWrite(downOUT, LOW);
      digitalWrite(upOUT, HIGH);
    }
  }
  else  // No vertical inputs
  {
    digitalWrite(upOUT, HIGH);
    digitalWrite(downOUT, HIGH);
  }
}
