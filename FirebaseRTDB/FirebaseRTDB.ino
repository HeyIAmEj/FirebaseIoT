
/**
 * Created by K. Suwatchai (Mobizt)
 *
 * Email: k_suwatchai@hotmail.com
 *
 * Github: https://github.com/mobizt/Firebase-ESP-Client
 *
 * Copyright (c) 2023 mobizt
 *
 */


#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

#define WIFI_SSID "VEVE"
#define WIFI_PASSWORD "#veve777"

// For the following credentials, see examples/Authentications/SignInAsUser/EmailPassword/EmailPassword.ino

/* 2. Define the API Key */
#define API_KEY "AIzaSyByZl9ncf8UoIk6WEPkzoq_peLubHAatNY"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://vumi-9db3e-default-rtdb.firebaseio.com"  //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "vumiesp@vumiesp.com"
#define USER_PASSWORD "vumiesp"
#define DEVICE_NAME "ESP8266_NV3"

// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
unsigned long interval = 15000;
unsigned long count = 0;

void setup() {

  Serial.begin(115200);


  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to Wi-Fi");
  unsigned long ms = millis();
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  config.api_key = API_KEY;

  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  config.database_url = DATABASE_URL;

  config.token_status_callback = tokenStatusCallback;


  Firebase.reconnectNetwork(true);

  fbdo.setBSSLBufferSize(4096 /* Rx buffer size in bytes from 512 - 16384 */, 1024 /* Tx buffer size in bytes from 512 - 16384 */);

  // Limit the size of response payload to be collected in FirebaseData
  fbdo.setResponseSize(2048);

  Firebase.begin(&config, &auth);



  Firebase.setDoubleDigits(5);

  config.timeout.serverResponse = 10 * 1000;
  //Network reconnect timeout (interval) in ms (10 sec - 5 min) when network or WiFi disconnected.
  config.timeout.networkReconnect = 10 * 1000;
  //will return false (error) when it called repeatedly in loop.
  config.timeout.rtdbStreamError = 3 * 1000;
}

void tokenStatusCallback() {
  Serial.println("Data");
}

void loop() {

  if (Firebase.ready() && (millis() - sendDataPrevMillis > interval || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();

    FirebaseJson mainJson;

    createJson(mainJson, "name", "LG Dual Voice");
    createJson(mainJson, "status", "on");


    bool result = Firebase.RTDB.set(&fbdo, DEVICE_NAME, &mainJson);
    Serial.printf("Enviando payload.... \n %s \n\n", result ? "Sucesso!" : fbdo.errorReason().c_str());


    count++;
  }
}


FirebaseJson createJson(FirebaseJson& data, const String& key, const String& value) {
    data.add(key, value);
    return data;
}
