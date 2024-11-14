#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "TxHandler.h"

bool transmit(uint8_t data[], size_t size, DataType dataType, uint64_t destAddr){
    // prepare for rand num generation
    srand(time(NULL));
    
    // local variables
    uint32_t fragmentNumber = 0;
    uint8_t messageId = 0x00; //rand() % 256;

    if(size > 200){
        // framgent the data array
    }else{
        // transmit the data array in its entirety
        TXPacket packet = defaultTxPacket();

        // fill remaining fields: length, frameId, destination address, fragment number, data type, payload data, checksum
        // length
        packet.length = DEFAULT_TX_LENGTH;
        // frameId
        packet.frameId = messageId;
        // destination address
        packet.destinationAddress = destAddr;
        // fragment number
        packet.fragmentNumber = fragmentNumber;
        // data type
        packet.dataType = dataType;
        // payload data
        for(size_t i = 0; i<size; i++){
            packet.payloadData[i] = data[i];
        }
        // checksum
        packet.checksum = calcChecksum(&packet);

        // create TX buffer
        uint8_t *txBuffer = packetToArray(&packet);
        
        // test output
        printf("TX Buffer: ");
        for(size_t i=0; i<DEFAULT_TX_BUFFER_SIZE; i++){
            printf("%02X ", txBuffer[i]);
        }
        printf("\n");

        // HAL_Transmit...

        // clean up dynamic memory for TX Buffer
        free(txBuffer);

        // indicate good transmission
        return true;
    }

    return false;
}

TXPacket defaultTxPacket(){
    return (TXPacket){
        .startDelimiter = START_DELIMITER,
        .length = DEFAULT_TX_LENGTH,
        .frameType = TX_FRAME,
        .frameId = DEFAULT_FRAME_ID,
        .destinationAddress = DEFAULT_DEST_ADDR,
        .reserved = RESERVED_FIELD,
        .broadcastRadius = BROADCAST_RADIUS,
        .transmitOptions = TRANSMIT_OPTIONS,
        .fragmentNumber = DEFAULT_FRAG_NUM,
        .dataType = DEFAULT_DATA_TYPE,
        .payloadData = {0x00},
        .checksum = DEFAULT_CHECKSUM
    };
}

uint8_t calcChecksum(TXPacket *packet){
    // add all the bytes between length and checksum
    uint64_t sum = 0;
    sum += packet->frameType;
    sum += packet->frameId;
    sum += sumAllBytes(packet->destinationAddress, sizeof(packet->destinationAddress));
    sum += sumAllBytes(packet->reserved, sizeof(packet->reserved));
    sum += packet->broadcastRadius;
    sum += packet->transmitOptions;
    sum += sumAllBytes(packet->fragmentNumber, sizeof(packet->fragmentNumber));
    sum += packet->dataType;
    sum += sumAllBytesArray(packet->payloadData, MAX_DATA_SIZE);

    // return the last 8 bits (1 byte) subtracted from 0xFF
    return 0xFF - (sum & 0xFF);
}

uint64_t sumAllBytes(uint64_t num, size_t byteCount){
    uint64_t sum = 0x00;
    for(size_t i=0; i<byteCount; i++){
        sum += (num >> i*8) & 0xFF;
    }
    return sum;
}

uint64_t sumAllBytesArray(uint8_t arr[], size_t byteCount){
    uint64_t sum = 0x00;
    for(size_t i=0; i<byteCount; i++){
        sum += arr[i];
    }
    return sum;
}

uint8_t* packetToArray(TXPacket *packet){
    uint8_t *output = (uint8_t*)malloc((packet->length + 4) * sizeof(uint8_t));
    if (output == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    size_t shift = 0;
    int offset = 0;
    
    // start delimiter
    output[offset] = packet->startDelimiter;
    // length
    shift = sizeof(packet->length);
    offset += 1;
    for(size_t i=shift; i>0; i--){output[shift-i+offset] = packet->length>>(i-1)*8 & 0xFF;}
    // frame type
    offset += 2;
    output[offset] = packet->frameType;
    // frame ID
    offset += 1;
    output[offset] = packet->frameId;
    // Destination address
    shift = sizeof(packet->destinationAddress);
    offset += 1;
    for(size_t i=shift; i>0; i--){output[shift-i+offset] = packet->destinationAddress>>(i-1)*8 & 0xFF;}
    // reserved
    shift = sizeof(packet->reserved);
    offset += 8;
    for(size_t i=shift; i>0; i--){output[shift-i+offset] = packet->reserved>>(i-1)*8 & 0xFF;}
    // broadcast radius
    offset += 2;
    output[offset] = packet->broadcastRadius;
    // Transmit options
    offset += 1;
    output[offset] = packet->transmitOptions;
    // fragment number
    shift = sizeof(packet->fragmentNumber);
    offset += 1;
    for(size_t i=shift; i>0; i--){output[shift-i+offset] = packet->length>>(i-1)*8 & 0xFF;}
    // data type
    offset += 4;
    output[offset] = packet->dataType;
    // payload data
    offset += 1;
    for(size_t i=0; i<MAX_DATA_SIZE; i++){output[i+offset] = packet->payloadData[i];}
    // checksum
    offset += MAX_DATA_SIZE;
    output[offset] = packet->checksum;

    return output;
}

void printPacket(TXPacket *packet){
    printf("packet fields: \n");
    printf("start delimiter: %02X\n", packet->startDelimiter);
    printf("length: %04X\n", packet->length);
    printf("frame type: %02X\n", packet->frameType);
    printf("frame ID: %02X\n", packet->frameId);
    printf("destination address: %llX\n", packet->destinationAddress);
    printf("reserved: %04X\n", packet->reserved);
    printf("broadcast radius: %02X\n", packet->broadcastRadius);
    printf("transmit options: %02X\n", packet->transmitOptions);
    printf("fragment number: %08X\n", packet->fragmentNumber);
    printf("data type: %02X\n", packet->dataType);
    // payload data
    printf("payload data: ");
    for(size_t i=0; i<MAX_DATA_SIZE; i++){
        printf("%02X ", packet->payloadData[i]);
    }
    printf("\n");
    // checksum
    printf("checksum: %02X\n", packet->checksum);
}
