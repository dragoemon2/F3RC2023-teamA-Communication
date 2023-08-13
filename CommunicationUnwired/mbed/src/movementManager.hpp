#pragma once

#include "serialCommunication.hpp"

/*
手動機R1の動きを決定するためのクラス

R1の動きをpublicメンバ変数にして(またはprivateにしてpublicメンバ関数でそれを読むのでも良い)
それをmainloopの中で読むことでR1が動く

受信があった時にupdate();が割り込みで実行されるので，その引数string strをもとにメンバ変数を書き換える
*/

using namespace std;

class MovementManager{
    public:
        SerialCommunication serial;

        //ロボットがするべき動きを決めたメンバ変数を作って．以下は一例

        //1. 動作番号を表すunsigned int

        //2. ロボットの動くべき速度[mm/s](手動時および調整時)

        //3. 自動/手動モードを示すbool変数

        //4. ジョイスティックなどの値

        //動作モードであることを示すflag
        bool flag = false;

        //受信があると実行される
        void update(string str); 

        MovementManager();
};