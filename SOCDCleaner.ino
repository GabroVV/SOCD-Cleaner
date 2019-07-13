const uint8_t leftIN = 26;
const uint8_t rightIN = 24;
const uint8_t upIN = 22;
const uint8_t downIN = 28;

const uint8_t leftOUT = 42;
const uint8_t rightOUT = 38;
const uint8_t upOUT = 44;
const uint8_t downOUT = 40;

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
  Serial.begin(9600);
}

void loop() {
  leftRead = digitalRead(leftIN);
  rightRead = digitalRead(rightIN);
  upRead = digitalRead(upIN);
  downRead = digitalRead(downIN);

  if (leftRead == LOW)
  {
    if (rightRead == HIGH)
    {
      Serial.println("Lewo");
      digitalWrite(rightOUT, HIGH);
      digitalWrite(leftOUT, LOW);
    }
    else
    {
      digitalWrite(rightOUT, HIGH);
      digitalWrite(leftOUT, HIGH);
      Serial.println("Neutral");
    }
  }
  else if (rightRead == LOW)
  {
    Serial.println("Prawo");
    digitalWrite(leftOUT, HIGH);
    digitalWrite(rightOUT, LOW);
  }
  else
  {
    digitalWrite(rightOUT, HIGH);
    digitalWrite(leftOUT, HIGH);
  }

  if (upRead == LOW)
  {
    Serial.println("Gora");
    digitalWrite(downOUT, HIGH);
    digitalWrite(upOUT, LOW);
  }
  else if (downRead == LOW)
  {
    {
      Serial.println("DOL");
      digitalWrite(downOUT, LOW);
      digitalWrite(upOUT, HIGH);
    }
  }
  else
  {
    digitalWrite(upOUT, HIGH);
    digitalWrite(downOUT, HIGH);
  }
}
