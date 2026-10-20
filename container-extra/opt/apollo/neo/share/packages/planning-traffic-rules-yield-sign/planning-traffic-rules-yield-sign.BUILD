
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-traffic-rules-yield-sign",
    hdrs = glob(["include/modules/planning/traffic_rules/yield_sign/**/*.h"]) + glob(["include/modules/planning/traffic_rules/yield_sign/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Straffic_rules_Syield_sign_Sproto_Cyield_sign_proto",
    srcs = ["lib/modules/planning/traffic_rules/yield_sign/proto/lib_yield_sign_proto_mptyp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
