#include <mbed.h>
#include "serialCommunication.hpp"

#include <string>

SerialCommunication esp32(9600, D8, D2);
//SerialCommunication pc;

string line;
bool flag=false;

int main(){
    esp32.attach([](string str){line = str; flag=true;});
    while(1){
        if(flag){
            printf("%s\n", line.c_str());
            flag = false;
        }
        wait_ns(1);
    }
}
