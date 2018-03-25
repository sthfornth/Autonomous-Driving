package(default_visibility = ["//visibility:public"])

cc_library(
	name = "side",
	srcs = ["side.cc"],
	hdrs = ["side.h"]
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [":side",],
)


