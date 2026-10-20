
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "map-creator-plugin",
    hdrs = glob(["include/modules/dreamview_plus_plugins/map_creator_tool/**/*.h"]) + glob(["include/modules/dreamview_plus_plugins/map_creator_tool/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Sdreamview_plus_plugins_Smap_creator_tool_Sproto_Cerror_code_proto",
    srcs = ["lib/modules/dreamview_plus_plugins/map_creator_tool/proto/lib_error_code_proto_mdmp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
