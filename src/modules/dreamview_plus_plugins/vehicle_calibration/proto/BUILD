load("//tools/proto:proto.bzl", "proto_library")
load("//tools:apollo_package.bzl", "apollo_package")

package(default_visibility = ["//visibility:public"])

proto_library(
    name = "vehicle_calib_conf_proto",
    srcs = [
        "vehicle_calibration_conf.proto",
    ],
)

proto_library(
    name = "error_code_proto",
    srcs = [
        "error_code.proto",
    ],
)

proto_library(
    name = "calib_result_proto",
    srcs = [
        "calib_result.proto",
    ],
)

proto_library(
    name = "vehicle_param_conf_proto",
    srcs = [
        "vehicle_param.proto",
    ],
)

proto_library(
    name = "calibration_table_conf_proto",
    srcs = [
        "calibration_table_conf.proto",
    ],
)

apollo_package()
