#ifndef INC_RXHANDLER_H_
#define INC_RXHANDLER_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "Constants.h"

typedef struct {
    uint8_t startDelimiter;
    uint16_t length;
    uint8_t frameType;
    uint64_t sourceAddress;
    uint16_t reserved;
    uint8_t receiveOptions;
    uint32_t fragmentNumber;
    uint8_t dataType;
    uint8_t dataSize;
    uint8_t payloadData[MAX_DATA_SIZE];
    uint8_t checksum;
} RXPacket;

// top level receive function
bool receive(uint8_t output, size_t size);

// function to return default RX_Packet
RXPacket defaultRxPacket();

#endif // INC_RXHANDLER_H_