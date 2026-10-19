load("//tools/proto:proto.bzl", "apollo_py_library")
load("//tools:apollo_package.bzl", "apollo_package")

package(default_visibility = ["//visibility:public"])

apollo_py_library(
    name = "multi_job_utils",
    srcs = ["multi_job_utils.py"],
    deps = [
        ":file_utils",
        ":h5_utils",
        ":proto_utils",
        "//modules/control/vehicle_calibration/features:calibration_table_utils",
        "//modules/control/vehicle_calibration/proto:calibration_table_proto",
        "//modules/common_msgs/config_msgs:vehicle_config_proto",
    ],
)

apollo_py_library(
    name = "multi_vehicle_utils",
    srcs = ["multi_vehicle_utils.py"],
    deps = [
        ":file_utils",
        ":proto_utils",
        "//modules/control/vehicle_calibration/proto:calibration_table_proto",
        "//modules/common_msgs/config_msgs:vehicle_config_proto",
    ],
)

apollo_py_library(
    name = "h5_utils",
    srcs = ["h5_utils.py"],
    deps = [
        ":file_utils",
        ":logging",
    ],
)

apollo_py_library(
    name = "file_utils",
    srcs = ["file_utils.py"],
    deps = [
        ":logging",
    ],
)

apollo_py_library(
    name = "proto_utils",
    srcs = ["proto_utils.py"],
)

apollo_py_library(
    name = "logging",
    srcs = ["logging.py"],
)


apollo_package()
