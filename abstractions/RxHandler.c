#include <stdlib.h>
#include <stdio.h>
#include "RxHandler.h"

bool receive(uint8_t output, size_t size){
    //create the main RX buffer
    uint8_t rxBuffer[DEFAULT_RX_BUFFER_SIZE];

    // HAL Receive IT...

    // instantiate default RX packet
    RXPacket packet = defaultRxPacket();

    // fill packet fields with data from RX buffer
    size_t shift = 0;
    int offset = 0;
    // source address
    shift = sizeof(packet.sourceAddress);
    offset = 4;
    for(size_t i=shift; i>0; i--){
        packet.sourceAddress += rxBuffer[offset+shift-i]<<(i-1);
    }
    // receive options
    offset = 14;
    packet.receiveOptions = rxBuffer[offset];
    // fragment number
    offset = 15;
    shift = sizeof(packet.fragmentNumber);
    for(size_t i=shift; i>0; i--){
        packet.fragmentNumber += rxBuffer[offset+shift-i]<<(i-1);
    }
    // data type
    offset = 19;
    // data size
    offset = 20;
    // payload data
    offset = 21;
    // checksum
    offset = 221;
    
    return false;
}

RXPacket defaultRxPacket(){
    return (RXPacket){
        .startDelimiter = START_DELIMITER,
        .length = DEFAULT_RX_LENGTH,
        .frameType = RX_FRAME,
        .sourceAddress = DEFAULT_SRC_ADDR,
        .reserved = RESERVED_FIELD,
        .receiveOptions = RECEIVE_OPTIONS,
        .fragmentNumber = DEFAULT_FRAG_NUM,
        .dataType = DEFAULT_DATA_TYPE,
		.dataSize = DEFAULT_DATA_SIZE,
        .payloadData = {0x00},
        .checksum = DEFAULT_CHECKSUM
    };
}