#include <mbed.h>
#include "serialCommunication.hpp"

#include <string>

SerialCommunication esp32(9600, PA_9, PA_10);
//SerialCommunication pc;

int main(){
    esp32.attach([](string str){printf("%s\n", str.c_str());});
    while(1){
        esp32.loop();
    }
}
