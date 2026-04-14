/* * PROJECT: Full Control Home Automation
 * COMMANDS: 
 * [1] Bulb ON  | [3] Bulb OFF
 * [2] Fan ON   | [4] Fan OFF
 * [9] BOTH ON  | [0] BOTH OFF
 */

const int RELAY_BULB = 7; 
const int RELAY_FAN  = 8; 

void setup() {
  Serial.begin(9600); 
  pinMode(RELAY_BULB, OUTPUT);
  pinMode(RELAY_FAN, OUTPUT);

  // Start with everything OFF
  digitalWrite(RELAY_BULB, LOW);
  digitalWrite(RELAY_FAN, LOW);

  Serial.println("--- SYSTEM READY: MULTI-DEVICE CONTROL ---");
}

void loop() {
  if (Serial.available() > 0) {
    char cmd = Serial.read(); 

    // Filter out extra characters
    if (cmd == '\n' || cmd == '\r' || cmd == ' ') return;

    switch (cmd) {
      // INDIVIDUAL CONTROL: BULB
      case '1': 
        digitalWrite(RELAY_BULB, HIGH);
        Serial.println("STATUS: BULB IS ON");
        break;
      case '3': 
        digitalWrite(RELAY_BULB, LOW);
        Serial.println("STATUS: BULB IS OFF");
        break;

      // INDIVIDUAL CONTROL: FAN
      case '2': 
        digitalWrite(RELAY_FAN, HIGH);
        Serial.println("STATUS: FAN IS ON");
        break;
      case '4': 
        digitalWrite(RELAY_FAN, LOW);
        Serial.println("STATUS: FAN IS OFF");
        break;

      // GROUP CONTROL
      case '9': 
        digitalWrite(RELAY_BULB, HIGH);
        digitalWrite(RELAY_FAN, HIGH);
        Serial.println("STATUS: ALL DEVICES ON");
        break;
      case '0': 
        digitalWrite(RELAY_BULB, LOW);
        digitalWrite(RELAY_FAN, LOW);
        Serial.println("STATUS: ALL DEVICES OFF");
        break;

      default:
        Serial.println("SYSTEM: Invalid Command Received");
        break;
    }
  }
}
