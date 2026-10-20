
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-rule-based-stop-decider",
    hdrs = glob(["include/modules/planning/tasks/rule_based_stop_decider/**/*.h"]) + glob(["include/modules/planning/tasks/rule_based_stop_decider/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Srule_based_stop_decider_Sproto_Crule_based_stop_decider_proto",
    srcs = ["lib/modules/planning/tasks/rule_based_stop_decider/proto/lib_rule_based_stop_decider_proto_mptrp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
