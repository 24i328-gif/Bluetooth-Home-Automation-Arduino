/* * PROJECT: Secure Autonomous Microgrid Negotiator
 * NOVELTY: Pre-emptive Priority Load Shedding + Security Gateway
 */

const int RELAY_LOW_PRIORITY = 7;  // Non-Essential (500W)
const int RELAY_HIGH_PRIORITY = 8; // Essential (1200W)
const int POWER_LIMIT = 1500;

int currentUsage = 0;
bool isLowOn = false;
bool isHighOn = false;
bool systemUnlocked = false;

String passkey = "OPEN"; 

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_LOW_PRIORITY, OUTPUT);
  pinMode(RELAY_HIGH_PRIORITY, OUTPUT);
  
  Serial.println("--- SYSTEM ENCRYPTED: ENTER KEY ---");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    // 1. SECURITY LAYER
    if (!systemUnlocked) {
      if (input == passkey) {
        systemUnlocked = true;
        Serial.println("ACCESS GRANTED. Microgrid Logic Initialized.");
      } else {
        Serial.println("SECURITY ALERT: Invalid Key.");
      }
      return;
    }

    // 2. CONTROL & NEGOTIATION LAYER
    
    // ACTION: Activate Non-Essential Load (500W)
    if (input == "L_ON") { 
      if (currentUsage + 500 <= POWER_LIMIT) {
        digitalWrite(RELAY_LOW_PRIORITY, HIGH);
        if (!isLowOn) currentUsage += 500;
        isLowOn = true;
        Serial.println("STATUS: Non-Essential Load Active (+500W)");
      } else {
        Serial.println("REJECTED: Power Budget Full. Cannot add load.");
      }
    }

    // ACTION: Activate Essential Load (1200W) - THE NEGOTIATOR
    else if (input == "H_ON") {
      // Logic: If adding 1200W breaks the limit, sacrifice the 500W load
      if (currentUsage + 1200 > POWER_LIMIT) {
        if (isLowOn) {
          digitalWrite(RELAY_LOW_PRIORITY, LOW);
          isLowOn = false;
          currentUsage -= 500;
          Serial.println("PRE-EMPTION: Dropping Non-Essential Load to protect grid!");
        }
      }

      if (currentUsage + 1200 <= POWER_LIMIT) {
        digitalWrite(RELAY_HIGH_PRIORITY, HIGH);
        if (!isHighOn) currentUsage += 1200;
        isHighOn = true;
        Serial.println("STATUS: Essential Load Active (+1200W)");
      } else {
        Serial.println("CRITICAL FAILURE: Even Essential Load exceeds Power Limit!");
      }
    }

    // ACTION: Turn OFF Essential Load
    else if (input == "H_OFF") {
      digitalWrite(RELAY_HIGH_PRIORITY, LOW);
      if (isHighOn) currentUsage -= 1200;
      isHighOn = false;
      Serial.println("STATUS: Essential Load Deactivated.");
    }

    // ACTION: Turn OFF Non-Essential Load
    else if (input == "L_OFF") {
      digitalWrite(RELAY_LOW_PRIORITY, LOW);
      if (isLowOn) currentUsage -= 500;
      isLowOn = false;
      Serial.println("STATUS: Non-Essential Load Deactivated.");
    }

    // ACTION: Master Shutdown & Relock
    else if (input == "0") {
      digitalWrite(RELAY_LOW_PRIORITY, LOW);
      digitalWrite(RELAY_HIGH_PRIORITY, LOW);
      currentUsage = 0; isLowOn = false; isHighOn = false;
      systemUnlocked = false;
      Serial.println("SYSTEM SHUTDOWN: Logic Relocked.");
    }

    Serial.print("GRID USAGE: "); Serial.print(currentUsage); Serial.println("W / 1500W");
  }
}
