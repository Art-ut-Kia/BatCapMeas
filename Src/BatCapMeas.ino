/**
 * BatCapMeas.ino: Measures the capacity, in [A x h], of a Li-ion battery
 * author: Jean-Paul PETILLON
 * to be improved: average some samples to reduce noise
 */

#define ledPin  13 // LED (shows current mode)
#define gndPin  A0 // forced to OUTPUT, LOW to act as a ground pin
#define ctrlPin A1 // digital output that controls the battery load (HIGH = load activated)
#define measPin A2 // analog input that measures the battery voltage

#define periodMinutes 5  // one sample each 5 minutes

int sample[500]; // buffer to memorize samples (not used so long)
int i = 0;
bool discharge = true;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin,  OUTPUT); digitalWrite(ledPin,  LOW); // to witness the load status
    pinMode(gndPin,  OUTPUT); digitalWrite(gndPin,  LOW); // ground
    pinMode(ctrlPin, OUTPUT); digitalWrite(ctrlPin, LOW); // battery loading control

    bool start = false;
    Serial.print("hit 'g' key to start the discharge process: ");
    while (!start) {
        while (!Serial.available());
        start = (Serial.read()=='g');
    }
    digitalWrite(ctrlPin, HIGH);
    digitalWrite(ledPin,  HIGH);
    Serial.println("done.");
}

void loop() {
    int m = analogRead(measPin);
    if (i<500) sample[i++] = m;
   
    float v = 5.0/1024.0 * m; // in volts
    if (v<=3.0 && discharge) {
        discharge = false;
        digitalWrite(ctrlPin, LOW);
        digitalWrite(ledPin,  LOW);
    }
    Serial.print(discharge ? "discharging: " : "no load:     ");
    Serial.println(v);
    delay(periodMinutes * 60000);
}
