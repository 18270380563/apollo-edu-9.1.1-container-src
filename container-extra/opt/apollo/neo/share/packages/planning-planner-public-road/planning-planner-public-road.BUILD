
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-planner-public-road",
    hdrs = glob(["include/modules/planning/planners/public_road/**/*.h"]) + glob(["include/modules/planning/planners/public_road/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Splanners_Spublic_road_Sproto_Cplanner_config_proto",
    srcs = ["lib/modules/planning/planners/public_road/proto/lib_planner_config_proto_mpppp_bin.so"],
    deps = ["@planning-base//:modules_Splanning_Splanning_base_Sproto_Cplugin_declare_info_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
