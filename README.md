⚡ CHARGI — Smart Electric Car Charging Station

🚗 Chargi is a C++ Qt-based desktop application connected to an Arduino-powered 3D prototype of an electric vehicle (EV) charging station.
It provides a complete management system for electric car charging operations — from clients to cars, maintenance, employees, and charging points.

🧠 Project Overview

Chargi was created as a 2nd-year engineering project combining IoT, embedded systems, and software engineering.
The goal is to build an intelligent, eco-friendly charging station system that:

Simplifies station management 🧾

Improves communication between employees and clients 💬

Automates offers, loyalty cards, and notifications 🎁

Integrates real-time Arduino sensors and displays 🧩

🧩 Main Modules

The project includes five management modules, each linked to Arduino elements and database logic:

Module	Description	Features
🚙 Car Management	Manage vehicles connected to the station	Add / Edit / Delete / View cars, vehicle history, charging duration display, PDF export, statistics
👨‍💼 Employee Management	Handle employee records and access	Add / Edit / Delete / View employees, authentication, prime membership, sorting, PDF export
👥 Client Management	Manage client data and loyalty system	Add / Edit / Delete / View clients, offer loyalty cards, Happy Hour alerts, statistics
🔧 Maintenance Management	Manage two garages (car wash & repair)	Add / Edit / Delete / View records, automated garage barriers, status LEDs, and RFID control
🔋 EV Charging Point Management	Control and monitor charging points	Add / Edit / Delete / View stations, live updates, solar recharge mode, Happy Hour feature
⚙️ Technical Stack
Category	Tools / Technologies
💻 Desktop App	C++ / Qt Framework
🔌 Hardware	Arduino Uno, sensors, motors, LCD screens
🧮 Database	Oracle SQL
🎨 UI Design	Qt Designer, Slidesgo visuals
🔐 Security	User authentication via CIN & password
🌞 Prototype	3D maquette powered by solar tracking and Arduino sensors
🌍 IoT & Arduino Integration

The physical 3D maquette connects the C++ Qt desktop app with Arduino components to simulate a real-world smart electric car charging station.
Each element of the station interacts with sensors, motors, and displays to automate tasks and ensure efficiency.

⚙️ Components Overview

🚗 Infrared (IR) Sensor — Detects car entry | Used with: Buzzer + Servo Motor (Barrier)

Detects when a vehicle enters the station area. When triggered, it sends a signal to the buzzer to beep and to the servo motor to lift the entry barrier.

🔊 Buzzer — Sound indicator | Used with: IR Sensor, Charging LEDs

Emits sound when a car enters or when charging sessions start or end.

⚙️ Servo Motor (Barrier Gate) — Controls vehicle entry/exit | Used with: IR Sensor + LCD

Opens or closes the physical barrier when a car arrives or when charging is complete.

🪪 RFID Reader (RC522 module) — Identifies driver and car information | Used with: RFID Card + LCD + C++ Database

Reads the driver’s ID card to retrieve client info, balance, and vehicle details from the database.

💡 Red and Green LEDs — Visual indicators of charging state | Used with: Buzzer + LCD + Charging Port

🔴 Red = Charging in progress.
🟢 Green = Charging complete.
When charging starts, the red LED turns on; when done, it turns off and the green LED blinks.

📟 LCD Display (16x2 or 20x4) — Displays system information | Used with: RFID, Temperature Sensor, Solar Battery, Charging Station

Shows car charge percentage, charging cost, duration, and current EV station battery status.

🔘 Push Button — Starts or stops charging | Used with: LCD + C++ Interface

The user presses this button to begin or stop the charging session after choosing the desired charge percentage.

🌡️ Temperature Sensor (DHT11 or LM35) — Monitors ambient temperature | Used with: LCD Display

Measures the environment’s temperature and sends data to the LCD for display purposes near the solar system.

☀️ Light Sensors (LDR Modules x2) — Detect sunlight direction and intensity | Used with: Servo Motors (Solar Panel Rotation)

Compare light intensity on both sides to determine where the sunlight is strongest.

⚙️ Dual Servo Motors (Solar Rotation Motors) — Rotate the solar panel | Used with: Light Sensors + Solar Panel

Receive directional data from the light sensors and rotate the solar panel accordingly (e.g., 20° left or right) to maximize light capture.

🔋 Rechargeable Battery (Power Bank / 12V Battery) — Stores collected solar energy | Used with: Solar Panel + EV Charging Point

Stores energy from the solar panel and supplies power to the EV station when sunlight is insufficient.

🧰 Maintenance Management Components

🪪 RFID Reader (RC522) — Identifies client car before maintenance access | Used with: Servo Motor + LCD Display

Ensures that only authorized cars enter the maintenance area after ID validation.

⚙️ Servo Motor (Entrance Barrier – Maintenance Area) — Controls access to maintenance garages | Used with: RFID Reader + IR Sensor

Lifts the barrier once the RFID verifies the client, then automatically closes after a few seconds.

🚦 IR Sensor (Garage Entry Detection) — Detects car movement into the maintenance path | Used with: Servo Motor (Barrier) + Buzzer

Detects when a car passes the entrance or exit to trigger barrier movements and safety signals.

🔘 Push Button (Employee Control) — Manual control for garage exit barrier | Used with: Servo Motor + LCD Display

Allows the employee to open the exit barrier once maintenance or washing is completed.

⚙️ Servo Motors (x2 — Garage Barriers) — Control both the maintenance and car wash garage doors | Used with: Push Button + IR Sensor

Automatically close after a car enters and reopen upon manual employee command after the service is finished.

💧 Water Sprinkler Motor (Car Wash) — Activates water spray for cleaning | Used with: Button + C++ Interface

Turns on during washing sessions, simulating automatic car cleaning.

💡 LED Indicators (Garage Status) — Show garage availability | Used with: C++ Interface + LCD Display

Indicate whether a garage is occupied (red) or free (green).

☀️ Solar System Integration Summary

The solar system in CHARGI is a smart, self-adjusting module designed to maximize solar energy capture and power the EV charging stations efficiently. Two LDR light sensors continuously monitor sunlight intensity from both sides. Based on their readings, the Arduino microcontroller calculates the optimal direction and instructs the dual servo motors to rotate the solar panel — for example, by 20° or 30° left or right — to face the brightest spot. The temperature sensor (DHT11) provides environmental data to the LCD display, giving users real-time weather information. The captured energy is stored in a rechargeable 12V battery, which powers the EV charging point when solar input is low. When the stored power drops below 20–30%, the system automatically alerts the LCD display and disables the EV access by closing the servo barrier, allowing recharging to occur until the battery reaches 100%. Once full, the red LED turns off, and the barrier opens again for cars to resume charging sessions.

🧰 Maintenance System Integration Summary

The maintenance management system controls two separate garages: one for mechanical repairs and one for car washing. As a car approaches the maintenance area, the RFID reader identifies the client’s vehicle and sends a signal to the servo motor to lift the entrance barrier. An IR sensor confirms the car’s entry and automatically triggers the barrier to close after a few seconds, ensuring safety. Inside the area, the car can enter either garage — each equipped with its own servo motor barrier and LED indicators to show whether the garage is occupied or available.

In the car wash garage, the employee activates a push button to start the washing process, turning on the sprinkler motor that simulates the car-cleaning cycle. Once finished, the employee presses the same button to reopen the exit barrier, allowing the car to leave while the LED switches back to green.

The same process applies to the maintenance garage, where the system ensures organized entry, service, and exit flow. Together, these components create an automated, efficient, and environmentally responsible maintenance management system fully synchronized with the C++ desktop application.

🌱 Sustainable Impact

Chargi supports sustainability and smart resource management by:

Using renewable solar energy ☀️

Promoting water efficiency 🚿

Reducing pollution through EV adoption 🌍

Encouraging smart automation for cleaner cities 🌿

👩‍💻 Team

👨‍🔧 Project Contributors

Raslen Ferchichi

Fares Ben Ammar

Alaa Bouchakour

Youssef Ben Arous

Jasser Ben Yahmadi

🎓 2A18 Engineering Students

