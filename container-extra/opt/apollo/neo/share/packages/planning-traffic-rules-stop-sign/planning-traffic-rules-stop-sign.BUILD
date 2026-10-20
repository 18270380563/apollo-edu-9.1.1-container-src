
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-traffic-rules-stop-sign",
    hdrs = glob(["include/modules/planning/traffic_rules/stop_sign/**/*.h"]) + glob(["include/modules/planning/traffic_rules/stop_sign/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Straffic_rules_Sstop_sign_Sproto_Cstop_sign_proto",
    srcs = ["lib/modules/planning/traffic_rules/stop_sign/proto/lib_stop_sign_proto_mptsp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
