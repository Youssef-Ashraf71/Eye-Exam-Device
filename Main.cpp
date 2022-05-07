const int ldrA = A0;
const int ldrE = A1;
const int ldrF = A2;
const int ldrD = A3;
const int ldrC = A4;
const int ldrB = A5;

unsigned long myTime;
int score = 0;

char tests[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'A'};

long long i, j;

void setup() {
  //  Void setup function will only run once, after each powerup or reset of the Arduino board.
  Serial.begin(9600);
  pinMode(ldrA, INPUT);
  pinMode(ldrB, INPUT);
  pinMode(ldrC, INPUT);
  pinMode(ldrD, INPUT);
  pinMode(ldrE, INPUT);
  pinMode(ldrF, INPUT);
}

void loop() {
  // Void loop is ran again and again and contains main code.

  for (i = 0; i < 7; i++) {
    myTime = millis();
    Serial.print("Target at ");
    Serial.println(tests[i]);
    delay(100);

    while (millis() - myTime < 7000) {
      int inA = analogRead(ldrA);
      int inB = analogRead(ldrB);
      int inC = analogRead(ldrC);
      int inD = analogRead(ldrD);
      int inE = analogRead(ldrE);
      int inF = analogRead(ldrF);

      if (inA > 600 && tests[i] == 'A') {
        score++;
        Serial.println("You hit A correctly!");
        break;
      }

      if (inB > 600 && tests[i] == 'B') {
        score++;
        Serial.println("You hit B correctly!");
        break;
      }

      if (inC > 600 && tests[i] == 'C') {
        score++;
        Serial.println("You hit C correctly!");
        break;
      }

      if (inD > 600 && tests[i] == 'D') {
        score++;
        Serial.println("You hit D correctly!");
        break;
      }

      if (inE > 600 && tests[i] == 'E') {
        score++;
        Serial.println("You hit E correctly!");
        break;
      }

      if (inF > 600 && tests[i] == 'F') {
        score++;
        Serial.println("You hit F correctly!");
        break;
      }

    }
    delay(3000);
  }

  Serial.print("Patient's score is ");
  Serial.print(((double)score/(double)7)*100);
  Serial.println("%");
  delay(1000000000);
}

