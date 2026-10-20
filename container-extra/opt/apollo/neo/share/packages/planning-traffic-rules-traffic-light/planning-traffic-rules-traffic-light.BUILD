
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-traffic-rules-traffic-light",
    hdrs = glob(["include/modules/planning/traffic_rules/traffic_light/**/*.h"]) + glob(["include/modules/planning/traffic_rules/traffic_light/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Straffic_rules_Straffic_light_Sproto_Ctraffic_light_proto",
    srcs = ["lib/modules/planning/traffic_rules/traffic_light/proto/lib_traffic_light_proto_mpttp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
