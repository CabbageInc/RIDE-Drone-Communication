#ifndef INC_TXHANDLER_H_
#define INC_TXHANDLER_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "Constants.h"
#include "stm32u5xx_hal.h"

typedef struct {
    uint8_t startDelimiter; // 1 Byte or 8 Bits
    uint16_t length; // 2 Bytes or 16 Bits
    uint8_t frameType; // 1 Byte or 8 Bits
    uint8_t frameId; // 1 Byte or 8 Bits
    uint64_t destinationAddress; // 8 Bytes or 64 Bits
    uint16_t reserved; // 2 Bytes or 16 Bits
    uint8_t broadcastRadius; // 1 Byte or 8 bits
    uint8_t transmitOptions; // 1 Byte or 8 bits
    uint32_t fragmentNumber; // 4 Bytes or 32 bits
    uint8_t dataType; // 1 Byte or 8 bits
    uint8_t payloadData[MAX_DATA_SIZE]; // variable Bytes, max = 200 Bytes
    uint8_t checksum; // 1 Byte or 8 Bits
} TXPacket;

// Top level transmit call
// Accepts array of bytes for payload and a size parameter for size of the array
bool transmit(UART_HandleTypeDef *huart, uint8_t data[], size_t size, DataType dataType, uint64_t destAddr);

// function to return default TX_Packet
TXPacket defaultTxPacket();

// checksum calculator
uint8_t calcChecksum(TXPacket *packet);

// helper functions for checksum calculator
uint64_t sumAllBytes(uint64_t num, size_t byteCount);
uint64_t sumAllBytesArray(uint8_t arr[], size_t byteCount);

// convert packet to TX buffer array of uint8_t
uint8_t* packetToArray(TXPacket *packet);

// print packet to console
void printPacket(TXPacket *packet);

#endif // INC_TXHANDLER_H_
