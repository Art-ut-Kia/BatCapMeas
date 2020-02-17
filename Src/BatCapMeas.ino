/**
 * BatCapMeas.ino: Permits to measure the capacity, in [A x h], of a LiPo battery
 */

#define ledPin  13 // LED (shows current mode)
#define gndPin  A0 // forced to OUTPUT, LOW to act as ground
#define ctrlPin A1 // digital output that control the battery load (HIGH = load activated)
#define measPin A2 // analog input that measures the battery voltage

#define periodMinutes 5  // one sample each 5 minute => 42 hours autonomy (1500mAh with 100 Ohms load)

int sample[500];
int i = 0;
bool discharge = true;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin,  OUTPUT); digitalWrite(ledPin,  LOW);
    pinMode(gndPin,  OUTPUT); digitalWrite(gndPin,  LOW); // ground
    pinMode(ctrlPin, OUTPUT); digitalWrite(ctrlPin, LOW); // battery loading control

    bool start = false;
    Serial.print("hit 'G' key to start discharge sequence: ");
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
//  delay(periodMinutes * 60000);
    delay(1000);
}
