
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "perception-model-efficient-net",
    hdrs = glob(["include/modules/perception/data/models/efficient_net/**/*.h"]) + glob(["include/modules/perception/data/models/efficient_net/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)
