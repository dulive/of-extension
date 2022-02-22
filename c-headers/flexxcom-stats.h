#ifndef ___OPENFLOW_FLEXXCOM_STATS_H___
#define ___OPENFLOW_FLEXXCOM_STATS_H___

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

enum ofp_flexxcom_stats_type {
        OFPFCST_GLOBAL,
        OFPFCST_PORT
};

// only needed for openflow 1.0
struct ofp_flexxcom_global_stats_request {
     uint32_t experimenter;      // FLEXXCOM_VENDOR
     uint32_t exp_type;          //OFPFCST_GLOBAL;
};

/* flexxcom global stats request for openflow 1.3
 *
 * struct ofp_experimenter_multipart_header {
 *      uint32_t experimenter == FLEXXCOM_VENDOR;
 *      uint32_t exp_type == OFPFCST_GLOBAL;
 * }
 */

struct ofp_flexxcom_global_stats_reply {
        uint32_t experimenter; //FLEXXCOM_VENDOR
        uint32_t exp_type;     //OFPFCST_GLOBAL

        uint64_t consumption;
        uint64_t load;
};

struct ofp_flexxcom_port_stats_request {
        uint32_t experimenter; //FLEXXCOM_VENDOR
        uint32_t exp_type;     //OFPFCST_PORT

        //single port or all port when:
        //      of 1.0 -> port_no == OFPP_NONE
        //      of 1.3 -> port_no == OFPP_ANY
        uint16_t port_no; 
        uint8_t pad[6];
};

struct ofp_flexxcom_port_stats_reply {
        uint32_t experimenter; //FLEXXCOM_VENDOR
        uint32_t exp_type;     //OFPFCST_PORT

        //single port
        uint16_t port_no; 
        uint8_t pad[6];

        uint64_t consumption;
        uint64_t load;
};

#ifdef __cplusplus
}
#endif

#endif
