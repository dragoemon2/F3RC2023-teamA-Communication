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


    if(str[0] == 'J'){
        int lx;
        int ly;

        int rx;
        int ry;

        int N = sscanf(str.c_str(), "J %d %d %d %d", &lx, &ly, &rx, &ry);
        if(N != 4){
            return;
        }

        //ジョイスティクの処理

    }else if(str[0] == 'B'){
        int button_L2;
        int button_R2;

        int N = sscanf(str.c_str(), "B %d %d", &button_L2, &button_R2);

        //L2と1の処理


    }else if(str[0] == 'z'){
        //調整モードから動作モードへの切り替え
        flag = true;
    }else if(str[0] == 'a'){
        movement_id++;
    }else if(str[0] == 'b'){
        if(movement_id > 0){
            movement_id--;
        }
    }else if(str[0] == 'c'){
        mode = HAND_MODE;
    }else if(str[0] == 'd'){
        mode = AUTO_MODE;
    }




}
