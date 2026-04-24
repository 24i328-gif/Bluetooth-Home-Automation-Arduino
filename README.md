# Secure Autonomous Microgrid Negotiator ⚡🛡️

### Project Overview
An intelligent Embedded Systems project that moves beyond simple home automation. It implements a **Priority-Based Load Shedding** algorithm to prevent grid failure and a **Security Handshake** to prevent unauthorized access.

## 🚀 Novel Features
1. **Security Gateway:** Prevents 'Bluejacking' by requiring a 4-character alphabetic password (`OPEN`) before initializing GPIO pins.
2. **Computational Load Management:** Simulates a real-time power meter to prevent exceeding a 1500W safety limit.
3. **Autonomous Pre-emption:** A unique "negotiation" logic where the system automatically deactivates Non-Essential loads to accommodate Essential (High-Priority) requests.

## 🛠️ Tech Stack
* **Microcontroller:** Arduino Nano (ATmega328P)
* **Communication:** UART Serial / Bluetooth (HC-05)
* **Simulation:** Proteus Design Suite 8.x
* **Language:** Embedded C++

## 🎮 Control Commands
| Command | Action | Priority | Power |
| :--- | :--- | :--- | :--- |
| `OPEN` | Unlock System | N/A | 0W |
| `L_ON` | Non-Essential ON | Low | 500W |
| `H_ON` | Essential ON | High | 1200W |
| `0` | Master Reset | N/A | 0W |

## 📉 Logic Flow
When `H_ON` is requested while `L_ON` is active, the system calculates:
`500W + 1200W = 1700W`. 
Since `1700W > 1500W (Limit)`, the system executes an **Autonomous Pre-emption** of the Low Priority load.
