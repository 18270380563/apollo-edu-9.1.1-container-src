
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "control-controller-antislip-control-task",
    hdrs = glob(["include/modules/control/controllers/slope_anti_slip_control_task/**/*.h"]) + glob(["include/modules/control/controllers/slope_anti_slip_control_task/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Scontrol_Scontrollers_Sslope_anti_slip_control_task_Sproto_Cantislip_control_task_conf_proto",
    srcs = ["lib/modules/control/controllers/slope_anti_slip_control_task/proto/lib_antislip_control_task_conf_proto_mccsp_bin.so"],
    deps = ["@control//:modules_Scontrol_Scontrol_component_Sproto_Cgain_scheduler_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
