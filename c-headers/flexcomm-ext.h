#ifndef OPENFLOW_FLEXCOMM_EXT_H
#define OPENFLOW_FLEXCOMM_EXT_H 1

#include "openflow/openflow.h"

#define FLEXCOMM_VENDOR_ID 0x0000f82a

enum ofp_flexcomm_msg_type {
    FC_REQUEST = 0,
    FC_REPLY   = 1
};

enum ofp_flexcomm_stats_type {
    FC_ST_GLOBAL = 0,
    FC_ST_PORT   = 1
};

struct ofp_flexcomm_stats_header {
    struct ofp_header header;
    uint32_t vendor;                /* FLEXCOMM_VENDOR_ID */
    uint32_t subtype;               /* One of ofp_flexcomm_msg_type */
    uint32_t stat_type;             /* One of ofp_flexcomm_stats_type */
};
OFP_ASSERT(sizeof(struct ofp_flexcomm_stats_header) == 20);

struct ofp_flexcomm_global_stats_request {
    struct ofp_flexcomm_stats_header fh;
};
OFP_ASSERT(sizeof(struct ofp_flexcomm_global_stats_request) == 20);

struct ofp_flexcomm_port_stats_request {
    struct ofp_flexcomm_stats_header fh;
    uint32_t port_no;
};
OFP_ASSERT(sizeof(struct ofp_flexcomm_port_stats_request) == 24);

struct ofp_flexcomm_global_stats_reply {
    struct ofp_flexcomm_stats_header fh;
    uint8_t pad[4];
    uint64_t consumption;
    uint64_t load;
};
OFP_ASSERT(sizeof(struct ofp_flexcomm_global_stats_reply) == 40);

struct ofp_flexcomm_port_stats_reply {
    struct ofp_flexcomm_stats_header fh;
    uint32_t port_no;
    uint64_t consumption;
};
OFP_ASSERT(sizeof(struct ofp_flexcomm_port_stats_reply) == 32);

#endif
