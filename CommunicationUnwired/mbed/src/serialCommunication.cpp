#include <mbed.h>
#include "serialCommunication.hpp"

using namespace std;

SerialCommunication::SerialCommunication(int speed, PinName tx, PinName rx): serialPort(tx, rx) {
    str = "";
    func = [](string comment) {return;};
    serialPort.baud(speed);
    serialPort.format(
        /* bits */ 8,
        /* parity */ SerialBase::None,
        /* stop bit */ 1
    );
    #if 0
    serialPort.attach([this]() {readChar();});
    #endif
}

void SerialCommunication::writeline(string comment) {
    //書きこみ
    serialPort.write((comment+'\n').c_str(), comment.size() + 1);
}

void SerialCommunication::readChar() {
    char c;
    while(serialPort.readable()){
        serialPort.read(&c, 1);
        if(c == '\n'){
            func(str);
            str.clear();
        }else{
            str.push_back(c);
        }
    }
    _s1 = true;
}

void SerialCommunication::attach(function<void(string)> f) {
    //受信時に割り込みで実行される関数を設定
    func = f;
}

void SerialCommunication::loop(){
    readChar();
}

void SerialCommunication::detach(){
    func = [](string comment) {return;};
}


