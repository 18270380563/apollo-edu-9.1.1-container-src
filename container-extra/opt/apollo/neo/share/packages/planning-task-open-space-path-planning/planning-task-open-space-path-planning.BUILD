
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-task-open-space-path-planning",
    hdrs = glob(["include/modules/planning/tasks/open_space_path_planning/**/*.h"]) + glob(["include/modules/planning/tasks/open_space_path_planning/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Stasks_Sopen_space_path_planning_Sproto_Copen_space_path_planning_proto",
    srcs = ["lib/modules/planning/tasks/open_space_path_planning/proto/lib_open_space_path_planning_proto_mptop_bin.so"],
    deps = ["@planning-base//:modules_Splanning_Splanning_base_Sproto_Smath_Cfem_pos_deviation_smoother_config_proto","@planning-open-space//:modules_Splanning_Splanning_open_space_Sproto_Cplanner_open_space_config_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
