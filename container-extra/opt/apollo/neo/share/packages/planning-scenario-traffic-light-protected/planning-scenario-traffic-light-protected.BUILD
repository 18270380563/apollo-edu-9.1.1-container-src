
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-traffic-light-protected",
    hdrs = glob(["include/modules/planning/scenarios/traffic_light_protected/**/*.h"]) + glob(["include/modules/planning/scenarios/traffic_light_protected/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Sscenarios_Straffic_light_protected_Sproto_Ctraffic_light_protected_proto",
    srcs = ["lib/modules/planning/scenarios/traffic_light_protected/proto/lib_traffic_light_protected_proto_mpstp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
