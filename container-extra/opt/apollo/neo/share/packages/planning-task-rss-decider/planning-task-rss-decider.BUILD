
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-rss-decider",
    hdrs = glob(["include/modules/planning/tasks/rss_decider/**/*.h"]) + glob(["include/modules/planning/tasks/rss_decider/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Srss_decider_Sproto_Crss_decider_proto",
    srcs = ["lib/modules/planning/tasks/rss_decider/proto/lib_rss_decider_proto_mptrp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
