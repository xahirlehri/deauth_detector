/*
  Deauth Detector for ESP32 TTGO T-Display
  Developer: Zahir
  Purpose: Detect Wi-Fi deauthentication (DoS) attacks using ESP32 in promiscuous mode
  License: For educational and authorized security auditing use only.
*/

#include <WiFi.h>
#include <TFT_eSPI.h>
#include <esp_wifi.h>

// TFT Display
TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(0, 0);
  tft.println("Deauth Detector");
  tft.setTextSize(1);
  tft.setCursor(0, 25);
  tft.println("Developed by Zahir Lehri");
  delay(1500);

  // WiFi promiscuous mode setup
  WiFi.mode(WIFI_MODE_STA);
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_promiscuous_rx_cb(&sniffer_callback);
  esp_wifi_set_promiscuous(true); // Start sniffing
}

void loop() {
  // Idle display update
  tft.setTextSize(1);
  tft.setCursor(0, 45);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.println("Monitoring for Deauth...");
  delay(2000); // Passive loop
}

// Callback for sniffed packets
void sniffer_callback(void* buf, wifi_promiscuous_pkt_type_t type) {
  if (type != WIFI_PKT_MGMT) return;

  wifi_promiscuous_pkt_t* p = (wifi_promiscuous_pkt_t*)buf;
  uint8_t* payload = p->payload;

  if (payload[0] == 0xC0) { // Deauth frame
    Serial.println("Deauth packet detected!");

    // Show alert on screen
    tft.fillScreen(TFT_RED);
    tft.setTextColor(TFT_WHITE, TFT_RED);
    tft.setTextSize(2);
    tft.setCursor(0, 50);
    tft.println("⚠ Deauth Attack!");
    delay(3000);

    // Reset display
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(0, 0);
    tft.println("Deauth Detector");
    tft.setTextSize(1);
    tft.setCursor(0, 25);
    tft.println("Developed by Zahir Lehri");
  }
}
