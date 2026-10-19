#include "modules/planning/scenarios/acc_lane_follow/acc_lane_follow_scenario.h"

#include "cyber/common/log.h"
#include "modules/planning/planning_base/gflags/planning_gflags.h"

namespace apollo {
namespace planning {

bool AccLaneFollowScenario::IsTransferable(const Scenario* other_scenario,
                                           const Frame& frame) {
  if (!FLAGS_enable_acc_lane_follow_scenario) {
    return false;
  }
  if (!frame.local_view().planning_command->has_lane_follow_command()) {
    return false;
  }
  if (frame.reference_line_info().empty()) {
    return false;
  }
  if (other_scenario != nullptr && other_scenario->Name() == Name()) {
    return false;
  }

  AINFO << "ACC_SCENARIO selected: reuse lane-follow speed pipeline";
  return true;
}

}  // namespace planning
}  // namespace apollo
