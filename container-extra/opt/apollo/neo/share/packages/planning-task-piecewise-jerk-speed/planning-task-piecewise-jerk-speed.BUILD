
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-piecewise-jerk-speed",
    hdrs = glob(["include/modules/planning/tasks/piecewise_jerk_speed/**/*.h"]) + glob(["include/modules/planning/tasks/piecewise_jerk_speed/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Spiecewise_jerk_speed_Sproto_Cpiecewise_jerk_speed_proto",
    srcs = ["lib/modules/planning/tasks/piecewise_jerk_speed/proto/lib_piecewise_jerk_speed_proto_mptpp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
