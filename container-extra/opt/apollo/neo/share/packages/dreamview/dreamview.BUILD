
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "dreamview",
    hdrs = glob(["include/modules/dreamview/**/*.h"]) + glob(["include/modules/dreamview/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Sdreamview_Sbackend_Capollo_dreamview_backend",
    srcs = ["lib/modules/dreamview/backend/libapollo_dreamview_backend.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Saudio_msgs_Caudio_common_proto","@common-msgs//:modules_Scommon_msgs_Saudio_msgs_Caudio_event_proto","@common-msgs//:modules_Scommon_msgs_Saudio_msgs_Caudio_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_event_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto","@common-msgs//:modules_Scommon_msgs_Schassis_msgs_Cchassis_proto","@common-msgs//:modules_Scommon_msgs_Sconfig_msgs_Cvehicle_config_proto","@common-msgs//:modules_Scommon_msgs_Scontrol_msgs_Ccontrol_cmd_proto","@common-msgs//:modules_Scommon_msgs_Scontrol_msgs_Ccontrol_pad_msg_proto","@common-msgs//:modules_Scommon_msgs_Scontrol_msgs_Cinput_debug_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Cchart_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Chmi_config_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Chmi_mode_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Chmi_status_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Csimulation_world_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Caction_command_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Ccommand_status_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Cexternal_geometry_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Clane_follow_command_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Clane_segment_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Cvalet_parking_command_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cgps_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_barrier_gate_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_clear_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_crosswalk_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_overlap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_parking_space_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_pnc_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_road_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_rsu_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_signal_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_speed_bump_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_stop_sign_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_yield_sign_proto","@common-msgs//:modules_Scommon_msgs_Smonitor_msgs_Cmonitor_log_proto","@common-msgs//:modules_Scommon_msgs_Smonitor_msgs_Csystem_status_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Ctraffic_light_detection_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cdecision_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cnavigation_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cpad_msg_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_command_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_internal_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Csl_boundary_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cscenario_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cgnss_best_pose_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Csensor_image_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cagent_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cgrading_condition_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cgrading_metric_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cscenario_proto","@common-msgs//:modules_Scommon_msgs_Sstorytelling_msgs_Cstory_proto","@common-msgs//:modules_Scommon_msgs_Stask_manager_msgs_Ctask_manager_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Sconfigs_Cvehicle_config_helper","@common//:modules_Scommon_Skv_db_Ckv_db","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Smonitor_log_Cmonitor_log","@common//:modules_Scommon_Sstatus_Cstatus","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@common//:modules_Scommon_Svehicle_state_Cvehicle_state_provider","@common//:modules_Scommon_Svehicle_state_Sproto_Cvehicle_state_proto","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cdag_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@dreamview//:modules_Sdreamview_Sbackend_Scommon_Cdreamview_common","@dreamview//:modules_Sdreamview_Sbackend_Scommon_Ssim_control_manager_Sproto_Cdynamic_model_conf_proto","@dreamview//:modules_Sdreamview_Sbackend_Scommon_Ssim_control_manager_Sproto_Csim_control_internal_proto","@dreamview//:modules_Sdreamview_Sproto_Ccamera_update_proto","@dreamview//:modules_Sdreamview_Sproto_Cdata_collection_table_proto","@dreamview//:modules_Sdreamview_Sproto_Cdv_plugin_msg_proto","@dreamview//:modules_Sdreamview_Sproto_Cplugin_config_proto","@dreamview//:modules_Sdreamview_Sproto_Cpoint_cloud_proto","@dreamview//:modules_Sdreamview_Sproto_Cpreprocess_table_proto","@dreamview//:modules_Sdreamview_Sproto_Crecord_proto","@dreamview//:modules_Sdreamview_Sproto_Cscenario_proto","@map//:modules_Smap_Capollo_map","@map//:modules_Smap_Srelative_map_Sproto_Crelative_map_config_proto","@transform//:modules_Stransform_Capollo_transform"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sbackend_Scommon_Cdreamview_common",
    srcs = ["lib/modules/dreamview/backend/common/libdreamview_common.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto","@common-msgs//:modules_Scommon_msgs_Schassis_msgs_Cchassis_proto","@common-msgs//:modules_Scommon_msgs_Sconfig_msgs_Cvehicle_config_proto","@common-msgs//:modules_Scommon_msgs_Scontrol_msgs_Ccontrol_cmd_proto","@common-msgs//:modules_Scommon_msgs_Scontrol_msgs_Ccontrol_pad_msg_proto","@common-msgs//:modules_Scommon_msgs_Scontrol_msgs_Cinput_debug_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Cchart_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Chmi_config_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Chmi_mode_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Chmi_status_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Csimulation_world_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_barrier_gate_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_clear_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_crosswalk_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_overlap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_parking_space_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_pnc_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_road_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_rsu_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_signal_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_speed_bump_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_stop_sign_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_yield_sign_proto","@common-msgs//:modules_Scommon_msgs_Smonitor_msgs_Cmonitor_log_proto","@common-msgs//:modules_Scommon_msgs_Smonitor_msgs_Csystem_status_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Ctraffic_light_detection_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cdecision_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cnavigation_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_command_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_internal_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Csl_boundary_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cscenario_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Cgnss_best_pose_proto","@common-msgs//:modules_Scommon_msgs_Ssensor_msgs_Csensor_image_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Sconfigs_Cvehicle_config_helper","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Smonitor_log_Cmonitor_log","@common//:modules_Scommon_Sstatus_Cstatus","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@common//:modules_Scommon_Svehicle_state_Cvehicle_state_provider","@common//:modules_Scommon_Svehicle_state_Sproto_Cvehicle_state_proto","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@dreamview//:modules_Sdreamview_Sbackend_Scommon_Ssim_control_manager_Sproto_Cdynamic_model_conf_proto","@dreamview//:modules_Sdreamview_Sbackend_Scommon_Ssim_control_manager_Sproto_Csim_control_internal_proto","@dreamview//:modules_Sdreamview_Sproto_Cdata_collection_table_proto","@dreamview//:modules_Sdreamview_Sproto_Cdv_plugin_msg_proto","@dreamview//:modules_Sdreamview_Sproto_Cplugin_config_proto","@dreamview//:modules_Sdreamview_Sproto_Cpreprocess_table_proto","@map//:modules_Smap_Capollo_map","@map//:modules_Smap_Srelative_map_Sproto_Crelative_map_config_proto"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sbackend_Scommon_Ssim_control_manager_Sproto_Cdynamic_model_conf_proto",
    srcs = ["lib/modules/dreamview/backend/common/sim_control_manager/proto/lib_dynamic_model_conf_proto_mdbcsp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sbackend_Scommon_Ssim_control_manager_Sproto_Csim_control_internal_proto",
    srcs = ["lib/modules/dreamview/backend/common/sim_control_manager/proto/lib_sim_control_internal_proto_mdbcsp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sbackend_Scommon_Steleop_Sproto_Cdaemon_cmd_proto",
    srcs = ["lib/modules/dreamview/backend/common/teleop/proto/lib_daemon_cmd_proto_mdbctp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sbackend_Scommon_Steleop_Sproto_Cdaemon_rpt_proto",
    srcs = ["lib/modules/dreamview/backend/common/teleop/proto/lib_daemon_rpt_proto_mdbctp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sbackend_Scommon_Steleop_Sproto_Cmodem_info_proto",
    srcs = ["lib/modules/dreamview/backend/common/teleop/proto/lib_modem_info_proto_mdbctp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sproto_Ccamera_update_proto",
    srcs = ["lib/modules/dreamview/proto/lib_camera_update_proto_mdp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sproto_Cdata_collection_table_proto",
    srcs = ["lib/modules/dreamview/proto/lib_data_collection_table_proto_mdp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sproto_Cdv_plugin_msg_proto",
    srcs = ["lib/modules/dreamview/proto/lib_dv_plugin_msg_proto_mdp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sproto_Cplugin_config_proto",
    srcs = ["lib/modules/dreamview/proto/lib_plugin_config_proto_mdp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sproto_Cpoint_cloud_proto",
    srcs = ["lib/modules/dreamview/proto/lib_point_cloud_proto_mdp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sproto_Cpreprocess_table_proto",
    srcs = ["lib/modules/dreamview/proto/lib_preprocess_table_proto_mdp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sproto_Crecord_proto",
    srcs = ["lib/modules/dreamview/proto/lib_record_proto_mdp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sdreamview_Sproto_Cscenario_proto",
    srcs = ["lib/modules/dreamview/proto/lib_scenario_proto_mdp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Ctraffic_light_detection_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cpad_msg_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cagent_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cgrading_condition_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cgrading_metric_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cscenario_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
