
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "drivers-lidar",
    hdrs = glob(["include/modules/drivers/lidar/**/*.h"]) + glob(["include/modules/drivers/lidar/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_CDO_NOT_IMPORT_lidar_driver_component",
    srcs = ["lib/modules/drivers/lidar/libDO_NOT_IMPORT_lidar_driver_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sdriver_factory_Capollo_lidar_driver_base","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sdriver_factory_Clidar_driver_factory","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cconfig_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Clidar_parameter_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Svelodyne_Sdriver_Cvelodyne_driver_lib","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Scommon_Clidar_common",
    srcs = ["lib/modules/drivers/lidar/common/liblidar_common.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Scommon_Sdriver_factory_Capollo_lidar_driver_base",
    srcs = ["lib/modules/drivers/lidar/common/driver_factory/libapollo_lidar_driver_base.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Scommon_Sdriver_factory_Clidar_driver_factory",
    srcs = ["lib/modules/drivers/lidar/common/driver_factory/liblidar_driver_factory.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sdriver_factory_Capollo_lidar_driver_base","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cconfig_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Clidar_parameter_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Svelodyne_Sdriver_Cvelodyne_driver_lib","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto",
    srcs = ["lib/modules/drivers/lidar/common/proto/lib_lidar_config_base_proto_mdlcp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Scompensator_CDO_NOT_IMPORT_compensator_component",
    srcs = ["lib/modules/drivers/lidar/compensator/libDO_NOT_IMPORT_compensator_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Slatency_recorder_Clatency_recorder","@common//:modules_Scommon_Slatency_recorder_Sproto_Clatency_record_proto","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scompensator_Sproto_Ccompensator_config_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib","@transform//:modules_Stransform_Capollo_transform"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Scompensator_Sproto_Ccompensator_config_proto",
    srcs = ["lib/modules/drivers/lidar/compensator/proto/lib_compensator_config_proto_mdlcp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Sfusion_CDO_NOT_IMPORT_fusion_component",
    srcs = ["lib/modules/drivers/lidar/fusion/libDO_NOT_IMPORT_fusion_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Sfusion_Sproto_Cfusion_config_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib","@transform//:modules_Stransform_Capollo_transform"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Sfusion_Sproto_Cfusion_config_proto",
    srcs = ["lib/modules/drivers/lidar/fusion/proto/lib_fusion_config_proto_mdlfp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Shesai_CDO_NOT_IMPORT_hesai_driver_component",
    srcs = ["lib/modules/drivers/lidar/hesai/libDO_NOT_IMPORT_hesai_driver_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sdriver_factory_Capollo_lidar_driver_base","@drivers-lidar//:modules_Sdrivers_Slidar_Shesai_Chesai_convert_component","@drivers-lidar//:modules_Sdrivers_Slidar_Shesai_Sdriver_Capollo_hesai_driver","@drivers-lidar//:modules_Sdrivers_Slidar_Shesai_Sdriver_Chesai_component","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cconfig_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Clidar_parameter_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Shesai_Chesai_convert_component",
    srcs = ["lib/modules/drivers/lidar/hesai/libhesai_convert_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sdriver_factory_Capollo_lidar_driver_base","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cconfig_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Clidar_parameter_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Shesai_Sdriver_Capollo_hesai_driver",
    srcs = ["lib/modules/drivers/lidar/hesai/driver/libapollo_hesai_driver.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sdriver_factory_Capollo_lidar_driver_base","@drivers-lidar//:modules_Sdrivers_Slidar_Shesai_Chesai_convert_component","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cconfig_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Clidar_parameter_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Shesai_Sdriver_Chesai_component",
    srcs = ["lib/modules/drivers/lidar/hesai/driver/libhesai_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sdriver_factory_Capollo_lidar_driver_base","@drivers-lidar//:modules_Sdrivers_Slidar_Shesai_Chesai_convert_component","@drivers-lidar//:modules_Sdrivers_Slidar_Shesai_Sdriver_Capollo_hesai_driver","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cconfig_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Clidar_parameter_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Shslidar_CDO_NOT_IMPORT_hesai_driver_component_2",
    srcs = ["lib/modules/drivers/lidar/hslidar/libDO_NOT_IMPORT_hesai_driver_component_2.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Clidar_common","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Shslidar_Sproto_Chesai_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Shslidar_Sproto_Chesai_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lhesai2-driver","-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Shslidar_Sproto_Chesai_config_proto",
    srcs = ["lib/modules/drivers/lidar/hslidar/proto/lib_hesai_config_proto_mdlhp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Shslidar_Sproto_Chesai_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Shslidar_Sproto_Chesai_proto",
    srcs = ["lib/modules/drivers/lidar/hslidar/proto/lib_hesai_proto_mdlhp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Slivox_CDO_NOT_IMPORT_livox_component",
    srcs = ["lib/modules/drivers/lidar/livox/libDO_NOT_IMPORT_livox_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Clidar_common","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Slivox_Sproto_Clivox_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-llivox_lidar_sdk_shared","-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Slivox_Sproto_Clivox_proto",
    srcs = ["lib/modules/drivers/lidar/livox/proto/lib_livox_proto_mdllp_bin.so"],
    deps = ["@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Slslidar_CDO_NOT_IMPORT_lslidar_component",
    srcs = ["lib/modules/drivers/lidar/lslidar/libDO_NOT_IMPORT_lslidar_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Clidar_common","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Slslidar_Sdriver_Cdriver","@drivers-lidar//:modules_Sdrivers_Slidar_Slslidar_Sparser_Cconvert","@drivers-lidar//:modules_Sdrivers_Slidar_Slslidar_Sproto_Cconfig_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Slslidar_Sproto_Clslidar_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Slslidar_Sdriver_Cdriver",
    srcs = ["lib/modules/drivers/lidar/lslidar/driver/libdriver.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Slslidar_Sproto_Cconfig_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Slslidar_Sproto_Clslidar_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Slslidar_Sparser_Cconvert",
    srcs = ["lib/modules/drivers/lidar/lslidar/parser/libconvert.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Slslidar_Sproto_Cconfig_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Slslidar_Sproto_Clslidar_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Slslidar_Sproto_Cconfig_proto",
    srcs = ["lib/modules/drivers/lidar/lslidar/proto/lib_config_proto_mdllp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Slslidar_Sproto_Clslidar_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Slslidar_Sproto_Clslidar_proto",
    srcs = ["lib/modules/drivers/lidar/lslidar/proto/lib_lslidar_proto_mdllp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Sproto_Cconfig_proto",
    srcs = ["lib/modules/drivers/lidar/proto/lib_config_proto_mdlp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Clidar_parameter_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Sproto_Chesai_config_proto",
    srcs = ["lib/modules/drivers/lidar/proto/lib_hesai_config_proto_mdlp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Sproto_Chesai_proto",
    srcs = ["lib/modules/drivers/lidar/proto/lib_hesai_proto_mdlp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Sproto_Clidar_parameter_proto",
    srcs = ["lib/modules/drivers/lidar/proto/lib_lidar_parameter_proto_mdlp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto",
    srcs = ["lib/modules/drivers/lidar/proto/lib_velodyne_config_proto_mdlp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto",
    srcs = ["lib/modules/drivers/lidar/proto/lib_velodyne_proto_mdlp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Srslidar_CDO_NOT_IMPORT_rslidar_component",
    srcs = ["lib/modules/drivers/lidar/rslidar/libDO_NOT_IMPORT_rslidar_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Clidar_common","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Srslidar_Sproto_Crslidar_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Srslidar_Sproto_Crslidar_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Srslidar_Sproto_Crslidar_config_proto",
    srcs = ["lib/modules/drivers/lidar/rslidar/proto/lib_rslidar_config_proto_mdlrp_bin.so"],
    deps = ["@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sproto_Clidar_config_base_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Srslidar_Sproto_Crslidar_proto",
    srcs = ["lib/modules/drivers/lidar/rslidar/proto/lib_rslidar_proto_mdlrp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Svelodyne_Scompensator_CDO_NOT_IMPORT_velodyne_compensator_component",
    srcs = ["lib/modules/drivers/lidar/velodyne/compensator/libDO_NOT_IMPORT_velodyne_compensator_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Slatency_recorder_Clatency_recorder","@common//:modules_Scommon_Slatency_recorder_Sproto_Clatency_record_proto","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib","@transform//:modules_Stransform_Capollo_transform"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Svelodyne_Sdriver_CDO_NOT_IMPORT_velodyne_driver_component",
    srcs = ["lib/modules/drivers/lidar/velodyne/driver/libDO_NOT_IMPORT_velodyne_driver_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sdriver_factory_Capollo_lidar_driver_base","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cconfig_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Clidar_parameter_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Svelodyne_Sdriver_Cvelodyne_driver_lib","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Svelodyne_Sdriver_Cvelodyne_driver_lib",
    srcs = ["lib/modules/drivers/lidar/velodyne/driver/libvelodyne_driver_lib.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Scommon_Sdriver_factory_Capollo_lidar_driver_base","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cconfig_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Chesai_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Clidar_parameter_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Svelodyne_Sfusion_CDO_NOT_IMPORT_velodyne_fusion_component",
    srcs = ["lib/modules/drivers/lidar/velodyne/fusion/libDO_NOT_IMPORT_velodyne_fusion_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib","@transform//:modules_Stransform_Capollo_transform"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdrivers_Slidar_Svelodyne_Sparser_CDO_NOT_IMPORT_velodyne_convert_component",
    srcs = ["lib/modules/drivers/lidar/velodyne/parser/libDO_NOT_IMPORT_velodyne_convert_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_config_proto","@drivers-lidar//:modules_Sdrivers_Slidar_Sproto_Cvelodyne_proto","@placeholder-3rd-rtklib//:third_party_Srtklib_Crtklib"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
