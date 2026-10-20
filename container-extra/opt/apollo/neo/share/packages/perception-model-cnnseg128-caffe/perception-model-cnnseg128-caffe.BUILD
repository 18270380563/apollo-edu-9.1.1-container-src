
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "perception-model-cnnseg128-caffe",
    hdrs = glob(["include/modules/perception/data/models/cnnseg128_caffe/**/*.h"]) + glob(["include/modules/perception/data/models/cnnseg128_caffe/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)
