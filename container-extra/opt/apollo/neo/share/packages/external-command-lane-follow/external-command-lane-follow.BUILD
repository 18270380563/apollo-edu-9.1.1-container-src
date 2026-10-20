
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "external-command-lane-follow",
    hdrs = glob(["include/modules/external_command/command_processor/lane_follow_command_processor/**/*.h"]) + glob(["include/modules/external_command/command_processor/lane_follow_command_processor/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)
