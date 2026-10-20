
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-traffic-rules-reference-line-end",
    hdrs = glob(["include/modules/planning/traffic_rules/reference_line_end/**/*.h"]) + glob(["include/modules/planning/traffic_rules/reference_line_end/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Straffic_rules_Sreference_line_end_Sproto_Creference_line_end_proto",
    srcs = ["lib/modules/planning/traffic_rules/reference_line_end/proto/lib_reference_line_end_proto_mptrp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
