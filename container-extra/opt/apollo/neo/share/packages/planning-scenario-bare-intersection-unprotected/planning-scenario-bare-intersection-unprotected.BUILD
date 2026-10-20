
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-bare-intersection-unprotected",
    hdrs = glob(["include/modules/planning/scenarios/bare_intersection_unprotected/**/*.h"]) + glob(["include/modules/planning/scenarios/bare_intersection_unprotected/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Sscenarios_Sbare_intersection_unprotected_Sproto_Cbare_intersection_unprotected_scenario_proto",
    srcs = ["lib/modules/planning/scenarios/bare_intersection_unprotected/proto/lib_bare_intersection_unprotected_scenario_proto_mpsbp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
