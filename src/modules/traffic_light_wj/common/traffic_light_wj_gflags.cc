#include "modules/traffic_light_wj/common/traffic_light_wj_gflags.h"

namespace apollo {
namespace trafficlight {

DEFINE_string(module_name, "tfl_wj", "module name");

// IP & PORT
DEFINE_string(obu_host, "127.0.0.1", "obu tcp server host ip");
DEFINE_string(obu_port, "15006", "obu tcp server port");

// Writer
DEFINE_string(traffic_light_topic, "/apollo/perception/traffic_light", "traffic light topic");

// SPAT
DEFINE_bool(enable_spat_publish, true, "whether to publish SPAT from OBU");
DEFINE_string(spat_topic, "/obu/spat", "SPAT original data topic");

DEFINE_int32(spat_node_focus_id, 24, "SPAT of intersection node id to foucs");
DEFINE_int32(spat_phase_focus_id, 7, "SPAT of phase node id to foucs");
DEFINE_string(traffic_light_id, "Signal_", "Traffic light id prefix");

}  // namespace trafficlight
}  // namespace apollo
