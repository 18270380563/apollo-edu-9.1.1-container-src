
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-st-bounds-decider",
    hdrs = glob(["include/modules/planning/tasks/st_bounds_decider/**/*.h"]) + glob(["include/modules/planning/tasks/st_bounds_decider/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Sst_bounds_decider_Sproto_Cst_bounds_decider_proto",
    srcs = ["lib/modules/planning/tasks/st_bounds_decider/proto/lib_st_bounds_decider_proto_mptsp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
