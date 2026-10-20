
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "control-vehicle-calibration",
    hdrs = glob(["include/modules/control/vehicle_calibration/**/*.h"]) + glob(["include/modules/control/vehicle_calibration/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Scontrol_Svehicle_calibration_Sproto_Ccalibration_table_proto",
    srcs = ["lib/modules/control/vehicle_calibration/proto/lib_calibration_table_proto_mcvp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
