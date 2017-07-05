
workspace(name = "examples")

new_git_repository(
    name = "gtest",
    remote = "https://github.com/google/googletest.git",
    commit = "de411c3e80120f8dcc2a3f4f62f3ca692c0431d7",
    build_file_content =
"""
cc_library(
    name = "gtest",
    srcs = glob(
        [
            "google*/src/*.cc",
        ],
        exclude = glob([
            "google*/src/*-all.cc",
            "googlemock/src/gmock_main.cc",
        ]),
    ),
    hdrs = glob(["*/include/**/*.h"]),
    includes = [
        "googlemock/",
        "googlemock/include",
        "googletest/",
        "googletest/include",
    ],
    linkopts = ["-pthread"],
    textual_hdrs = ["googletest/src/gtest-internal-inl.h"],
    visibility = ["//visibility:public"],
)
"""
)

