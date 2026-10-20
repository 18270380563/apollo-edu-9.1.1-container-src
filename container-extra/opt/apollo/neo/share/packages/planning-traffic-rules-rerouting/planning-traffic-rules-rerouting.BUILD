
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-traffic-rules-rerouting",
    hdrs = glob(["include/modules/planning/traffic_rules/rerouting/**/*.h"]) + glob(["include/modules/planning/traffic_rules/rerouting/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Straffic_rules_Srerouting_Sproto_Crerouting_proto",
    srcs = ["lib/modules/planning/traffic_rules/rerouting/proto/lib_rerouting_proto_mptrp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
