#ifndef ___OPENFLOW_FLEXXCOM_METER_H___
#define ___OPENFLOW_FLEXXCOM_METER_H___

//include openflow
//needs OPF_ASSERT

#include <stdint.h>

//dunno if it is needed for C++
#ifdef __cplusplus
extern "C" {
#endif

//verification probably not needed
#ifndef FLEXXCOM_VENDOR

#define FLEXXCOM_VENDOR 0xe433

#endif

enum ofp_flexxcom_meter_flags {
        OFPFCMF_LOAD_PCT   = 1 << 0,
        OFPFCMF_LOAD_PKTPS = 1 << 1,
        OFPFCMF_LOAD_CPU   = 1 << 2,
        OFPFCMF_CON_PORT   = 1 << 3,
        OFPFCMF_STATS      = 1 << 4
};

enum ofp_flexxcom_meter_band_type {
        OFPFCMBT_DROP,
        OFPFCMBT_WARN_CONTROLLER
};

enum ofp_flexxcom_meter_band_value {
        OFPFCMBV_LOAD,
        OFPFCMBV_CONSUMPTION,
};

struct ofp_flexxcom_meter_band {
        uint16_t type;      //one of ofp_flexxcom_meter_band_type
        uint16_t len;       //probably not needed
        //maybe add pad
        
        uint8_t value_type; //one of ofp_flexxcom_meter_band_value
        uint64_t value;
        uint8_t pad[3];
};

struct ofp_flexxcom_meter_mod {
        //mabe it needs ofp_header

        uint32_t experimenter; //FLEXXCOM_VENDOR
        uint32_t exp_type;     //ignored (openflow 1.3 requires it)

        uint16_t command;      //one of ofp_meter_mod_command (same as of_meter_mod)
        uint16_t flags;        //flags from ofp_flexxcom_meter_flags
        uint32_t meter_id;      //meter instance (same as of_meter_mod)

        //same as ofp_meter_mod but with ofp_flexxcom_meter_band
        struct ofp_flexxcom_meter_band bands[0];
};

//missing warn controller msg type?

#ifdef __cplusplus
}
#endif

#endif
