
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-lane-borrow-path",
    hdrs = glob(["include/modules/planning/tasks/lane_borrow_path/**/*.h"]) + glob(["include/modules/planning/tasks/lane_borrow_path/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Slane_borrow_path_Sproto_Clane_borrow_path_proto",
    srcs = ["lib/modules/planning/tasks/lane_borrow_path/proto/lib_lane_borrow_path_proto_mptlp_bin.so"],
    deps = ["@planning-base//:modules_Splanning_Splanning_base_Sproto_Cpiecewise_jerk_path_config_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
