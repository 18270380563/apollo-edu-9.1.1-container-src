
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "prediction",
    hdrs = glob(["include/modules/prediction/**/*.h"]) + glob(["include/modules/prediction/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Sprediction_CDO_NOT_IMPORT_prediction_component",
    srcs = ["lib/modules/prediction/libDO_NOT_IMPORT_prediction_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto","@common-msgs//:modules_Scommon_msgs_Schassis_msgs_Cchassis_proto","@common-msgs//:modules_Scommon_msgs_Sconfig_msgs_Cvehicle_config_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Cchart_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_barrier_gate_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_clear_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_crosswalk_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_overlap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_parking_space_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_pnc_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_road_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_rsu_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_signal_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_speed_bump_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_stop_sign_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_yield_sign_proto","@common-msgs//:modules_Scommon_msgs_Smonitor_msgs_Cmonitor_log_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Ctraffic_light_detection_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cdecision_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cnavigation_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_command_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_internal_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Csl_boundary_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cscenario_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cgnss_best_pose_proto","@common-msgs//:modules_Scommon_msgs_Sstorytelling_msgs_Cstory_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Sadapters_Sproto_Cadapter_config_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Sconfigs_Cvehicle_config_helper","@common//:modules_Scommon_Sfilters_Cfilters","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Smonitor_log_Cmonitor_log","@common//:modules_Scommon_Sstatus_Cstatus","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_lib","@common//:modules_Scommon_Sutil_Cutil_tool","@common//:modules_Scommon_Svehicle_state_Cvehicle_state_provider","@common//:modules_Scommon_Svehicle_state_Sproto_Cvehicle_state_proto","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@map//:modules_Smap_Capollo_map","@map//:modules_Smap_Srelative_map_Sproto_Crelative_map_config_proto","@prediction//:modules_Sprediction_Capollo_prediction","@prediction//:modules_Sprediction_Capollo_prediction_network","@prediction//:modules_Sprediction_Sproto_Cfnn_model_base_proto","@prediction//:modules_Sprediction_Sproto_Cfnn_vehicle_model_proto","@prediction//:modules_Sprediction_Sproto_Cnetwork_layers_proto","@prediction//:modules_Sprediction_Sproto_Cnetwork_model_proto","@prediction//:modules_Sprediction_Sproto_Coffline_features_proto","@prediction//:modules_Sprediction_Sproto_Cprediction_conf_proto","@prediction//:modules_Sprediction_Sproto_Cvector_net_proto"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sprediction_Capollo_prediction",
    srcs = ["lib/modules/prediction/libapollo_prediction.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto","@common-msgs//:modules_Scommon_msgs_Schassis_msgs_Cchassis_proto","@common-msgs//:modules_Scommon_msgs_Sconfig_msgs_Cvehicle_config_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Cchart_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_barrier_gate_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_clear_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_crosswalk_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_overlap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_parking_space_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_pnc_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_road_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_rsu_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_signal_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_speed_bump_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_stop_sign_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_yield_sign_proto","@common-msgs//:modules_Scommon_msgs_Smonitor_msgs_Cmonitor_log_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Ctraffic_light_detection_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cdecision_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cnavigation_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_command_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_internal_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Csl_boundary_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cscenario_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cgnss_best_pose_proto","@common-msgs//:modules_Scommon_msgs_Sstorytelling_msgs_Cstory_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Sadapters_Sproto_Cadapter_config_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Sconfigs_Cvehicle_config_helper","@common//:modules_Scommon_Sfilters_Cfilters","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Smonitor_log_Cmonitor_log","@common//:modules_Scommon_Sstatus_Cstatus","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_lib","@common//:modules_Scommon_Sutil_Cutil_tool","@common//:modules_Scommon_Svehicle_state_Cvehicle_state_provider","@common//:modules_Scommon_Svehicle_state_Sproto_Cvehicle_state_proto","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@map//:modules_Smap_Capollo_map","@map//:modules_Smap_Srelative_map_Sproto_Crelative_map_config_proto","@prediction//:modules_Sprediction_Capollo_prediction_network","@prediction//:modules_Sprediction_Sproto_Cfnn_model_base_proto","@prediction//:modules_Sprediction_Sproto_Cfnn_vehicle_model_proto","@prediction//:modules_Sprediction_Sproto_Cnetwork_layers_proto","@prediction//:modules_Sprediction_Sproto_Cnetwork_model_proto","@prediction//:modules_Sprediction_Sproto_Coffline_features_proto","@prediction//:modules_Sprediction_Sproto_Cprediction_conf_proto","@prediction//:modules_Sprediction_Sproto_Cvector_net_proto"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sprediction_Capollo_prediction_network",
    srcs = ["lib/modules/prediction/libapollo_prediction_network.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_lib","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@prediction//:modules_Sprediction_Sproto_Cnetwork_layers_proto","@prediction//:modules_Sprediction_Sproto_Cnetwork_model_proto"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sprediction_Sproto_Cfnn_model_base_proto",
    srcs = ["lib/modules/prediction/proto/lib_fnn_model_base_proto_mpp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sprediction_Sproto_Cfnn_vehicle_model_proto",
    srcs = ["lib/modules/prediction/proto/lib_fnn_vehicle_model_proto_mpp_bin.so"],
    deps = ["@prediction//:modules_Sprediction_Sproto_Cfnn_model_base_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sprediction_Sproto_Cnetwork_layers_proto",
    srcs = ["lib/modules/prediction/proto/lib_network_layers_proto_mpp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sprediction_Sproto_Cnetwork_model_proto",
    srcs = ["lib/modules/prediction/proto/lib_network_model_proto_mpp_bin.so"],
    deps = ["@prediction//:modules_Sprediction_Sproto_Cnetwork_layers_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sprediction_Sproto_Coffline_features_proto",
    srcs = ["lib/modules/prediction/proto/lib_offline_features_proto_mpp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cscenario_proto","@prediction//:modules_Sprediction_Sproto_Cprediction_conf_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sprediction_Sproto_Cprediction_conf_proto",
    srcs = ["lib/modules/prediction/proto/lib_prediction_conf_proto_mpp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sprediction_Sproto_Cvector_net_proto",
    srcs = ["lib/modules/prediction/proto/lib_vector_net_proto_mpp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
