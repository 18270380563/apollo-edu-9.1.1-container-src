
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-large-curvature",
    hdrs = glob(["include/modules/planning/scenarios/large_curvature/**/*.h"]) + glob(["include/modules/planning/scenarios/large_curvature/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Sscenarios_Slarge_curvature_Sproto_Clarge_curvature_proto",
    srcs = ["lib/modules/planning/scenarios/large_curvature/proto/lib_large_curvature_proto_mpslp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
