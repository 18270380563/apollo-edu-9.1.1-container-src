
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-square",
    hdrs = glob(["include/modules/planning/scenarios/square/**/*.h"]) + glob(["include/modules/planning/scenarios/square/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Sscenarios_Ssquare_Sproto_Csquare_proto",
    srcs = ["lib/modules/planning/scenarios/square/proto/lib_square_proto_mpssp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
