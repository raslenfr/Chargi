<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8" />
  <meta name="viewport" content="width=device-width,initial-scale=1" />
  <title>⚡ CHARGI — Smart Electric Car Charging Station</title>
  <style>
    :root{
      --bg:#0f1724; /* dark background */
      --card:#0b1220;
      --muted:#94a3b8;
      --accent:#81e54f;
      --accent2:#f7d948;
      --glass: rgba(255,255,255,0.03);
      --card-padding:22px;
      --radius:14px;
      --mono: "Segoe UI Mono", "Roboto Mono", Menlo, monospace;
      --ui: "Inter", "Segoe UI", Roboto, Arial, sans-serif;
    }
    *{box-sizing:border-box}
    html,body{height:100%;margin:0;font-family:var(--ui);background:linear-gradient(180deg,#071022 0%, #071224 65%);color:#e6eef6}
    .container{max-width:980px;margin:36px auto;padding:20px}
    .card{background:linear-gradient(180deg, rgba(255,255,255,0.02), rgba(255,255,255,0.01)); border:1px solid rgba(255,255,255,0.03); border-radius:var(--radius); padding:var(--card-padding); box-shadow:0 6px 24px rgba(2,6,23,0.6)}
    header{display:flex;gap:18px;align-items:center}
    .logo{
      width:86px;height:86px;border-radius:12px;display:flex;align-items:center;justify-content:center;
      background:linear-gradient(135deg,var(--accent),var(--accent2));font-size:34px;font-weight:700;color:#072218;
      box-shadow:0 6px 18px rgba(129,229,79,0.12);
    }
    h1{margin:0;font-size:26px}
    p.lead{color:var(--muted);margin-top:6px}
    .grid{display:grid;grid-template-columns:1fr 340px;gap:18px;margin-top:18px}
    .full{grid-column:1 / -1}
    table{width:100%;border-collapse:collapse;margin-top:10px}
    th,td{padding:10px 12px;text-align:left;border-bottom:1px dashed rgba(255,255,255,0.03)}
    th{color:var(--muted);font-weight:600}
    .badge{display:inline-block;background:rgba(255,255,255,0.04);padding:6px 10px;border-radius:999px;font-weight:600;color:var(--accent);margin-right:8px}
    .section-title{display:flex;align-items:center;gap:12px;margin:8px 0 12px}
    .components{background:var(--glass);padding:14px;border-radius:12px}
    .component-line{display:flex;gap:12px;padding:8px 0;border-bottom:1px solid rgba(255,255,255,0.02)}
    .component-line:last-child{border-bottom:0}
    .component-name{min-width:220px;font-weight:700;color:#dffbe2}
    .component-role{flex:1;color:var(--muted)}
    .summary{background:linear-gradient(180deg, rgba(255,255,255,0.01), rgba(255,255,255,0.005));padding:14px;border-radius:10px;border:1px solid rgba(255,255,255,0.02);color:#d9f7d8}
    footer{margin-top:18px;color:var(--muted);font-size:14px}
    code{font-family:var(--mono);background:rgba(255,255,255,0.02);padding:6px 8px;border-radius:6px;color:#cce7c8}
    .btn{display:inline-block;background:var(--accent);color:#062216;padding:10px 14px;border-radius:10px;font-weight:700;text-decoration:none;margin-top:8px}
    @media (max-width:900px){ .grid{grid-template-columns:1fr} .logo{width:64px;height:64px;font-size:28px} }
  </style>
</head>
<body>
  <div class="container">
    <div class="card">
      <header>
        <div class="logo">⚡</div>
        <div>
          <h1>⚡ CHARGI — Smart Electric Car Charging Station</h1>
          <p class="lead">C++ (Qt) desktop app + Arduino-powered 3D maquette for managing EV charging, maintenance, cars, clients & employees.</p>
        </div>
      </header>

      <div class="grid" style="margin-top:18px">
        <div>
          <section class="card" style="padding:18px">
            <div class="section-title"><span class="badge">🧠</span><strong>Project Overview</strong></div>
            <p style="color:var(--muted)">CHARGI is a 2nd-year engineering project combining IoT, embedded systems and desktop software to deliver an eco-friendly charging station management tool. Highlights:</p>
            <ul style="color:var(--muted);margin:8px 0 0 18px">
              <li>Simplifies station management and employee-client communication</li>
              <li>Automates offers, loyalty cards, notifications</li>
              <li>Integrates Arduino sensors & actuators with a Qt desktop interface</li>
            </ul>
          </section>

          <section class="card" style="margin-top:14px;padding:18px">
            <div class="section-title"><span class="badge">🧩</span><strong>Main Modules</strong></div>
            <table>
              <thead><tr><th>Module</th><th>Description</th><th>Key Features</th></tr></thead>
              <tbody>
                <tr><td>🚙 Car Management</td><td>Manage vehicles</td><td>Add/Edit/Delete/View, history, PDF export, stats</td></tr>
                <tr><td>👨‍💼 Employee Management</td><td>Handle staff</td><td>Auth, CRUD, PDF exports, sorting</td></tr>
                <tr><td>👥 Client Management</td><td>Client profiles & loyalty</td><td>Loyalty cards, Happy-Hour, stats</td></tr>
                <tr><td>🔧 Maintenance Management</td><td>Two garages (repair & wash)</td><td>Automated barriers, status LEDs, employee control</td></tr>
                <tr><td>🔋 EV Charging Point Mgmt</td><td>Charging point control</td><td>Live status, solar recharge mode, Happy-Hour</td></tr>
              </tbody>
            </table>
          </section>

          <section class="card" style="margin-top:14px;padding:18px">
            <div class="section-title"><span class="badge">⚙️</span><strong>Technical Stack</strong></div>
            <p style="color:var(--muted);margin:0">C++ / Qt • Oracle SQL • Arduino (Uno) • Sensors, servos, LCDs • 3D maquette (solar + garages)</p>
          </section>
        </div>

        <aside>
          <div class="card" style="padding:14px">
            <strong>Team</strong>
            <ul style="color:var(--muted);margin:8px 0 0 16px">
              <li>Raslen Ferchichi</li>
              <li>Fares Ben Ammar</li>
              <li>Alaa Bouchakour</li>
              <li>Youssef Ben Arous</li>
              <li>Jasser Ben Yahmadi</li>
            </ul>
            <div style="margin-top:12px">
              <strong>Contact</strong>
              <p style="color:var(--muted);margin:6px 0 0">📧 <code>raslenferchihi1@gmail.com</code><br/>📞 +216 29775523</p>
            </div>
            <a class="btn" href="#" onclick="navigator.clipboard?.writeText('https://github.com/yourusername/Chargi')">Copy GitHub link</a>
          </div>
        </aside>
      </div>

      <!-- IoT & Arduino Integration -->
      <div class="full" style="margin-top:18px">
        <div class="section-title"><span class="badge">🌍</span><strong>IoT & Arduino Integration</strong></div>
        <div class="components card" aria-hidden="false">
          <div style="margin-bottom:8px;color:var(--muted)">The physical 3D maquette connects the C++ Qt desktop app with Arduino components to simulate a real-world smart electric car charging station. Each element interacts with sensors, motors and displays to automate tasks and ensure efficiency.</div>

          <!-- Components list -->
          <div class="component-line">
            <div class="component-name">🚗 Infrared (IR) Sensor</div>
            <div class="component-role">Detects car entry — Used with: <strong>Buzzer</strong> + <strong>Servo Motor (Barrier)</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">🔊 Buzzer</div>
            <div class="component-role">Sound indicator — Used with: <strong>IR Sensor</strong>, <strong>Charging LEDs</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">⚙️ Servo Motor (Barrier Gate)</div>
            <div class="component-role">Controls vehicle entry/exit — Used with: <strong>IR Sensor</strong> + <strong>LCD</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">🪪 RFID Reader (RC522)</div>
            <div class="component-role">Identifies driver/car — Used with: <strong>RFID Card</strong> + <strong>LCD</strong> + <strong>C++ Database</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">💡 Red & Green LEDs</div>
            <div class="component-role">Charging state indicators — Used with: <strong>Buzzer</strong> + <strong>LCD</strong> + <strong>Charging Port</strong> (Red = charging, Green = finished)</div>
          </div>

          <div class="component-line">
            <div class="component-name">📟 LCD Display (16x2 / 20x4)</div>
            <div class="component-role">Shows charge %, cost, duration, EV point battery status — Used with: <strong>RFID</strong>, <strong>Temp Sensor</strong>, <strong>Solar Battery</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">🔘 Push Button</div>
            <div class="component-role">Start/stop charging — Used with: <strong>LCD</strong> + <strong>C++ Interface</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">🌡️ Temperature Sensor (DHT11 / LM35)</div>
            <div class="component-role">Monitors ambient temperature — Used with: <strong>LCD Display</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">☀️ Light Sensors (LDR x2)</div>
            <div class="component-role">Detect sunlight direction/intensity — Used with: <strong>Dual Servo Motors</strong> for solar rotation</div>
          </div>

          <div class="component-line">
            <div class="component-name">⚙️ Dual Servo Motors (Solar Rotation)</div>
            <div class="component-role">Rotate the solar panel (e.g., 20°/30° left or right) — Used with: <strong>LDRs</strong> + <strong>Solar Panel</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">🔋 Rechargeable Battery (12V / Power Bank)</div>
            <div class="component-role">Stores solar energy — Used with: <strong>Solar Panel</strong> + <strong>EV Charging Point</strong></div>
          </div>

          <!-- Maintenance components -->
          <div style="margin-top:12px;font-weight:700;color:#dffbe2">🧰 Maintenance Management Components</div>

          <div class="component-line">
            <div class="component-name">🪪 RFID Reader (RC522)</div>
            <div class="component-role">Identifies client car before maintenance access — Used with: <strong>Servo Motor</strong> + <strong>LCD</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">⚙️ Servo Motor (Entrance Barrier - Maintenance)</div>
            <div class="component-role">Controls access to both garages — Used with: <strong>RFID</strong> + <strong>IR Sensor</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">🚦 IR Sensor (Garage Entry Detection)</div>
            <div class="component-role">Detects car movement into maintenance path — Used with: <strong>Servo Motor (Barrier)</strong> + <strong>Buzzer</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">🔘 Push Button (Employee Control)</div>
            <div class="component-role">Manual exit barrier control — Used with: <strong>Servo Motor</strong> + <strong>LCD</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">⚙️ Servo Motors (x2 - Garage Barriers)</div>
            <div class="component-role">Control maintenance & car wash garage doors — Used with: <strong>Push Button</strong> + <strong>IR Sensor</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">💧 Water Sprinkler Motor (Car Wash)</div>
            <div class="component-role">Activates water spray for cleaning — Used with: <strong>Button</strong> + <strong>C++ Interface</strong></div>
          </div>

          <div class="component-line">
            <div class="component-name">💡 LED Indicators (Garage Status)</div>
            <div class="component-role">Show garage availability (red = occupied / green = free) — Used with: <strong>C++ Interface</strong> + <strong>LCD</strong></div>
          </div>
        </div>

        <!-- Summaries -->
        <div style="margin-top:14px" class="summary">
          <h3 style="margin-top:0">☀️ Solar System Integration Summary</h3>
          <p style="margin:6px 0 0">
            The CHARGI solar module maximizes solar energy capture. Two LDR light sensors measure sunlight intensity on each side; the Arduino compares readings and instructs the dual servo motors to rotate the solar panel (for example, 20°–30° left or right) so it faces the brightest direction. The temperature sensor (DHT11) provides weather data to the LCD for visualization. Collected energy is stored in the rechargeable battery (12V / power bank). When stored energy drops below a threshold (≈20–30%), the system notifies the LCD and disables EV access by closing the servo barrier; the EV charging point then recharges from solar/battery until restored, at which point the red LED turns off and access resumes.
          </p>
        </div>

        <div style="margin-top:12px" class="summary">
          <h3 style="margin-top:0">🧰 Maintenance System Integration Summary</h3>
          <p style="margin:6px 0 0">
            The maintenance system controls two garages (repair & car wash). When a vehicle arrives, the RFID reader validates the client and triggers the entrance servo barrier to open briefly. An IR sensor confirms entry and closes the barrier after the car passes. Inside, each garage has its own servo barrier and LED status indicator. For the car wash, an employee uses a push button to start the sprinkler motor (washing), and then presses the button again to open the exit barrier when the service completes. The maintenance garage follows the same entry/exit flow. This logic is synchronized with the C++ desktop app so the operator sees live statuses on the LCD and in the management interface.
          </p>
        </div>
      </div>

      <footer style="margin-top:16px">
        <div style="display:flex;justify-content:space-between;align-items:center;gap:12px;flex-wrap:wrap">
          <div style="color:var(--muted)">🌱 CHARGI promotes renewable energy and efficient station management</div>
          <div style="color:var(--muted)">Contact: <code>raslenferchihi1@gmail.com</code> • +216 29775523</div>
        </div>
      </footer>
    </div>
  </div>
</body>
</html>
