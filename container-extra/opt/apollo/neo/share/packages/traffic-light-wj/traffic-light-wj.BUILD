
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "traffic-light-wj",
    hdrs = glob(["include/modules/traffic_light_wj/**/*.h"]) + glob(["include/modules/traffic_light_wj/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_CDO_NOT_IMPORT_traffic_light_wj_component",
    srcs = ["lib/modules/traffic_light_wj/libDO_NOT_IMPORT_traffic_light_wj_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Smonitor_msgs_Cmonitor_log_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Ctraffic_light_detection_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Smonitor_log_Cmonitor_log","@common//:modules_Scommon_Sstatus_Cstatus","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@traffic-light-wj//:modules_Straffic_light_wj_Scommon_Ctraffic_light_wj_common","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cobu_2_autopilot_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_commons_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_geometry_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_map_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_motion_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_rsi_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_rsm_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_spat_proto"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Scommon_Ctraffic_light_wj_common",
    srcs = ["lib/modules/traffic_light_wj/common/libtraffic_light_wj_common.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Sproto_Cautopilot_2_obu_proto",
    srcs = ["lib/modules/traffic_light_wj/proto/lib_autopilot_2_obu_proto_mtp_bin.so"],
    deps = ["@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_bsm_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_commons_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_geometry_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_motion_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_path_planning_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Sproto_Cobu_2_autopilot_proto",
    srcs = ["lib/modules/traffic_light_wj/proto/lib_obu_2_autopilot_proto_mtp_bin.so"],
    deps = ["@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_commons_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_geometry_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_map_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_motion_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_rsi_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_rsm_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_spat_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Sproto_Cv2r_bsm_proto",
    srcs = ["lib/modules/traffic_light_wj/proto/lib_v2r_bsm_proto_mtp_bin.so"],
    deps = ["@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_commons_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_geometry_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_motion_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Sproto_Cv2r_commons_proto",
    srcs = ["lib/modules/traffic_light_wj/proto/lib_v2r_commons_proto_mtp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Sproto_Cv2r_geometry_proto",
    srcs = ["lib/modules/traffic_light_wj/proto/lib_v2r_geometry_proto_mtp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Sproto_Cv2r_map_proto",
    srcs = ["lib/modules/traffic_light_wj/proto/lib_v2r_map_proto_mtp_bin.so"],
    deps = ["@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_commons_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_geometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Sproto_Cv2r_motion_proto",
    srcs = ["lib/modules/traffic_light_wj/proto/lib_v2r_motion_proto_mtp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Sproto_Cv2r_path_planning_proto",
    srcs = ["lib/modules/traffic_light_wj/proto/lib_v2r_path_planning_proto_mtp_bin.so"],
    deps = ["@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_commons_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_geometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Sproto_Cv2r_rsi_proto",
    srcs = ["lib/modules/traffic_light_wj/proto/lib_v2r_rsi_proto_mtp_bin.so"],
    deps = ["@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_commons_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_geometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Sproto_Cv2r_rsm_proto",
    srcs = ["lib/modules/traffic_light_wj/proto/lib_v2r_rsm_proto_mtp_bin.so"],
    deps = ["@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_commons_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_geometry_proto","@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_motion_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Straffic_light_wj_Sproto_Cv2r_spat_proto",
    srcs = ["lib/modules/traffic_light_wj/proto/lib_v2r_spat_proto_mtp_bin.so"],
    deps = ["@traffic-light-wj//:modules_Straffic_light_wj_Sproto_Cv2r_commons_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
