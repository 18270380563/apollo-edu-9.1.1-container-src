
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-traffic-rules-keepclear",
    hdrs = glob(["include/modules/planning/traffic_rules/keepclear/**/*.h"]) + glob(["include/modules/planning/traffic_rules/keepclear/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Straffic_rules_Skeepclear_Sproto_Ckeepclear_proto",
    srcs = ["lib/modules/planning/traffic_rules/keepclear/proto/lib_keepclear_proto_mptkp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
