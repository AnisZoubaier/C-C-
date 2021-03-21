#include "canSend.hpp"
int main(){
    canSend sending;
    sending.sendBewertung();
    sending.sendBewertung(0x555,1,2);
    return 0;
}
