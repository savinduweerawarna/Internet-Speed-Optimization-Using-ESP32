# Internet-Speed-Optimization-Using-ESP32-
Built an ESP32-based “speed-bypass” automation to reduce Sri Lankan ISP peak-time throttling by keeping optimized TCP connections alive to selected endpoints, which helped maintain better throughput during congested hours, without needing a PC running 24/7.

📡 Internet Speed Optimization using ESP32
An IoT-based lightweight network optimization solution designed to mitigate ISP peak-time throttling by autonomously maintaining optimized TCP sessions using an ESP32 microcontroller.

📌 Overview
During peak hours, ISP bandwidth throttling caused significant speed reductions despite having a stable connection. Traditional solutions like VPN tunneling and packet obfuscation were tested but proved impractical for daily use.
Through network analysis, it was identified that maintaining persistent connections to selected endpoints helped stabilize throughput. This project automates that concept using an ESP32 for low-power, continuous operation.

🧠 Concept

Instead of running a full PC-based script 24/7, a microcontroller:
Establishes lightweight TCP sessions
Maintains persistent connectivity
Periodically refreshes connections
Operates independently without user intervention
This enables network-wide performance stabilization during high-traffic periods.

🛠 Hardware Requirements

ESP32 Development Board
5V USB Power Supply
Power Consumption: ~500mW

⚙️ System Architecture

Phase 1 – Software Prototype
Custom lightweight TCP session script
Required continuous PC uptime
Effective but inefficient for long-term use

Phase 2 – ESP32 Implementation

Embedded TCP handler
Autonomous network management
Plug-and-play deployment
Ultra-low power operation

✨ Key Features

🔹 Autonomous operation (set-and-forget)
🔹 Ultra-low power consumption
🔹 Periodic connection refresh
🔹 Automatic session maintenance
🔹 Network-wide performance benefits
🔹 No dependency on always-on PC

🧪 Testing & Validation

A Python-based proxy server was configured during development to:

Monitor traffic behavior
Analyze session persistence
Validate throughput stability
Visualize connection patterns

📈 Results

✅ Stable speeds during peak hours
✅ 99% reduction in power usage compared to PC-based solution
✅ Zero maintenance after deployment
✅ Benefits all connected devices simultaneously

🚀 Impact

This project demonstrates how embedded systems and networking concepts can be combined to create energy-efficient, automated infrastructure solutions using minimal hardware.
