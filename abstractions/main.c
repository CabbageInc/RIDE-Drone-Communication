#include <stdio.h>
#include <string.h>
#include "TxHandler.h"
#include "RxHandler.h"
#include "Constants.h"

int main(){

    /*
    TXPacket packet = defaultTxPacket();

    printf("this is the start delimiter: %02X\n", packet.startDelimiter);
    printf("this is the last byte of the payload data: %02X\n", packet.payloadData[199]);
    printf("this is the checksum for this packet %02X\n", calcChecksum(&packet));

    RXPacket packet2;
    packet2.startDelimiter = 0x7A;

    printf("this is the second start delimiter: %02X\n", packet2.startDelimiter);

    printf("this is the integer code for TEXT: %d\n", TEXT);

    printf("this is the default length of a packet: %04X\n", DEFAULT_TX_LENGTH);

    printf("this is the size of the unsigned long: %d\n", sizeof(unsigned long long));
    */

    uint8_t data[] = "Hello World";

    size_t size = strlen(data);
    transmit(data, size, TEXT, XBEE_GROUND_TEST_MAC_ADDR);
    
    return 0;
}