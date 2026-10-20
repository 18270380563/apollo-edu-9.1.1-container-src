
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-lane-follow-map",
    hdrs = glob(["include/modules/planning/pnc_map/lane_follow_map/**/*.h"]) + glob(["include/modules/planning/pnc_map/lane_follow_map/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)
