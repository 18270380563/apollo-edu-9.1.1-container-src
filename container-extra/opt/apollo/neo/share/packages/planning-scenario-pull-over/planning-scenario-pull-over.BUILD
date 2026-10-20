
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-pull-over",
    hdrs = glob(["include/modules/planning/scenarios/pull_over/**/*.h"]) + glob(["include/modules/planning/scenarios/pull_over/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Sscenarios_Spull_over_Sproto_Cpull_over_proto",
    srcs = ["lib/modules/planning/scenarios/pull_over/proto/lib_pull_over_proto_mpspp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
