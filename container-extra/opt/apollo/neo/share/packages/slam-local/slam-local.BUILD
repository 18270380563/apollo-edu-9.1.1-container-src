
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "slam-local",
    hdrs = glob(["include/modules/slam_local/**/*.h"]) + glob(["include/modules/slam_local/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Sslam_local_CDO_NOT_IMPORT_laser_multiscan_registration_component",
    srcs = ["lib/modules/slam_local/libDO_NOT_IMPORT_laser_multiscan_registration_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cgps_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cimu_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cgnss_best_pose_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@slam-local//:modules_Sslam_local_Scommon_Cgtsam","@slam-local//:modules_Sslam_local_Scommon_Claser_odometry_common","@slam-local//:modules_Sslam_local_Scommon_Cslam_gflag","@slam-local//:modules_Sslam_local_Sproto_CcloudWithPoseInfo_proto","@slam-local//:modules_Sslam_local_Sproto_Cloam_velodyne_conf_proto","@slam-local//:modules_Sslam_local_Sproto_Clocalization_status_proto","@slam-local//:modules_Sslam_local_Sproto_Codometry_proto","@transform//:modules_Stransform_Capollo_transform"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_CDO_NOT_IMPORT_laser_odometry_component",
    srcs = ["lib/modules/slam_local/libDO_NOT_IMPORT_laser_odometry_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cgps_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cimu_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cgnss_best_pose_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@slam-local//:modules_Sslam_local_Scommon_Cgtsam","@slam-local//:modules_Sslam_local_Scommon_Claser_odometry_common","@slam-local//:modules_Sslam_local_Scommon_Cslam_gflag","@slam-local//:modules_Sslam_local_Sproto_CcloudWithPoseInfo_proto","@slam-local//:modules_Sslam_local_Sproto_Cloam_velodyne_conf_proto","@slam-local//:modules_Sslam_local_Sproto_Clocalization_status_proto","@slam-local//:modules_Sslam_local_Sproto_Codometry_proto","@transform//:modules_Stransform_Capollo_transform"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_CDO_NOT_IMPORT_localization_mapping_node_component",
    srcs = ["lib/modules/slam_local/libDO_NOT_IMPORT_localization_mapping_node_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cgps_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cimu_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cgnss_best_pose_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@slam-local//:modules_Sslam_local_CGeographic","@slam-local//:modules_Sslam_local_Scommon_Cgtsam","@slam-local//:modules_Sslam_local_Scommon_Claser_odometry_common","@slam-local//:modules_Sslam_local_Scommon_Cslam_gflag","@slam-local//:modules_Sslam_local_Sproto_CcloudWithPoseInfo_proto","@slam-local//:modules_Sslam_local_Sproto_Cloam_velodyne_conf_proto","@slam-local//:modules_Sslam_local_Sproto_Clocalization_status_proto","@slam-local//:modules_Sslam_local_Sproto_Codometry_proto","@slam-local//:modules_Sslam_local_Sproto_Cslam_pose_result_proto","@slam-local//:modules_Sslam_local_Sproto_Cslam_service_proto","@transform//:modules_Stransform_Capollo_transform"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_CGeographic",
    srcs = ["lib/modules/slam_local/libGeographic.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_Cgtsam",
    srcs = ["lib/modules/slam_local/libgtsam.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_Scommon_Cgtsam",
    srcs = ["lib/modules/slam_local/common/libgtsam.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_Scommon_Claser_odometry_common",
    srcs = ["lib/modules/slam_local/common/liblaser_odometry_common.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cgps_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cimu_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cgnss_best_pose_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@slam-local//:modules_Sslam_local_Scommon_Cgtsam","@slam-local//:modules_Sslam_local_Scommon_Cslam_gflag","@slam-local//:modules_Sslam_local_Sproto_CcloudWithPoseInfo_proto","@slam-local//:modules_Sslam_local_Sproto_Cloam_velodyne_conf_proto","@slam-local//:modules_Sslam_local_Sproto_Clocalization_status_proto","@slam-local//:modules_Sslam_local_Sproto_Codometry_proto","@transform//:modules_Stransform_Capollo_transform"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_Scommon_Cslam_gflag",
    srcs = ["lib/modules/slam_local/common/libslam_gflag.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_Sproto_CcloudWithPoseInfo_proto",
    srcs = ["lib/modules/slam_local/proto/lib_cloudWithPoseInfo_proto_msp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_Sproto_Cloam_velodyne_conf_proto",
    srcs = ["lib/modules/slam_local/proto/lib_loam_velodyne_conf_proto_msp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_Sproto_Clocalization_status_proto",
    srcs = ["lib/modules/slam_local/proto/lib_localization_status_proto_msp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_Sproto_Codometry_proto",
    srcs = ["lib/modules/slam_local/proto/lib_odometry_proto_msp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@slam-local//:modules_Sslam_local_Sproto_Clocalization_status_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_Sproto_Cpointcloud2_proto",
    srcs = ["lib/modules/slam_local/proto/lib_pointcloud2_proto_msp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_Sproto_Cslam_pose_result_proto",
    srcs = ["lib/modules/slam_local/proto/lib_slam_pose_result_proto_msp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sslam_local_Sproto_Cslam_service_proto",
    srcs = ["lib/modules/slam_local/proto/lib_slam_service_proto_msp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
