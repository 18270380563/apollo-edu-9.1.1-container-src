
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "perception-plugin-onnx-multibatch-inference",
    hdrs = glob(["include/modules/perception/perception_plugin/onnx_multi_batch/**/*.h"]) + glob(["include/modules/perception/perception_plugin/onnx_multi_batch/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)
