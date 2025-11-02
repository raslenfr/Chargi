# ⚡ CHARGI — Smart Electric Car Charging Station

## 🚗 Project Overview

CHARGI is a comprehensive C++ Qt-based desktop application integrated with an Arduino-powered 3D prototype of an electric vehicle (EV) charging station. This intelligent system combines IoT, embedded systems, and software engineering to create an eco-friendly charging station management solution.

<table>
<thead>
<tr>
<th>Feature</th>
<th>Description</th>
<th>Benefit</th>
</tr>
</thead>
<tbody>
<tr>
<td>🧾 Station Management</td>
<td>Complete management system for EV charging operations</td>
<td>Simplified administration and control</td>
</tr>
<tr>
<td>💬 Client-Employee Communication</td>
<td>Integrated communication system</td>
<td>Improved service coordination</td>
</tr>
<tr>
<td>🎁 Automated Offers & Loyalty</td>
<td>Smart loyalty cards and notification system</td>
<td>Enhanced customer engagement</td>
</tr>
<tr>
<td>🧩 Real-time IoT Integration</td>
<td>Arduino sensors and displays</td>
<td>Live monitoring and control</td>
</tr>
<tr>
<td>🌞 Solar-Powered</td>
<td>Renewable energy integration</td>
<td>Eco-friendly operation</td>
</tr>
</tbody>
</table>

## 🧩 Main Modules

<table>
<thead>
<tr>
<th>Module</th>
<th>Icon</th>
<th>Description</th>
<th>Key Features</th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>Car Management</strong></td>
<td>🚙</td>
<td>Manage vehicles connected to the station</td>
<td>Add/Edit/Delete/View cars, vehicle history, charging duration display, PDF export, statistics</td>
</tr>
<tr>
<td><strong>Employee Management</strong></td>
<td>👨‍💼</td>
<td>Handle employee records and access</td>
<td>Add/Edit/Delete/View employees, authentication, prime membership, sorting, PDF export</td>
</tr>
<tr>
<td><strong>Client Management</strong></td>
<td>👥</td>
<td>Manage client data and loyalty system</td>
<td>Add/Edit/Delete/View clients, offer loyalty cards, Happy Hour alerts, statistics</td>
</tr>
<tr>
<td><strong>Maintenance Management</strong></td>
<td>🔧</td>
<td>Manage two garages (car wash & repair)</td>
<td>Add/Edit/Delete/View records, automated garage barriers, status LEDs, RFID control</td>
</tr>
<tr>
<td><strong>EV Charging Point Management</strong></td>
<td>🔋</td>
<td>Control and monitor charging points</td>
<td>Add/Edit/Delete/View stations, live updates, solar recharge mode, Happy Hour feature</td>
</tr>
</tbody>
</table>

## ⚙️ Technical Stack

<table>
<thead>
<tr>
<th>Category</th>
<th>Technology</th>
<th>Purpose</th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>Desktop Application</strong></td>
<td>C++ / Qt Framework</td>
<td>Main application development and UI</td>
</tr>
<tr>
<td><strong>Hardware Platform</strong></td>
<td>Arduino Uno, sensors, motors, LCD screens</td>
<td>Physical prototype and IoT integration</td>
</tr>
<tr>
<td><strong>Database</strong></td>
<td>Oracle SQL</td>
<td>Data storage and management</td>
</tr>
<tr>
<td><strong>UI Design</strong></td>
<td>Qt Designer, Slidesgo visuals</td>
<td>User interface design and graphics</td>
</tr>
<tr>
<td><strong>Security</strong></td>
<td>User authentication via CIN & password</td>
<td>System access control</td>
</tr>
<tr>
<td><strong>Prototype</strong></td>
<td>3D maquette with solar tracking</td>
<td>Physical demonstration model</td>
</tr>
</tbody>
</table>

## 🌍 IoT & Arduino Integration

### Core Station Components

<table>
<thead>
<tr>
<th>Component</th>
<th>Icon</th>
<th>Function</th>
<th>Integration</th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>Infrared (IR) Sensor</strong></td>
<td>🚗</td>
<td>Detects car entry</td>
<td>Buzzer + Servo Motor (Barrier)</td>
</tr>
<tr>
<td><strong>Buzzer</strong></td>
<td>🔊</td>
<td>Sound indicator</td>
<td>IR Sensor, Charging LEDs</td>
</tr>
<tr>
<td><strong>Servo Motor (Barrier Gate)</strong></td>
<td>⚙️</td>
<td>Controls vehicle entry/exit</td>
<td>IR Sensor + LCD</td>
</tr>
<tr>
<td><strong>RFID Reader (RC522)</strong></td>
<td>🪪</td>
<td>Identifies driver and car information</td>
<td>RFID Card + LCD + C++ Database</td>
</tr>
<tr>
<td><strong>Red & Green LEDs</strong></td>
<td>💡</td>
<td>Visual charging indicators</td>
<td>Buzzer + LCD + Charging Port</td>
</tr>
<tr>
<td><strong>LCD Display</strong></td>
<td>📟</td>
<td>Displays system information</td>
<td>RFID, Temperature Sensor, Solar Battery</td>
</tr>
<tr>
<td><strong>Push Button</strong></td>
<td>🔘</td>
<td>Starts/stops charging</td>
<td>LCD + C++ Interface</td>
</tr>
<tr>
<td><strong>Temperature Sensor</strong></td>
<td>🌡️</td>
<td>Monitors ambient temperature</td>
<td>LCD Display</td>
</tr>
<tr>
<td><strong>Light Sensors (LDR)</strong></td>
<td>☀️</td>
<td>Detects sunlight direction and intensity</td>
<td>Servo Motors (Solar Panel Rotation)</td>
</tr>
<tr>
<td><strong>Dual Servo Motors</strong></td>
<td>⚙️</td>
<td>Rotates solar panel</td>
<td>Light Sensors + Solar Panel</td>
</tr>
<tr>
<td><strong>Rechargeable Battery</strong></td>
<td>🔋</td>
<td>Stores collected solar energy</td>
<td>Solar Panel + EV Charging Point</td>
</tr>
</tbody>
</table>

### LED Status Indicators

<table>
<thead>
<tr>
<th>LED Color</th>
<th>Status</th>
<th>Action</th>
</tr>
</thead>
<tbody>
<tr>
<td>🔴 Red LED</td>
<td>Charging in progress</td>
<td>Turns on when charging starts</td>
</tr>
<tr>
<td>🟢 Green LED</td>
<td>Charging complete</td>
<td>Blinks when charging finishes</td>
</tr>
</tbody>
</table>

## 🧰 Maintenance Management System

### Maintenance Components

<table>
<thead>
<tr>
<th>Component</th>
<th>Icon</th>
<th>Function</th>
<th>Integration</th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>RFID Reader</strong></td>
<td>🪪</td>
<td>Identifies client car before maintenance access</td>
<td>Servo Motor + LCD Display</td>
</tr>
<tr>
<td><strong>Servo Motor (Entrance Barrier)</strong></td>
<td>⚙️</td>
<td>Controls access to maintenance garages</td>
<td>RFID Reader + IR Sensor</td>
</tr>
<tr>
<td><strong>IR Sensor</strong></td>
<td>🚦</td>
<td>Detects car movement into maintenance path</td>
<td>Servo Motor + Buzzer</td>
</tr>
<tr>
<td><strong>Push Button (Employee Control)</strong></td>
<td>🔘</td>
<td>Manual control for garage exit barrier</td>
<td>Servo Motor + LCD Display</td>
</tr>
<tr>
<td><strong>Servo Motors (x2 Garage Barriers)</strong></td>
<td>⚙️</td>
<td>Control maintenance and car wash garage doors</td>
<td>Push Button + IR Sensor</td>
</tr>
<tr>
<td><strong>Water Sprinkler Motor</strong></td>
<td>💧</td>
<td>Activates water spray for cleaning</td>
<td>Button + C++ Interface</td>
</tr>
<tr>
<td><strong>LED Indicators (Garage Status)</strong></td>
<td>💡</td>
<td>Show garage availability</td>
<td>C++ Interface + LCD Display</td>
</tr>
</tbody>
</table>

### Garage Status Indicators

<table>
<thead>
<tr>
<th>LED Color</th>
<th>Garage Status</th>
<th>Meaning</th>
</tr>
</thead>
<tbody>
<tr>
<td>🔴 Red LED</td>
<td>Occupied</td>
<td>Garage currently in use</td>
</tr>
<tr>
<td>🟢 Green LED</td>
<td>Free</td>
<td>Garage available for service</td>
</tr>
</tbody>
</table>

## ☀️ Solar System Integration

### Solar Tracking Process

<table>
<thead>
<tr>
<th>Step</th>
<th>Component</th>
<th>Action</th>
<th>Result</th>
</tr>
</thead>
<tbody>
<tr>
<td>1</td>
<td>Light Sensors (LDR x2)</td>
<td>Monitor sunlight intensity from both sides</td>
<td>Determine brightest direction</td>
</tr>
<tr>
<td>2</td>
<td>Arduino Microcontroller</td>
<td>Calculates optimal rotation direction</td>
<td>Determines panel movement (20°-30°)</td>
</tr>
<tr>
<td>3</td>
<td>Dual Servo Motors</td>
<td>Rotate solar panel toward sunlight</td>
<td>Maximizes energy capture</td>
</tr>
<tr>
<td>4</td>
<td>Temperature Sensor (DHT11)</td>
<td>Provides environmental data</td>
<td>Real-time weather information on LCD</td>
</tr>
<tr>
<td>5</td>
<td>Rechargeable Battery</td>
<td>Stores captured solar energy</td>
<td>Powers EV station when sunlight is low</td>
</tr>
</tbody>
</table>

### Battery Management System

<table>
<thead>
<tr>
<th>Battery Level</th>
<th>System Action</th>
<th>User Impact</th>
</tr>
</thead>
<tbody>
<tr>
<td>Below 20-30%</td>
<td>LCD alert, servo barrier closes</td>
<td>Charging disabled for recharging</td>
</tr>
<tr>
<td>Charging to 100%</td>
<td>Continuous monitoring</td>
<td>System prepares for reactivation</td>
</tr>
<tr>
<td>100% Full</td>
<td>Red LED off, barrier opens</td>
<td>Charging services resume</td>
</tr>
</tbody>
</table>

## 🔄 Maintenance Workflow

### Car Entry Process

<table>
<thead>
<tr>
<th>Step</th>
<th>Component</th>
<th>Action</th>
<th>Next Step</th>
</tr>
</thead>
<tbody>
<tr>
<td>1</td>
<td>RFID Reader</td>
<td>Identifies client vehicle</td>
<td>Sends verification signal</td>
</tr>
<tr>
<td>2</td>
<td>Servo Motor</td>
<td>Lifts entrance barrier</td>
<td>Allows vehicle entry</td>
</tr>
<tr>
<td>3</td>
<td>IR Sensor</td>
<td>Confirms car entry</td>
<td>Triggers barrier closure</td>
</tr>
<tr>
<td>4</td>
<td>Servo Motor</td>
<td>Closes barrier after entry</td>
<td>Ensures security</td>
</tr>
</tbody>
</table>

### Service Execution

<table>
<thead>
<tr>
<th>Garage Type</th>
<th>Service</th>
<th>Activation</th>
<th>Completion</th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>Car Wash</strong></td>
<td>Automatic cleaning</td>
<td>Employee push button</td>
<td>Sprinkler motor activates</td>
</tr>
<tr>
<td><strong>Maintenance</strong></td>
<td>Mechanical repairs</td>
<td>Vehicle entry</td>
<td>Service completion</td>
</tr>
<tr>
<td><strong>Both Garages</strong></td>
<td>Exit process</td>
<td>Employee push button</td>
<td>Barrier opens, LED turns green</td>
</tr>
</tbody>
</table>

## 🌱 Sustainable Impact

<table>
<thead>
<tr>
<th>Sustainability Feature</th>
<th>Icon</th>
<th>Environmental Benefit</th>
<th>Impact Level</th>
</tr>
</thead>
<tbody>
<tr>
<td>Renewable Solar Energy</td>
<td>☀️</td>
<td>Reduces grid electricity consumption</td>
<td>High</td>
</tr>
<tr>
<td>Water Efficiency</td>
<td>🚿</td>
<td>Optimized water usage in car wash</td>
<td>Medium</td>
</tr>
<tr>
<td>EV Adoption Support</td>
<td>🌍</td>
<td>Reduces fossil fuel dependency</td>
<td>High</td>
</tr>
<tr>
<td>Smart Automation</td>
<td>🌿</td>
<td>Energy-efficient operations</td>
<td>Medium</td>
</tr>
<tr>
<td>Pollution Reduction</td>
<td>💨</td>
<td>Lowers carbon emissions</td>
<td>High</td>
</tr>
</tbody>
</table>

## 👩‍💻 Development Team

<table>
<thead>
<tr>
<th>Role</th>
<th>Team Member</th>
<th>Contribution Area</th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>Project Lead</strong></td>
<td>Raslen Ferchichi</td>
<td>System Architecture & Integration</td>
</tr>
<tr>
<td><strong>Hardware Specialist</strong></td>
<td>Fares Ben Ammar</td>
<td>Arduino & Sensor Integration</td>
</tr>
<tr>
<td><strong>Software Developer</strong></td>
<td>Alaa Bouchakour</td>
<td>C++ Qt Application Development</td>
</tr>
<tr>
<td><strong>Database Engineer</strong></td>
<td>Youssef Ben Arous</td>
<td>Oracle SQL Database Design</td>
</tr>
<tr>
<td><strong>UI/UX Designer</strong></td>
<td>Jasser Ben Yahmadi</td>
<td>User Interface & Experience Design</td>
</tr>
</tbody>
</table>

### 🎓 Academic Information
<table>
<thead>
<tr>
<th>Institution</th>
<th>Program</th>
<th>Year</th>
<th>Project Type</th>
</tr>
</thead>
<tbody>
<tr>
<td>Engineering School</td>
<td>2A18 Engineering Program</td>
<td>2nd Year</td>
<td>Comprehensive Engineering Project</td>
</tr>
</tbody>
</table>

## 🎯 Key Innovations

<table>
<thead>
<tr>
<th>Innovation Area</th>
<th>Technology</th>
<th>Unique Feature</th>
</tr>
</thead>
<tbody>
<tr>
<td><strong>Smart Solar Tracking</strong></td>
<td>LDR Sensors + Servo Motors</td>
<td>Automatic panel rotation for maximum efficiency</td>
</tr>
<tr>
<td><strong>Integrated Maintenance</strong></td>
<td>RFID + Barrier System</td>
<td>Seamless car wash and repair services</td>
</tr>
<tr>
<td><strong>Real-time Monitoring</strong></td>
<td>LCD Display + Sensors</td>
<td>Live system status and environmental data</td>
</tr>
<tr>
<td><strong>Automated Access Control</strong></td>
<td>RFID + Servo Barriers</td>
<td>Secure, automated vehicle entry/exit</td>
</tr>
<tr>
<td><strong>Energy Management</strong></td>
<td>Battery + Solar System</td>
<td>Smart power allocation and conservation</td>
</tr>
</tbody>
</table>

---

**Built with innovation and sustainability in mind for the future of electric mobility** ⚡🌱
