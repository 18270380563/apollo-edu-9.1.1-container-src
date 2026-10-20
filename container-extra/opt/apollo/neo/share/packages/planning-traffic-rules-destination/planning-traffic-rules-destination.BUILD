
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-traffic-rules-destination",
    hdrs = glob(["include/modules/planning/traffic_rules/destination/**/*.h"]) + glob(["include/modules/planning/traffic_rules/destination/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Straffic_rules_Sdestination_Sproto_Cdestination_proto",
    srcs = ["lib/modules/planning/traffic_rules/destination/proto/lib_destination_proto_mptdp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
