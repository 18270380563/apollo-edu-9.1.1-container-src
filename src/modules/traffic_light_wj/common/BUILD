load("//tools:apollo_package.bzl","apollo_package", "apollo_cc_library")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

apollo_cc_library(
    name = "traffic_light_wj_common",
    srcs = ["traffic_light_wj_gflags.cc"],
    hdrs = ["traffic_light_wj_gflags.h"],
    deps = [
        "@com_github_gflags_gflags//:gflags",
    ],
)
apollo_package()
cpplint()
