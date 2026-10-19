load("//tools/proto:proto.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("//tools:python_rules.bzl", "py_proto_library")
load("//tools:apollo_package.bzl", "apollo_package")

package(default_visibility = ["//visibility:public"])


proto_library(
    name = "loam_velodyne_conf_proto",
    srcs = ["loam_velodyne_conf.proto"],
)

proto_library(
    name = "pointcloud2_proto",
    srcs = ["pointcloud2.proto"],
    deps = [
        "//modules/common_msgs/basic_msgs:header_proto"
    ]
)

proto_library(
    name = "localization_status_proto",
    srcs = ["localization_status.proto"],
)

proto_library(
    name = "odometry_proto",
    srcs = ["odometry.proto"],
    deps = [
        "//modules/common_msgs/basic_msgs:header_proto",
        "//modules/common_msgs/localization_msgs:pose_proto",
	"//modules/slam_local/proto:localization_status_proto"
    ]
)
proto_library(
    name = "cloudWithPoseInfo_proto",
    srcs = ["cloudWithPoseInfo.proto"],
    deps = [
        "//modules/common_msgs/basic_msgs:header_proto",
        "//modules/common_msgs/sensor_msgs:pointcloud_proto"
    ]
)


proto_library(
    name = "slam_pose_result_proto",
    srcs = ["slam_pose_result.proto"],
    deps = [
        "//modules/common_msgs/transform_msgs:transform_proto",
    ]
)

proto_library(
    name = "slam_service_proto",
    srcs = ["slam_service.proto"],
)

apollo_package()
