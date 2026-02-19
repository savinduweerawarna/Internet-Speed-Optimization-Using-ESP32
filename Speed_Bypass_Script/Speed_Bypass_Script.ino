#include <WiFi.h>
#include "esp_system.h"
#include "esp_task_wdt.h"

const char* ssid     = "XXXXXXXX";
const char* password = "XXXXXXXX";

const char* server = "XXXXXXXX";
const int   port   = XXXXXXXX;

#define WIFI_LED    21
#define SERVER_LED  4

WiFiClient client;

const unsigned long RESET_INTERVAL_MS = 1UL * 60UL * 1000UL; 
unsigned long bootMs = 0;

void connectToWiFi() {
  digitalWrite(WIFI_LED, LOW);
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);

  WiFi.disconnect(true);
  delay(100);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("✅ WiFi connected");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  digitalWrite(WIFI_LED, HIGH);
}

void connectToServer() {
  Serial.print("Connecting TCP to ");
  Serial.print(server);
  Serial.print(":");
  Serial.println(port);

  digitalWrite(SERVER_LED, LOW);

  while (!client.connect(server, port)) {
    digitalWrite(SERVER_LED, HIGH); delay(80);
    digitalWrite(SERVER_LED, LOW);  delay(80);
    delay(10);
  }

  Serial.println("✅ TCP connected");
  digitalWrite(SERVER_LED, HIGH);
}

void resetViaWatchdog() {
  Serial.println("⏱️ Interval reached → Disconnect WiFi + Watchdog reset");

  // Close TCP and drop WiFi
  client.stop();
  digitalWrite(SERVER_LED, LOW);

  WiFi.disconnect(true);
  digitalWrite(WIFI_LED, LOW);

  delay(200);

#if ESP_IDF_VERSION_MAJOR >= 5 //ESP32 soft restart to refresh the connection
  esp_task_wdt_config_t cfg = {};
  cfg.timeout_ms = 1000;
  cfg.idle_core_mask = (1 << 0) | (1 << 1);
  cfg.trigger_panic = true;
  esp_task_wdt_init(&cfg);
#else
  esp_task_wdt_init(1, true);        
#endif

  esp_task_wdt_add(NULL);

  while (true) {
  }
}

void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(WIFI_LED, OUTPUT);
  pinMode(SERVER_LED, OUTPUT);
  digitalWrite(WIFI_LED, LOW);
  digitalWrite(SERVER_LED, LOW);

  bootMs = millis();

  connectToWiFi();
  connectToServer();
}

void loop() {
  const unsigned long now = millis();

  if (now - bootMs >= RESET_INTERVAL_MS) {
    resetViaWatchdog();
  }

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("⚠️ WiFi dropped → reconnecting");
    digitalWrite(WIFI_LED, LOW);
    digitalWrite(SERVER_LED, LOW);
    client.stop();

    connectToWiFi();
    connectToServer();
  }

  if (!client.connected()) {
    Serial.println("⚠️ TCP dropped → reconnecting");
    digitalWrite(SERVER_LED, LOW);
    client.stop();
    connectToServer();
  }
  delay(1000);
}
