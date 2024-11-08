#include <stdlib.h>
#include <time.h>
#include "TxHandler.h"

bool transmit(uint8_t data[], size_t size, uint64_t destAddr){
    
    if(size > 200){
        // framgent the data array
    }else{
        // transmit the data array in its entirety
        TXPacket packet = defaultTxPacket();

        // fill remaining fields: length, frameId, destination address, payload data, checksum
        // frameId
        srand(time(NULL));
        packet.frameId = rand() % 256;
        // destination address
        packet.destinationAddress = destAddr;
        // payload data
        for(size_t i = 0; i<size; i++){
            packet.payloadData[i] = data[i];
        }
        // checksum
    }

    return false;
}

TXPacket defaultTxPacket(){
    return (TXPacket){
        .startDelimiter = START_DELIMITER,
        .length = DEFAULT_TX_LENGTH,
        .frameType = TX_FRAME,
        .reserved = RESERVED_FIELD,
        .broadcastRadius = BROADCAST_RADIUS,
        .transmitOptions = TRANSMIT_OPTIONS,
        .payloadData = {0x00}
    };
}