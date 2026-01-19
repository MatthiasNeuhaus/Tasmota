/*
  user_config_override.h - Optimiert für ESP32 mit 16MB Flash
  
  Für Olimex ESP32-POE mit SML Stromzähler-Auslesen
  Basierend auf ottelo's Anleitung und Scripts
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// Nur für Custom-Build aktivieren
#ifdef FIRMWARE_TASMOTA32_16MB_SML

#warning **** user_config_override.h: Custom Build für 16MB ESP32 SML ****

/*******************************************************************************
 * GRUNDLEGENDE EINSTELLUNGEN
 ******************************************************************************/

// Zeitzone für Deutschland
#undef APP_TIMEZONE
#define APP_TIMEZONE             99

/*******************************************************************************
 * SCRIPT & SML AKTIVIERUNG (KERNFEATURES)
 ******************************************************************************/

// WICHTIG: Rules deaktivieren, Script aktivieren
#undef USE_RULES
#ifndef USE_SCRIPT
#define USE_SCRIPT
#endif

// SML Smart Meter Interface aktivieren
#ifndef USE_SML_M
#define USE_SML_M
#endif

/*******************************************************************************
 * SCRIPT FEATURES - Alle für ottelo's Google Chart Scripts benötigten
 ******************************************************************************/

#ifndef USE_SCRIPT_WEB_DISPLAY
#define USE_SCRIPT_WEB_DISPLAY
#endif

#ifndef USE_SCRIPT_JSON_EXPORT
#define USE_SCRIPT_JSON_EXPORT
#endif

#ifndef USE_SCRIPT_SUB_COMMAND
#define USE_SCRIPT_SUB_COMMAND
#endif

#ifndef USE_SCRIPT_STATUS
#define USE_SCRIPT_STATUS
#endif

#ifndef SCRIPT_POWER_SECTION
#define SCRIPT_POWER_SECTION
#endif

#ifndef SUPPORT_MQTT_EVENT
#define SUPPORT_MQTT_EVENT
#endif

#ifndef SUPPORT_IF_STATEMENT
#define SUPPORT_IF_STATEMENT
#endif

// Größere Variablen-Limits
#undef MAXFILT
#define MAXFILT                  16

#undef SCRIPT_MAXSSIZE
#define SCRIPT_MAXSSIZE          254

/*******************************************************************************
 * FILESYSTEM - 16MB FLASH OPTIMAL NUTZEN
 ******************************************************************************/

#ifndef USE_UFILESYS
#define USE_UFILESYS
#endif

#undef UFSYS_SIZE
#define UFSYS_SIZE               16384

#undef SCRIPT_FATFS
#define SCRIPT_FATFS             -1

/*******************************************************************************
 * MQTT SETTINGS
 ******************************************************************************/

#undef MQTT_EVENT_MSIZE
#define MQTT_EVENT_MSIZE         512

#undef MQTT_EVENT_JSIZE
#define MQTT_EVENT_JSIZE         800

/*******************************************************************************
 * NICHT BENÖTIGTE FEATURES DEAKTIVIEREN - Spart Flash & RAM
 ******************************************************************************/

#ifdef USE_KNX
#undef USE_KNX
#endif

#ifdef USE_ZIGBEE
#undef USE_ZIGBEE
#endif

#ifdef USE_BLE_ESP32
#undef USE_BLE_ESP32
#endif

#ifdef USE_MI_ESP32
#undef USE_MI_ESP32
#endif

#ifdef USE_IR_REMOTE
#undef USE_IR_REMOTE
#endif

#ifdef USE_IR_RECEIVE
#undef USE_IR_RECEIVE
#endif

#ifdef USE_WEBCAM
#undef USE_WEBCAM
#endif

#ifdef USE_LVGL
#undef USE_LVGL
#endif

#endif  // FIRMWARE_TASMOTA32_16MB_SML

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password
// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS     MY_IP                // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY        MY_GW                // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS            MY_DNS               // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

#ifdef MY_DNS2
#undef  WIFI_DNS2
#define WIFI_DNS2           MY_DNS2              // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!!
*/

#ifdef DFIRMWARE_BLUETOOTH
// Enable BLE
#ifndef USE_BLE_ESP32
#define USE_BLE_ESP32                 // (ESP32 only) Add support for ESP32 as a BLE-bridge (+9k2 mem, +292k flash)
#endif
#endif

#endif  // _USER_CONFIG_OVERRIDE_H_