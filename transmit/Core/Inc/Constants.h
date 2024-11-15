#ifndef INC_CONSTANTS_H_
#define INC_CONSTANTS_H_

#include <stdint.h>
#include <stddef.h>

#define MAX_DATA_SIZE 200 // max size for data field in TXPacket

// fragment data types
typedef enum {
    TEXT = 0,
    IMAGE = 1,
    GPS = 2
} DataType;

extern const uint8_t START_DELIMITER; // universal start delimiter
extern const uint16_t DEFAULT_TX_LENGTH; // default TX packet length = 220 Bytes
extern const size_t DEFAULT_TX_BUFFER_SIZE; // default TX buffer size = 220 bytes + 4 bytes = 224 bytes
extern const uint8_t TX_FRAME; // frame type for TX
extern const uint8_t RX_FRAME; // frame type for RX
extern const uint8_t DEFAULT_FRAME_ID; // default frame id = 0x00;
extern const uint64_t XBEE_DRONE_TEST_MAC_ADDR; // mac address for drone-side XBee
extern const uint64_t XBEE_GROUND_TEST_MAC_ADDR; // mac address for ground-side XBee
extern const uint64_t DEFAULT_DEST_ADDR; // default destination address = 0x000000000000FFFF (broadcast address)
extern const uint16_t RESERVED_FIELD; // universal bytes for populating reserved field in XBee api frame
extern const uint8_t BROADCAST_RADIUS; // broadcast radius for TX
extern const uint8_t TRANSMIT_OPTIONS; // default options for TX frames
extern const uint32_t DEFAULT_FRAG_NUM; // default fragment number = 0x00
extern const uint8_t DEFAULT_DATA_TYPE; // default TX data type = 0x00 (Text)
extern const uint8_t DEFAULT_DATA_SIZE; // default TX data size = 0x00
extern const uint8_t DEFAULT_CHECKSUM; // default checksum value = 0x00

#endif // INC_CONSTANTS_H_
