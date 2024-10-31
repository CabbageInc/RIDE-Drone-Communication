#include <stdio.h>
#include "TxHandler.h"
#include "RxHandler.h"

int main(){
    
    int num = sumOfTwoNumbers(3, 5);
    printf("this is the num: %d\n", num);

    TXPacket packet;
    packet.startDelimiter = 0x7E;

    printf("this is the start delimiter: %02X\n", packet.startDelimiter);

    RXPacket packet2;
    packet2.startDelimiter = 0x7A;

    printf("this is the second start delimiter: %02X", packet2.startDelimiter);
    
    return 0;
}