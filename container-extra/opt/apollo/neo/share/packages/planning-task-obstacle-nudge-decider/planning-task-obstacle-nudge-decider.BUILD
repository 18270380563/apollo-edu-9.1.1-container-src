
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-obstacle-nudge-decider",
    hdrs = glob(["include/modules/planning/tasks/obstacle_nudge_decider/**/*.h"]) + glob(["include/modules/planning/tasks/obstacle_nudge_decider/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Sobstacle_nudge_decider_Sproto_Cobstacle_nudge_decider_proto",
    srcs = ["lib/modules/planning/tasks/obstacle_nudge_decider/proto/lib_obstacle_nudge_decider_proto_mptop_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
