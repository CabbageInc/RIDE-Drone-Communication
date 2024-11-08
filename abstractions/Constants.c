#include "Constants.h"

const uint8_t START_DELIMITER = 0x7E; // universal start delimiter
const uint16_t DEFAULT_TX_LENGTH = 214; // default length for TX Packet = 214 Bytes
const uint8_t TX_FRAME = 0x10; // frame type for TX
const uint8_t RX_FRAME = 0x90; // frame type for RX
const uint64_t XBEE_DRONE_MAC_ADDR = 0x0013A200423F4D8D; // mac address for drone-side XBee
const uint64_t XBEE_GROUND_MAC_ADDR = 0x0013A200423F4D3D; // mac address for ground-side XBee
const uint16_t RESERVED_FIELD = 0xFFFE; // universal bytes for populating reserved field in XBee api frame
const uint8_t BROADCAST_RADIUS = 0x00; // default broadcast radius for TX
const uint8_t TRANSMIT_OPTIONS = 0x00; // default options for TX frames