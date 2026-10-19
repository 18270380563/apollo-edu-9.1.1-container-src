load("//tools/proto:proto.bzl", "proto_library")
load("//tools:apollo_package.bzl", "apollo_package")

package(default_visibility = ["//visibility:public"])

proto_library(
    name = "calibration_conf_proto",
    srcs = [
        "calibration_conf.proto",
    ],
)

proto_library(
    name = "error_code_proto",
    srcs = [
        "error_code.proto",
    ],
)

proto_library(
    name = "camera_proto",
    srcs = [
        "camera.proto",
    ],
)

proto_library(
    name = "point_cloud_proto",
    srcs = [
        "point_cloud.proto",
    ],
)

proto_library(
    name = "lidar_calib_message_proto",
    srcs = [
        "lidar_calib_message.proto",
    ],
    deps = [
        "//modules/dreamview_plus_plugins/calibration_tool/proto:error_code_proto",
    ]
)

apollo_package()
