# Bluetooth-Home-Automation-Arduino
A Proteus-simulated Home Automation System using Arduino and HC-05 Bluetooth module.
# Mobile Controlled Home Automation System using Bluetooth 🏠📱

A Bluetooth-based home automation system using an **Arduino Uno/Nano** interfaced with an **HC-05 Bluetooth module** and **Relay modules** to enable wireless control of electrical appliances through a smartphone.

---

## 📝 Abstract
This project presents a cost-effective solution to improve convenience and reduce energy wastage by allowing remote switching of devices. By replacing manual wall switches with a smartphone interface, the system provides an essential tool for elderly people and modern energy-efficient homes.

## 🚀 Key Features
- **Wireless Control:** Range of ~10m using Bluetooth HC-05.
- **Multi-Device Support:** Independent control for a Bulb and a Fan.
- **Group Commands:** "Master OFF" and "All ON" functions for quick control.
- **Serial Feedback:** Real-time status updates sent back to the mobile app.
- **Proteus Simulated:** Fully verified circuit design before hardware assembly.

---

## 🕹️ Control Commands
| Command | Action | Status Feedback |
|:---:|:---:|:---|
| `1` | **Bulb ON** | `STATUS: BULB IS ON` |
| `3` | **Bulb OFF** | `STATUS: BULB IS OFF` |
| `2` | **Fan ON** | `STATUS: FAN IS ON` |
| `4` | **Fan OFF** | `STATUS: FAN IS OFF` |
| `9` | **ALL ON** | `STATUS: ALL DEVICES ON` |
| `0` | **ALL OFF** | `STATUS: ALL DEVICES OFF` |

---

## 🛠️ Hardware Components
| Component | Specification | Purpose |
|:---|:---|:---|
| **Arduino Nano/Uno** | ATmega328P | Central Controller |
| **HC-05** | Serial UART, 2.4 GHz | Wireless Communication |
| **Relay Module** | 5V Coil, 10A Contact | Switching AC Loads |
| **COMPIM** | Proteus Component | Physical Serial Port Interface |
| **Power Supply** | 5V DC Regulated | System Power |

---

## 📂 Project Structure
- `/Code`: Contains the `.ino` file for Arduino.
- `/Simulation`: Contains the Proteus `.pdsprj` file.
- `/Docs`: Problem statement and Abstract details.

## 🔧 Installation & Setup
1. **Simulation:** Open the Proteus file, ensure the Arduino is loaded with the `.hex` file.
2. **Serial Bridge:** Use a Virtual Serial Port Driver to pair COM ports (e.g., COM7 ↔ COM8).
3. **Bluetooth:** Connect the HC-05 to the Arduino (TX to RX, RX to TX).
4. **Execution:** Use a Serial Monitor or "Arduino Bluetooth Controller" app to send commands.

## 🏁 Conclusion
This system provides a reliable and efficient wireless home automation solution, successfully improving convenience and saving energy in a residential environment.

