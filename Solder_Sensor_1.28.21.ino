#define ledPin D4
#define sensorPin D1
#define relayPin D2

unsigned long previousMillis = 0;
const long interval = 3000;
int serialAlert = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (digitalRead(sensorPin) == LOW) {
      if (serialAlert == 0) {
        Serial.println("Objected Detected");
        serialAlert = 1;
      }
      digitalWrite(ledPin, HIGH);
      digitalWrite(relayPin, LOW);
    }

    else {
      if (serialAlert == 1) {
        Serial.println("No Objected Detected");
        serialAlert = 0;
      }
      digitalWrite(ledPin, LOW);
      digitalWrite(relayPin, HIGH);
    }

  } //end millis loop

}
