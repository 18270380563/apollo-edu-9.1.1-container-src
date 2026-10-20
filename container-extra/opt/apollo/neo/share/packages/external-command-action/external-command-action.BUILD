
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "external-command-action",
    hdrs = glob(["include/modules/external_command/command_processor/action_command_processor/**/*.h"]) + glob(["include/modules/external_command/command_processor/action_command_processor/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Sexternal_command_Scommand_processor_Saction_command_processor_Sproto_Caction_command_config_proto",
    srcs = ["lib/modules/external_command/command_processor/action_command_processor/proto/lib_action_command_config_proto_mecap_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
