
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "perception-model-yolox3d",
    hdrs = glob(["include/modules/perception/data/models/yolox3d_onnx/**/*.h"]) + glob(["include/modules/perception/data/models/yolox3d_onnx/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)
