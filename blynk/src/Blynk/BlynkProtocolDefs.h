/**
 * @file       BlynkProtocolDefs.h
 * @author     Volodymyr Shymanskyy
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2015 Volodymyr Shymanskyy
 * @date       Jan 2015
 * @brief      Blynk protocol definitions
 *
 */

#ifndef BlynkProtocolDefs_h
#define BlynkProtocolDefs_h

enum BlynkCmd
{
    BLYNK_CMD_RESPONSE       = 0,

    BLYNK_CMD_PING           = 6,

    BLYNK_CMD_BRIDGE         = 15,
    BLYNK_CMD_HARDWARE_SYNC  = 16,
    BLYNK_CMD_INTERNAL       = 17,
    BLYNK_CMD_PROPERTY       = 19,
    BLYNK_CMD_HARDWARE       = 20,
    BLYNK_CMD_GROUP          = 21,

    BLYNK_CMD_HW_LOGIN       = 29,

    BLYNK_CMD_REDIRECT       = 41,
    BLYNK_CMD_DEBUG_PRINT    = 55,
    BLYNK_CMD_EVENT_LOG      = 64,
    BLYNK_CMD_EVENT_CLEAR    = 65
};

enum BlynkStatus
{
    BLYNK_SUCCESS                = 200,
    BLYNK_QUOTA_LIMIT_EXCEPTION  = 1,
    BLYNK_ILLEGAL_COMMAND        = 2,
    BLYNK_NOT_REGISTERED         = 3,
    BLYNK_ALREADY_REGISTERED     = 4,
    BLYNK_NOT_AUTHENTICATED      = 5,
    BLYNK_NOT_ALLOWED            = 6,
    BLYNK_DEVICE_NOT_IN_NETWORK  = 7,
    BLYNK_NO_ACTIVE_DASHBOARD    = 8,
    BLYNK_INVALID_TOKEN          = 9,
    BLYNK_ILLEGAL_COMMAND_BODY   = 11,
    BLYNK_GET_GRAPH_DATA_EXCEPTION = 12,
    BLYNK_NO_DATA_EXCEPTION      = 17,
    BLYNK_DEVICE_WENT_OFFLINE    = 18,
    BLYNK_SERVER_EXCEPTION       = 19,

    BLYNK_NTF_INVALID_BODY       = 13,
    BLYNK_NTF_NOT_AUTHORIZED     = 14,
    BLYNK_NTF_ECXEPTION          = 15,

    BLYNK_TIMEOUT                = 16,

    BLYNK_NOT_SUPPORTED_VERSION  = 20,
    BLYNK_ENERGY_LIMIT           = 21,

    BLYNK_OPERATION_ACCEPT       = 23,
    BLYNK_OPERATION_DECLINE      = 24,
};

struct BlynkHeader
{
    uint8_t  type;
    uint16_t msg_id;
    uint16_t length;
}
BLYNK_ATTR_PACKED;

#if defined(ESP32) || defined(ESP8266)
    #include <lwip/def.h>
#elif !defined(htons) && (defined(ARDUINO) || defined(PARTICLE) || defined(__MBED__))
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        #define htons(x) ( ((x)<<8) | (((x)>>8)&0xFF) )
        #define htonl(x) ( ((x)<<24 & 0xFF000000UL) | \
                           ((x)<< 8 & 0x00FF0000UL) | \
                           ((x)>> 8 & 0x0000FF00UL) | \
                           ((x)>>24 & 0x000000FFUL) )
        #define ntohs(x) htons(x)
        #define ntohl(x) htonl(x)
    #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        #define htons(x) (x)
        #define htonl(x) (x)
        #define ntohs(x) (x)
        #define ntohl(x) (x)
    #else
        #error "Byte order not defined"
    #endif
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
    #define BLYNK_STR_16(a,b)     ((uint16_t(a) << 0) | (uint16_t(b) << 8))
    #define BLYNK_STR_32(a,b,c,d) ((uint32_t(a) << 0) | (uint32_t(b) << 8) | (uint32_t(c) << 16) | (uint32_t(d) << 24))
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
    #define BLYNK_STR_16(a,b)     ((uint16_t(b) << 0) | (uint16_t(a) << 8))
    #define BLYNK_STR_32(a,b,c,d) ((uint32_t(d) << 0) | (uint32_t(c) << 8) | (uint32_t(b) << 16) | (uint32_t(a) << 24))
#else
    #error byte order problem
#endif

#define BLYNK_HW_PM BLYNK_STR_16('p','m')
#define BLYNK_HW_DW BLYNK_STR_16('d','w')
#define BLYNK_HW_DR BLYNK_STR_16('d','r')
#define BLYNK_HW_AW BLYNK_STR_16('a','w')
#define BLYNK_HW_AR BLYNK_STR_16('a','r')
#define BLYNK_HW_VW BLYNK_STR_16('v','w')
#define BLYNK_HW_VR BLYNK_STR_16('v','r')

#define BLYNK_INT_RTC  BLYNK_STR_32('r','t','c',0)
#define BLYNK_INT_UTC  BLYNK_STR_32('u','t','c',0)
#define BLYNK_INT_OTA  BLYNK_STR_32('o','t','a',0)
#define BLYNK_INT_VFS  BLYNK_STR_32('v','f','s',0)
#define BLYNK_INT_DBG  BLYNK_STR_32('d','b','g',0)
#define BLYNK_INT_ACON BLYNK_STR_32('a','c','o','n')
#define BLYNK_INT_ADIS BLYNK_STR_32('a','d','i','s')
#define BLYNK_INT_META BLYNK_STR_32('m','e','t','a')

#endif
