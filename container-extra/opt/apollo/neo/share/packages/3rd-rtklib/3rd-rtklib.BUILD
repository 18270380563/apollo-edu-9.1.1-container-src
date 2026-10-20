
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
cc_library(
    name = "3rd-rtklib",
    hdrs = glob(["include/third_party/rtklib/**/*.h"]) + glob(["include/third_party/rtklib/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


cc_library(
    name = "third_party_Srtklib_Crtklib",
    srcs = ["lib/third_party/rtklib/librtklib.so"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
