
#include <Arduino.h>
#include "PS4Controller.h"

PS4Controller ps4;


bool next_button = false;
bool increment_button = false;
bool decrement_button = false;

bool hand_button = false;
bool auto_button = false;

int next_serial_time;

#define SERIAL_INTERNAL (10)

//HardwareSerial Serial(0);


#if 1
#include <esp_bt_main.h>
#include <esp_bt_device.h>

char str[100];

void setup()
{
    uint8_t new_mac[8] = {0x24, 0x6f, 0x28, 0x04, 0x41, 0x66};
    esp_base_mac_addr_set(new_mac);
    Serial.begin(115200);
    PS4.begin();
    const uint8_t* address = esp_bt_dev_get_address();
    sprintf(str, "ESP32's Bluetooth MAC address is - %02x:%02x:%02x:%02x:%02x:%02x", address[0],address[1],address[2],address[3],address[4],address[5]);
}

void loop()
{
    Serial.println(str);
}


#else

void setup(){
    uint8_t new_mac[8] = {0x24, 0x6f, 0x28, 0x04, 0x41, 0x66};
    esp_base_mac_addr_set(new_mac);
    ps4.begin("24:6f:28:04:41:66");
    // ps4.begin("28:C1:3C:3F:D4:80");
    #if 1
    Serial.begin(115200);
    Serial.println("started");
    #else
    Serial.begin(9600);
    #endif

    next_serial_time = millis();
}



void loop() {
    delay(1);
    if(ps4.isConnected()){
        if(millis() >= next_serial_time){
            next_serial_time += SERIAL_INTERNAL;

            //ジョイスティックの値の送信
            Serial.printf("J %d %d %d %d B %d %d\n", ps4.LStickX(), ps4.LStickY(), ps4.RStickX(), ps4.RStickY(), ps4.L2(), ps4.R2());

            delay(1);

            //L2，R2ボタン
            //Serial.printf("aB %d %d\n", ps4.L2(), ps4.R2());
        }
        
        //その他切り替え用のボタン
        if(!next_button && ps4.Cross()){
            Serial.printf("z\n");
        }
        next_button = ps4.Cross();

        if(!increment_button && ps4.Triangle()){
            Serial.printf("a\n");
        }
        increment_button = ps4.Triangle();

        if(!decrement_button && ps4.Up()){
            Serial.printf("b\n");
        }
        decrement_button = ps4.Up();

        if(!hand_button && ps4.R1()){
            Serial.printf("c\n");
        }
        hand_button = ps4.R1();

        if(!auto_button && ps4.L1()){
            Serial.printf("d\n");
        }
        auto_button = ps4.L1();
        
    }
}
#endif