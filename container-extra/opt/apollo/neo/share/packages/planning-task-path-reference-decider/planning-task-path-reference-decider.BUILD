
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-path-reference-decider",
    hdrs = glob(["include/modules/planning/tasks/path_reference_decider/**/*.h"]) + glob(["include/modules/planning/tasks/path_reference_decider/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Spath_reference_decider_Sproto_Cpath_reference_decider_proto",
    srcs = ["lib/modules/planning/tasks/path_reference_decider/proto/lib_path_reference_decider_proto_mptpp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
