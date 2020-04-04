#include "RingBuffer.h"
#include <iostream>
#include <string>
#include <ncursesw/curses.h>

int main(int, char**) {
    initscr();
    std::string keys = "asd";
    while (true) {
        int chr = getch();
        if(chr != ERR){
            int pos = keys.find((char) chr);
            if(pos != std::string::npos){
                
            }
            
        }
    }
}
