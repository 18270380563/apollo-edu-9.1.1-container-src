
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-traffic-rules-crosswalk",
    hdrs = glob(["include/modules/planning/traffic_rules/crosswalk/**/*.h"]) + glob(["include/modules/planning/traffic_rules/crosswalk/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Straffic_rules_Scrosswalk_Sproto_Ccrosswalk_proto",
    srcs = ["lib/modules/planning/traffic_rules/crosswalk/proto/lib_crosswalk_proto_mptcp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
