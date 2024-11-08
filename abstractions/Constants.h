#ifndef INC_CONSTANTS_H_
#define INC_CONSTANTS_H_

#include <stdint.h>

#define MAX_DATA_SIZE 200 // max size for data field in TXPacket

extern const uint8_t START_DELIMITER; // universal start delimiter
extern const uint16_t DEFAULT_TX_LENGTH; // default TX packet length = 214 Bytes
extern const uint8_t TX_FRAME; // frame type for TX
extern const uint8_t RX_FRAME; // frame type for RX
extern const uint64_t XBEE_DRONE_MAC_ADDR; // mac address for drone-side XBee
extern const uint64_t XBEE_GROUND_MAC_ADDR; // mac address for ground-side XBee
extern const uint16_t RESERVED_FIELD; // universal bytes for populating reserved field in XBee api frame
extern const uint8_t BROADCAST_RADIUS; // broadcast radius for TX
extern const uint8_t TRANSMIT_OPTIONS; // default options for TX frames

#endif // INC_CONSTANTS_H_