
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-free-space",
    hdrs = glob(["include/modules/planning/scenarios/free_space/**/*.h"]) + glob(["include/modules/planning/scenarios/free_space/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Sscenarios_Sfree_space_Sproto_Cfree_space_proto",
    srcs = ["lib/modules/planning/scenarios/free_space/proto/lib_free_space_proto_mpsfp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
