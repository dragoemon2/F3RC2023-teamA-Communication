#pragma once

#include "serialCommunication.hpp"

/*
手動機R1の動きを決定するためのクラス

R1の動きをpublicメンバ変数にして(またはprivateにしてpublicメンバ関数でそれを読むのでも良い)
それをmainloopの中で読むことでR1が動く

受信があった時にupdate();が割り込みで実行されるので，その引数string strをもとにメンバ変数を書き換える
*/

using namespace std;

#define HAND_MODE (0)
#define AUTO_MODE (1)
#define COMPLETELY_AUTO_MODE (2)

class MovementManager{
    private:
        //正規化したジョイスティックの値
        float ljoystick_x = 0;
        float ljoystick_y = 0;
        float rjoystick_x = 0;
        float rjoystick_y = 0;

        bool left_rotate_button = false;
        bool right_rotate_button = false;

        void setTargetSpeed();

    public:
        SerialCommunication serial;

        //ロボットがするべき動きを決めたメンバ変数を作って．以下は一例

        //動作番号
        int movement_id = 0;

        //自動モードか手動モードか
        int mode = HAND_MODE;

        //ジョイスティックやボタンの値から検出した目標の速度
        float targetSpeedX = 0;
        float targetSpeedY = 0;
        float targetSpeedD = 0;

        //動作モードであることを示すflag
        bool flag = false;

        //受信があると実行される
        void update(string str);

        MovementManager();
};