
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-traffic-light-unprotected-right-turn",
    hdrs = glob(["include/modules/planning/scenarios/traffic_light_unprotected_right_turn/**/*.h"]) + glob(["include/modules/planning/scenarios/traffic_light_unprotected_right_turn/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Sscenarios_Straffic_light_unprotected_right_turn_Sproto_Ctraffic_light_unprotected_right_turn_proto",
    srcs = ["lib/modules/planning/scenarios/traffic_light_unprotected_right_turn/proto/lib_traffic_light_unprotected_right_turn_proto_mpstp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto","@planning-interface-base//:modules_Splanning_Splanning_interface_base_Sscenario_base_Sproto_Ccreep_stage_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
