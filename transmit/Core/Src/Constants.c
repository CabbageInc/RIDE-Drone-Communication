#include "Constants.h"

const uint8_t START_DELIMITER = 0x7E; // universal start delimiter
const uint16_t DEFAULT_TX_LENGTH = 220; // default length for TX Packet = 220 Bytes
const size_t DEFAULT_TX_BUFFER_SIZE = 224; // default TX buffer size = 220 bytes + 4 bytes = 224 bytes
const uint8_t TX_FRAME = 0x10; // frame type for TX
const uint8_t RX_FRAME = 0x90; // frame type for RX
const uint8_t DEFAULT_FRAME_ID = 0x00; // default frame id = 0x00;
const uint64_t XBEE_DRONE_TEST_MAC_ADDR = 0x0013A200423F4D8D; // mac address for drone-side XBee
const uint64_t XBEE_GROUND_TEST_MAC_ADDR = 0x0013A200423F4D3D; // mac address for ground-side XBee
const uint64_t DEFAULT_DEST_ADDR = 0x000000000000FFFF; // default destination address = 0x000000000000FFFF (broadcast address)
const uint16_t RESERVED_FIELD = 0xFFFE; // universal bytes for populating reserved field in XBee api frame
const uint8_t BROADCAST_RADIUS = 0x00; // default broadcast radius for TX
const uint8_t TRANSMIT_OPTIONS = 0x00; // default options for TX frames
const uint32_t DEFAULT_FRAG_NUM = 0x00; // default fragment number = 0x00
const uint8_t DEFAULT_DATA_TYPE = 0x00; // default TX data type = 0x00 (Text)
const uint8_t DEFAULT_DATA_SIZE = 0x00; // defualt TX data size = 0x00
const uint8_t DEFAULT_CHECKSUM = 0x00; // default checksum value = 0x00
