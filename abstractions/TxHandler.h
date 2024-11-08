#ifndef INC_TXHANDLER_H_
#define INC_TXHANDLER_H_

#include <stdint.h>
#include <stdbool.h>
#include "Constants.h"

typedef struct {
    uint8_t startDelimiter; // 1 Byte or 8 Bits
    uint16_t length; // 2 Bytes or 16 Bits
    uint8_t frameType; // 1 Byte or 8 Bits
    uint8_t frameId; // 1 Byte or 8 Bits
    uint64_t destinationAddress; // 8 Bytes or 64 Bits
    uint16_t reserved; // 2 Bytes or 16 Bits
    uint8_t broadcastRadius; // 1 Byte or 8 bits
    uint8_t transmitOptions; // 1 Byte or 8 bits
    uint8_t payloadData[MAX_DATA_SIZE]; // variable Bytes, max = 200 Bytes
    uint8_t checksum; // 1 Byte or 8 Bits
} TXPacket;

// Top level transmit call
// Accepts array of bytes for payload and a size parameter for size of the array
bool transmit(uint8_t data[], size_t size, uint64_t destAddr);

// function to return default TX_Packet
TXPacket defaultTxPacket();

#endif // INC_TXHANDLER_H_