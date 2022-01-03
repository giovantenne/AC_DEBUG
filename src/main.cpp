#include <WebServer.h>
#include <AutoConnect.h>

WebServer Server;
AutoConnect Portal(Server);
AutoConnectConfig Config;

void setup() {
  Serial.begin(115200);
  Config.autoReconnect = true;
  Config.apid = "MySSID";
  Portal.config(Config);
  if (Portal.begin()) {
    Serial.println("Connected to WiFi");
  }
}

void loop() {
  Portal.handleClient();
}

