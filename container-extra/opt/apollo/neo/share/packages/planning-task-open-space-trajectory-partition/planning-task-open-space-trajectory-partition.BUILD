
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-open-space-trajectory-partition",
    hdrs = glob(["include/modules/planning/tasks/open_space_trajectory_partition/**/*.h"]) + glob(["include/modules/planning/tasks/open_space_trajectory_partition/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Sopen_space_trajectory_partition_Sproto_Copen_space_trajectory_partition_proto",
    srcs = ["lib/modules/planning/tasks/open_space_trajectory_partition/proto/lib_open_space_trajectory_partition_proto_mptop_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
