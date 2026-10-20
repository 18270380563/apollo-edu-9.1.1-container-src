
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-traffic-rules-backside-vehicle",
    hdrs = glob(["include/modules/planning/traffic_rules/backside_vehicle/**/*.h"]) + glob(["include/modules/planning/traffic_rules/backside_vehicle/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Straffic_rules_Sbackside_vehicle_Sproto_Cbackside_vehicle_proto",
    srcs = ["lib/modules/planning/traffic_rules/backside_vehicle/proto/lib_backside_vehicle_proto_mptbp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
