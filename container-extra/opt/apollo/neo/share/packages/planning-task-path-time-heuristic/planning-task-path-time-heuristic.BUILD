
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-path-time-heuristic",
    hdrs = glob(["include/modules/planning/tasks/path_time_heuristic/**/*.h"]) + glob(["include/modules/planning/tasks/path_time_heuristic/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Spath_time_heuristic_Sproto_Cpath_time_heuristic_proto",
    srcs = ["lib/modules/planning/tasks/path_time_heuristic/proto/lib_path_time_heuristic_proto_mptpp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
