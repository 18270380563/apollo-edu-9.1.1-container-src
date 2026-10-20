
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "safety-manager-msgs",
    hdrs = glob(["include/modules/safety_manager_msgs/**/*.h"]) + glob(["include/modules/safety_manager_msgs/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Ssafety_manager_msgs_Csafety_manager_proto",
    srcs = ["lib/modules/safety_manager_msgs/lib_safety_manager_proto_ms_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
