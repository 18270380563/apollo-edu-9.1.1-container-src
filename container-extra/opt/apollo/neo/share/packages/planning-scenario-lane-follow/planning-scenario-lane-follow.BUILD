
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-lane-follow",
    hdrs = glob(["include/modules/planning/scenarios/lane_follow/**/*.h"]) + glob(["include/modules/planning/scenarios/lane_follow/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)
