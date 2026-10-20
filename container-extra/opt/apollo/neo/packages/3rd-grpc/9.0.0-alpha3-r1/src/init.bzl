load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def grpc_repo():
    http_archive(
        name = "com_github_grpc_grpc",
        sha256 = "2378b608557a4331c6a6a97f89a9257aee2f8e56a095ce6619eea62e288fcfbe",
        patches = ["//third_party/grpc:grpc.patch"],
        strip_prefix = "grpc-1.30.0",
        urls = [
            "https://apollo-system.cdn.bcebos.com/archive/8.0/v1.30.0-apollo.tar.gz",
        ],
    )

def init():
    grpc_repo()