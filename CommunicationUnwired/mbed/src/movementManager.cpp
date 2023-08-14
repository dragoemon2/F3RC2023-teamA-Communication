#include "movementManager.hpp"

//初期化
MovementManager::MovementManager(){
    flag = false; //flagを下げておく
    serial.attach([this](string str) {update(str);});
}

//esp32から受信があったときに割り込みで実行される
void MovementManager::update(string str){
    //必要な情報がesp32からスペース区切りで送られてくる．
    //int N = sscanf(str.c_str(), フォーマット, 変数1ポインタ, 変数2ポインタ, ...);
    //Nの値が変数の個数と異なるときはreturn; (通信で何らかの問題が起きたと判断し例外処理する)
    //ロボットがするべき動きをメンバ変数に書き込む
    //もし調整モード(flagがfalse)であり，次の動作に行けという命令なら，flag = true; を実行(mainloopがこれを検知する)
    
}

