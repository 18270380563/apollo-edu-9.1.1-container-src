
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-emergency-stop",
    hdrs = glob(["include/modules/planning/scenarios/emergency_stop/**/*.h"]) + glob(["include/modules/planning/scenarios/emergency_stop/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Sscenarios_Semergency_stop_Sproto_Cemergency_stop_proto",
    srcs = ["lib/modules/planning/scenarios/emergency_stop/proto/lib_emergency_stop_proto_mpsep_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
