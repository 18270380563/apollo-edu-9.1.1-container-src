
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "perception-model-tl-detection-yolox",
    hdrs = glob(["include/modules/perception/data/models/tl_detection_yolox/**/*.h"]) + glob(["include/modules/perception/data/models/tl_detection_yolox/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)
