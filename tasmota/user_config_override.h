/*
  user_config_override.h - Basierend auf ottelo's tasmota-sml-images
  
  Angepasst für ESP32 mit 16MB Flash (Olimex ESP32-POE)
  Original: https://github.com/ottelo9/tasmota-sml-images
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

#ifdef FIRMWARE_TASMOTA32_16MB_SML

#warning **** user_config_override.h: 16MB ESP32 SML Build (basierend auf ottelo) ****

/*******************************************************************************
 * (1) Unnötige Features deaktivieren
 ******************************************************************************/
#undef USE_DOMOTICZ
#undef USE_EMULATION_HUE
#undef USE_EMULATION_WEMO
#undef ROTARY_V1
#undef USE_SONOFF_RF
#undef USE_SONOFF_SC
#undef USE_TUYA_MCU
#undef USE_ARMTRONIX_DIMMERS
#undef USE_PS_16_DZ
#undef USE_SONOFF_IFAN
#undef USE_BUZZER
#undef USE_ARILUX_RF
#undef USE_SHUTTER
#undef USE_EXS_DIMMER
#undef USE_DEVICE_GROUPS
#undef USE_PWM_DIMMER
#undef USE_SONOFF_D1
#undef USE_SHELLY_DIMMER
#undef SHELLY_CMDS
#undef SHELLY_FW_UPGRADE
#undef USE_LIGHT
#undef USE_WS2812
#undef USE_MY92X1
#undef USE_SM16716
#undef USE_SM2135
#undef USE_SM2335
#undef USE_BP1658CJ
#undef USE_BP5758D
#undef USE_SONOFF_L1
#undef USE_ELECTRIQ_MOODL
#undef USE_LIGHT_PALETTE
#undef USE_LIGHT_VIRTUAL_CT
#undef USE_DGR_LIGHT_SEQUENCE
#undef USE_SERIAL_BRIDGE
#undef USE_ENERGY_DUMMY
#undef USE_PZEM004T
#undef USE_PZEM_AC
#undef USE_PZEM_DC
#undef USE_MCP39F501
#undef USE_IR_REMOTE
#undef GV_USE_ESPINFO
#undef USE_GPIO_VIEWER
#undef USE_ADC
#undef USE_NETWORK_LIGHT_SCHEMES
#undef USE_AUTOCONF
#undef USE_CSE7761

// BMP Sensor aktivieren (optional für Temperatur/Luftdruck)
#define USE_BMP

/*******************************************************************************
 * (2) Stack Size erhöhen
 ******************************************************************************/
#undef SET_ESP32_STACK_SIZE
#define SET_ESP32_STACK_SIZE (12 * 1024)

/*******************************************************************************
 * (3) Große Arrays und Variablen für ESP32
 ******************************************************************************/
#define SCRIPT_LARGE_VNBUFF
#define MAX_ARRAY_SIZE 2000

/*******************************************************************************
 * (4) Filesystem - 16MB Flash nutzen
 ******************************************************************************/
#define USE_SCRIPT_FATFS_EXT
#define USE_UFILESYS
#undef UFSYS_SIZE
#define UFSYS_SIZE 16384

/*******************************************************************************
 * (5) SML, Script, Google Chart Support
 ******************************************************************************/
#define USE_SCRIPT
#define USE_SML_M
#define USE_SML_CRC
#undef USE_RULES
#define USE_GOOGLE_CHARTS
#define LARGE_ARRAYS
#define USE_SCRIPT_WEB_DISPLAY
#define USE_CW_CALC
#define USE_HOME_ASSISTANT
#define USE_WEBCLIENT_HTTPS
#define USE_HTML_CALLBACK       // Für smlpd() Smartmeter Descriptor Dropdown

// Erweiterte Funktionen
#define USE_ANGLE_FUNC
#define USE_FEXTRACT

// SML Auth Key
#define USE_SML_AUTHKEY
#define USE_TLS

/*******************************************************************************
 * (6) ESP32 spezifische Features
 ******************************************************************************/
#define USE_ESP32_SW_SERIAL
#define USE_SCRIPT_SERIAL
#define SCRIPT_FULL_WEBPAGE
#define USE_MQTT_TLS
#define USE_INFLUXDB

/*******************************************************************************
 * (7) Ethernet Support (für Olimex ESP32-POE)
 ******************************************************************************/
#define USE_ETHERNET

/*******************************************************************************
 * (8) TCP Server und Task Support
 ******************************************************************************/
#define USE_SCRIPT_TCP_SERVER
#define USE_SCRIPT_TASK

/*******************************************************************************
 * (9) Shelly/EcoTracker Emulation (für Marstek Akkus etc.)
 ******************************************************************************/
#define USE_SCRIPT_MDNS

/*******************************************************************************
 * (10) Globale Variablen und JSON Export
 ******************************************************************************/
#define USE_SCRIPT_GLOBVARS
#define USE_SCRIPT_JSON_EXPORT

/*******************************************************************************
 * (11) SCRIPT DROPDOWN MENÜ - Scripts von ottelo's GitHub
 ******************************************************************************/
#define SCRIPT_LIST_DOWNLOAD_URL "https://raw.githubusercontent.com/ottelo9/tasmota-sml-script/main/script-list-menu/scripts/"
#define SCRIPT_LIST "scripts.json"

/*******************************************************************************
 * (12) OTA URL (optional - für dein eigenes Repo anpassen)
 ******************************************************************************/
// #undef OTA_URL
// #define OTA_URL "https://raw.githubusercontent.com/DEIN_USER/DEIN_REPO/main/firmware.bin"

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
