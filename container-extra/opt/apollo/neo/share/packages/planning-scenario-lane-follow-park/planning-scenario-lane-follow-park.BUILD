
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-lane-follow-park",
    hdrs = glob(["include/modules/planning/scenarios/lane_follow_park/**/*.h"]) + glob(["include/modules/planning/scenarios/lane_follow_park/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Sscenarios_Slane_follow_park_Sproto_Clane_follow_park_proto",
    srcs = ["lib/modules/planning/scenarios/lane_follow_park/proto/lib_lane_follow_park_proto_mpslp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
