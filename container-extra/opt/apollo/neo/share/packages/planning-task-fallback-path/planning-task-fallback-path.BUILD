
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-fallback-path",
    hdrs = glob(["include/modules/planning/tasks/fallback_path/**/*.h"]) + glob(["include/modules/planning/tasks/fallback_path/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Sfallback_path_Sproto_Cfallback_path_proto",
    srcs = ["lib/modules/planning/tasks/fallback_path/proto/lib_fallback_path_proto_mptfp_bin.so"],
    deps = ["@planning-base//:modules_Splanning_Splanning_base_Sproto_Cpiecewise_jerk_path_config_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
