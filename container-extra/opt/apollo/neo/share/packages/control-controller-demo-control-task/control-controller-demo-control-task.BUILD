
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "control-controller-demo-control-task",
    hdrs = glob(["include/modules/control/controllers/demo_control_task/**/*.h"]) + glob(["include/modules/control/controllers/demo_control_task/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Scontrol_Scontrollers_Sdemo_control_task_Sproto_Cdemo_control_task_conf_proto",
    srcs = ["lib/modules/control/controllers/demo_control_task/proto/lib_demo_control_task_conf_proto_mccdp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
