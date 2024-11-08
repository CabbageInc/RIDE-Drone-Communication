#include <stdio.h>
#include "TxHandler.h"
#include "RxHandler.h"

int main(){

    TXPacket packet = defaultTxPacket();

    printf("this is the start delimiter: %02X\n", packet.startDelimiter);
    printf("this is the last byte of the payload data: %02X\n", packet.payloadData[199]);

    RXPacket packet2;
    packet2.startDelimiter = 0x7A;

    printf("this is the second start delimiter: %02X", packet2.startDelimiter);
    
    return 0;
}