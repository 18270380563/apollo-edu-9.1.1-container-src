
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "planning-scenario-valet-parking-park",
    hdrs = glob(["include/modules/planning/scenarios/valet_parking_park/**/*.h"]) + glob(["include/modules/planning/scenarios/valet_parking_park/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Splanning_Sscenarios_Svalet_parking_park_Sproto_Cvalet_parking_park_proto",
    srcs = ["lib/modules/planning/scenarios/valet_parking_park/proto/lib_valet_parking_park_proto_mpsvp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
