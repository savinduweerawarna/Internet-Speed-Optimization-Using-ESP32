# Internet-Speed-Optimization-Using-ESP32-
Built an ESP32-based “speed-bypass” automation to reduce Sri Lankan ISP peak-time throttling by keeping optimized TCP connections alive to selected endpoints, which helped maintain better throughput during congested hours, without needing a PC running 24/7.

📡 Internet Speed Optimization using ESP32 <br>
An IoT-based lightweight network optimization solution designed to mitigate ISP peak-time throttling by autonomously maintaining optimized TCP sessions using an ESP32 microcontroller. <br>

📌 Overview <br>
During peak hours, ISP bandwidth throttling caused significant speed reductions despite having a stable connection. Traditional solutions like VPN tunneling and packet obfuscation were tested but proved impractical for daily use. <br>
Through network analysis, it was identified that maintaining persistent connections to selected endpoints helped stabilize throughput. This project automates that concept using an ESP32 for low-power, continuous operation. <br>

🧠 Concept <br>
Instead of running a full PC-based script 24/7, a microcontroller: <br>
  Establishes lightweight TCP sessions <br>
  Maintains persistent connectivity <br>
  Periodically refreshes connections <br>
  Operates independently without user intervention <br>
This enables network-wide performance stabilization during high-traffic periods. <br>

🛠 Hardware Requirements <br>
ESP32 Development Board <br>
5V USB Power Supply <br>
Power Consumption: ~500mW <br>

⚙️ System Architecture <br>

Phase 1 – Software Prototype <br>
Custom lightweight TCP session script <br>
Required continuous PC uptime <br>
Effective but inefficient for long-term use <br>

Phase 2 – ESP32 Implementation <br>

Embedded TCP handler <br>
Autonomous network management <br>
Plug-and-play deployment <br>
Ultra-low power operation <br>

✨ Key Features <br>

🔹 Autonomous operation (set-and-forget) <br>
🔹 Ultra-low power consumption <br>
🔹 Periodic connection refresh <br>
🔹 Automatic session maintenance <br>
🔹 Network-wide performance benefits <br>
🔹 No dependency on always-on PC <br>

🧪 Testing & Validation <br>

A Python-based proxy server was configured during development to: <br>

Monitor traffic behavior <br>
Analyze session persistence <br>
Validate throughput stability <br>
Visualize connection patterns <br>

📈 Results <br>

✅ Stable speeds during peak hours <br>
✅ 99% reduction in power usage compared to PC-based solution <br>
✅ Zero maintenance after deployment <br>
✅ Benefits all connected devices simultaneously <br>

🚀 Impact <br>

This project demonstrates how embedded systems and networking concepts can be combined to create energy-efficient, automated infrastructure solutions using minimal hardware. 
