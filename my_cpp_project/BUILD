cc_library(
    name = "add_lib",
    srcs = ["add.cpp"],
    hdrs = ["add.h"],
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":add_lib"],
)

cc_test(
    name = "add_test",
    srcs = ["add_test.cpp"],
    deps = [":add_lib"],
)
