
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "cyber",
    hdrs = glob(["include/cyber/**/*.h"]) + glob(["include/cyber/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "cyber_Ccyber",
    srcs = ["lib/cyber/libcyber.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Ccyber_binary",
    srcs = ["lib/cyber/libcyber_binary.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Ccyber_state",
    srcs = ["lib/cyber/libcyber_state.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sbase_Ccyber_base",
    srcs = ["lib/cyber/base/libcyber_base.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sbenchmark_Cbenchmark_msg_proto",
    srcs = ["lib/cyber/benchmark/lib_benchmark_msg_proto_cb_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sblocker_Ccyber_blocker",
    srcs = ["lib/cyber/blocker/libcyber_blocker.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sclass_loader_Ccyber_class_loader",
    srcs = ["lib/cyber/class_loader/libcyber_class_loader.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sclass_loader_Sshared_library_Cshared_library",
    srcs = ["lib/cyber/class_loader/shared_library/libshared_library.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sclass_loader_Sutility_Cclass_loader_utility",
    srcs = ["lib/cyber/class_loader/utility/libclass_loader_utility.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Scommon_Ccyber_common",
    srcs = ["lib/cyber/common/libcyber_common.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Scomponent_Ccyber_component",
    srcs = ["lib/cyber/component/libcyber_component.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Scontext_Ccyber_context",
    srcs = ["lib/cyber/context/libcyber_context.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Scroutine_Ccyber_croutine",
    srcs = ["lib/cyber/croutine/libcyber_croutine.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sdata_Ccyber_data",
    srcs = ["lib/cyber/data/libcyber_data.so"],
    deps = ["@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Cqos_profile_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sevent_Ccyber_event",
    srcs = ["lib/cyber/event/libcyber_event.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sexamples_Scommon_component_example_CDO_NOT_IMPORT_common_component_example",
    srcs = ["lib/cyber/examples/common_component_example/libDO_NOT_IMPORT_common_component_example.so"],
    deps = ["@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sexamples_Sproto_Cexamples_proto","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sexamples_Sproto_Cexamples_proto",
    srcs = ["lib/cyber/examples/proto/lib_examples_proto_cep_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sexamples_Stimer_component_example_CDO_NOT_IMPORT_timer_component_example",
    srcs = ["lib/cyber/examples/timer_component_example/libDO_NOT_IMPORT_timer_component_example.so"],
    deps = ["@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sexamples_Sproto_Cexamples_proto","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sio_Ccyber_io",
    srcs = ["lib/cyber/io/libcyber_io.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Slogger_Ccyber_logger",
    srcs = ["lib/cyber/logger/libcyber_logger.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Smessage_Ccyber_message",
    srcs = ["lib/cyber/message/libcyber_message.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Snode_Ccyber_node",
    srcs = ["lib/cyber/node/libcyber_node.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sparameter_Ccyber_parameter",
    srcs = ["lib/cyber/parameter/libcyber_parameter.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Splugin_manager_Ccyber_plugin_manager",
    srcs = ["lib/cyber/plugin_manager/libcyber_plugin_manager.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sprofiler_Ccyber_profiler",
    srcs = ["lib/cyber/profiler/libcyber_profiler.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Cchoreography_conf_proto",
    srcs = ["lib/cyber/proto/lib_choreography_conf_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Cclassic_conf_proto",
    srcs = ["lib/cyber/proto/lib_classic_conf_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Cclock_proto",
    srcs = ["lib/cyber/proto/lib_clock_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Ccomponent_conf_proto",
    srcs = ["lib/cyber/proto/lib_component_conf_proto_cp_bin.so"],
    deps = ["@cyber//:cyber_Sproto_Cqos_profile_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Ccyber_conf_proto",
    srcs = ["lib/cyber/proto/lib_cyber_conf_proto_cp_bin.so"],
    deps = ["@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Cdag_conf_proto",
    srcs = ["lib/cyber/proto/lib_dag_conf_proto_cp_bin.so"],
    deps = ["@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Cqos_profile_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Cparameter_proto",
    srcs = ["lib/cyber/proto/lib_parameter_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Cperf_conf_proto",
    srcs = ["lib/cyber/proto/lib_perf_conf_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Cproto_desc_proto",
    srcs = ["lib/cyber/proto/lib_proto_desc_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Cqos_profile_proto",
    srcs = ["lib/cyber/proto/lib_qos_profile_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Crecord_proto",
    srcs = ["lib/cyber/proto/lib_record_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Crole_attributes_proto",
    srcs = ["lib/cyber/proto/lib_role_attributes_proto_cp_bin.so"],
    deps = ["@cyber//:cyber_Sproto_Cqos_profile_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Crun_mode_conf_proto",
    srcs = ["lib/cyber/proto/lib_run_mode_conf_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Cscheduler_conf_proto",
    srcs = ["lib/cyber/proto/lib_scheduler_conf_proto_cp_bin.so"],
    deps = ["@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Csimple_proto",
    srcs = ["lib/cyber/proto/lib_simple_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Ctopology_change_proto",
    srcs = ["lib/cyber/proto/lib_topology_change_proto_cp_bin.so"],
    deps = ["@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crole_attributes_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Ctransport_conf_proto",
    srcs = ["lib/cyber/proto/lib_transport_conf_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sproto_Cunit_test_proto",
    srcs = ["lib/cyber/proto/lib_unit_test_proto_cp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Spython_Sinternal_Cpy_cyber",
    srcs = ["lib/cyber/python/internal/libpy_cyber.so"],
    deps = ["@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Spython_Sinternal_Cpy_parameter",
    srcs = ["lib/cyber/python/internal/libpy_parameter.so"],
    deps = ["@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Spython_Sinternal_Cpy_cyber","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Spython_Sinternal_Cpy_record",
    srcs = ["lib/cyber/python/internal/libpy_record.so"],
    deps = ["@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Spython_Sinternal_Cpy_time",
    srcs = ["lib/cyber/python/internal/libpy_time.so"],
    deps = ["@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Spython_Sinternal_Cpy_timer",
    srcs = ["lib/cyber/python/internal/libpy_timer.so"],
    deps = ["@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Srecord_Ccyber_record",
    srcs = ["lib/cyber/record/libcyber_record.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sscheduler_Ccyber_scheduler",
    srcs = ["lib/cyber/scheduler/libcyber_scheduler.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sservice_Ccyber_service",
    srcs = ["lib/cyber/service/libcyber_service.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sservice_discovery_Ccyber_service_discovery",
    srcs = ["lib/cyber/service_discovery/libcyber_service_discovery.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sservice_discovery_Ccyber_service_discovery_role",
    srcs = ["lib/cyber/service_discovery/libcyber_service_discovery_role.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Sstatistics_Capollo_statistics",
    srcs = ["lib/cyber/statistics/libapollo_statistics.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Ssysmo_Ccyber_sysmo",
    srcs = ["lib/cyber/sysmo/libcyber_sysmo.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Stask_Ccyber_task",
    srcs = ["lib/cyber/task/libcyber_task.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Stime_Ccyber_time",
    srcs = ["lib/cyber/time/libcyber_time.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Stimer_Ccyber_timer",
    srcs = ["lib/cyber/timer/libcyber_timer.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Stools_Scyber_recorder_Crecorder",
    srcs = ["lib/cyber/tools/cyber_recorder/librecorder.so"],
    deps = ["@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "cyber_Stransport_Ccyber_transport",
    srcs = ["lib/cyber/transport/libcyber_transport.so"],
    deps = ["@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
