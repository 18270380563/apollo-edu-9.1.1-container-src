
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-speed-decider",
    hdrs = glob(["include/modules/planning/tasks/speed_decider/**/*.h"]) + glob(["include/modules/planning/tasks/speed_decider/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Sspeed_decider_Sproto_Cspeed_decider_proto",
    srcs = ["lib/modules/planning/tasks/speed_decider/proto/lib_speed_decider_proto_mptsp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
