#include <Arduino.h>
#include "PS4Controller.h"

PS4Controller ps4;
HardwareSerial mbed;

/*
void setup(){
    //初期化処理
}

void loop(){
    //ループ処理
}*/

void setup() {
  ps4.begin("1a:2b:3c:01:01:01");
}

void loop() {
  if (ps4.isConnected()) {
    if (ps4.Right()) {
        //右ボタンが押された時
    }

    if (ps4.Down()) {
        //下ボタンが押された時
    }
    
    if (ps4.Up()) {
        //上ボタンが押された時
    }

    if (ps4.Left()) {

    }

    if (ps4.Square()) {

    }

    if (ps4.Cross()) {

    }

    if (ps4.Circle()) {

    }

    if (ps4.Triangle()) {
        
    }

    if (ps4.UpRight()) {

    }

    if (ps4.DownRight()) {

    }

    if (ps4.UpLeft()) {

    }

    if (ps4.DownLeft()) {

    }

    if (ps4.L1()) {

    }

    if (ps4.R1()) {

    }

    if (ps4.Share()) {

    }

    if (ps4.Options()) {

    }

    if (ps4.L3()) {

    }

    if (ps4.R3()) {

    }

    if (ps4.PSButton()) {

    }

    if (ps4.Touchpad()) {

    }

    if (ps4.L2()) {
        //uint8_t ps4.L2Value();で値を読める
    }

    if (ps4.R2()) {
        //uint8_t ps4.L2Value();で値を読める
    }

    //バッテリーレベルps4.Battery()でわかる

    //ジョイスティックはint8_t ps4.LStickX(), ps4.LStickY(), ps4.RStickX(), ps4.RStickY()で読める
    
    //充電してるかps4.Charging()
    //ヘッドフォンしてるかps4.Audio()
    //マイクしてるかps4.Mic()
    
  }
}
