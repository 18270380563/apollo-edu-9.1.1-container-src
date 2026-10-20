
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-reverse-speed",
    hdrs = glob(["include/modules/planning/tasks/reverse_speed/**/*.h"]) + glob(["include/modules/planning/tasks/reverse_speed/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Sreverse_speed_Sproto_Creverse_speed_proto",
    srcs = ["lib/modules/planning/tasks/reverse_speed/proto/lib_reverse_speed_proto_mptrp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
