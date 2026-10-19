load("//tools/proto:proto.bzl", "apollo_py_library")
load("//tools:apollo_package.bzl", "apollo_package")

package(default_visibility = ["//visibility:public"])

apollo_py_library(
    name = "calibration_table_train_utils",
    srcs = ["calibration_table_train_utils.py"],
    deps = [
        ":calibration_table_utils",
        ":neural_network_tf",
        "//modules/control/control_component/proto:calibration_table_proto",
    ],
)

apollo_py_library(
    name = "calibration_table_utils",
    srcs = ["calibration_table_utils.py"],
    deps = [
        ":filters",
        "//modules/control/vehicle_calibration/common:file_utils",
        "//modules/control/vehicle_calibration/common:h5_utils",
        "//modules/control/vehicle_calibration/common:proto_utils",
        "//modules/control/vehicle_calibration/proto:calibration_table_proto",
        "//modules/common_msgs/config_msgs:vehicle_config_proto",
    ],
)

apollo_py_library(
    name = "filters",
    srcs = ["filters.py"],
)

apollo_py_library(
    name = "neural_network_tf",
    srcs = ["neural_network_tf.py"],
    deps = [
        "//modules/control/vehicle_calibration/common:logging",
    ],
)


apollo_package()
