
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "control-controller-lon-based-pid-controller",
    hdrs = glob(["include/modules/control/controllers/lon_based_pid_controller/**/*.h"]) + glob(["include/modules/control/controllers/lon_based_pid_controller/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Scontrol_Scontrollers_Slon_based_pid_controller_Sproto_Clon_based_pid_controller_conf_proto",
    srcs = ["lib/modules/control/controllers/lon_based_pid_controller/proto/lib_lon_based_pid_controller_conf_proto_mcclp_bin.so"],
    deps = ["@control//:modules_Scontrol_Scontrol_component_Sproto_Cgain_scheduler_conf_proto","@control//:modules_Scontrol_Scontrol_component_Sproto_Cleadlag_conf_proto","@control//:modules_Scontrol_Scontrol_component_Sproto_Cpid_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
