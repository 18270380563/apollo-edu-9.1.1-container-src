#pragma once

#include "gflags/gflags.h"

namespace apollo {
namespace trafficlight {

DECLARE_string(module_name);

// IP & PORT
DECLARE_string(obu_host);
DECLARE_string(obu_port);

// Writer
DECLARE_string(traffic_light_topic);

// SPAT
DECLARE_bool(enable_spat_publish);
DECLARE_string(spat_topic);
DECLARE_int32(spat_node_focus_id);
DECLARE_int32(spat_phase_focus_id);
DECLARE_string(traffic_light_id);

}  // namespace trafficlight
}  // namespace apollo
