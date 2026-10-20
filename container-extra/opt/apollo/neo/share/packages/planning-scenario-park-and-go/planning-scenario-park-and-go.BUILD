
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-park-and-go",
    hdrs = glob(["include/modules/planning/scenarios/park_and_go/**/*.h"]) + glob(["include/modules/planning/scenarios/park_and_go/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Sscenarios_Spark_and_go_Sproto_Cpark_and_go_proto",
    srcs = ["lib/modules/planning/scenarios/park_and_go/proto/lib_park_and_go_proto_mpspp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
