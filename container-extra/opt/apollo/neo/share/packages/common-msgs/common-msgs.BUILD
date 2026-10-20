
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "common-msgs",
    hdrs = glob(["include/modules/common_msgs/**/*.h"]) + glob(["include/modules/common_msgs/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Saudio_msgs_Caudio_common_proto",
    srcs = ["lib/modules/common_msgs/audio_msgs/lib_audio_common_proto_mca_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Saudio_msgs_Caudio_event_proto",
    srcs = ["lib/modules/common_msgs/audio_msgs/lib_audio_event_proto_mca_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Saudio_msgs_Caudio_common_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Saudio_msgs_Caudio_proto",
    srcs = ["lib/modules/common_msgs/audio_msgs/lib_audio_proto_mca_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Saudio_msgs_Caudio_common_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sbasic_msgs_Cdirection_proto",
    srcs = ["lib/modules/common_msgs/basic_msgs/lib_direction_proto_mcb_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sbasic_msgs_Cdrive_event_proto",
    srcs = ["lib/modules/common_msgs/basic_msgs/lib_drive_event_proto_mcb_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto",
    srcs = ["lib/modules/common_msgs/basic_msgs/lib_drive_state_proto_mcb_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto",
    srcs = ["lib/modules/common_msgs/basic_msgs/lib_error_code_proto_mcb_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto",
    srcs = ["lib/modules/common_msgs/basic_msgs/lib_geometry_proto_mcb_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sbasic_msgs_Cheader_proto",
    srcs = ["lib/modules/common_msgs/basic_msgs/lib_header_proto_mcb_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto",
    srcs = ["lib/modules/common_msgs/basic_msgs/lib_pnc_point_proto_mcb_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto",
    srcs = ["lib/modules/common_msgs/basic_msgs/lib_vehicle_id_proto_mcb_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto",
    srcs = ["lib/modules/common_msgs/basic_msgs/lib_vehicle_signal_proto_mcb_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Schassis_msgs_Cchassis_detail_proto",
    srcs = ["lib/modules/common_msgs/chassis_msgs/lib_chassis_detail_proto_mcc_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto","@common-msgs//:modules_Scommon_msgs_Schassis_msgs_Cchassis_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Schassis_msgs_Cchassis_proto",
    srcs = ["lib/modules/common_msgs/chassis_msgs/lib_chassis_proto_mcc_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sconfig_msgs_Cvehicle_config_proto",
    srcs = ["lib/modules/common_msgs/config_msgs/lib_vehicle_config_proto_mcc_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Scontrol_msgs_Ccontrol_cmd_proto",
    srcs = ["lib/modules/common_msgs/control_msgs/lib_control_cmd_proto_mcc_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto","@common-msgs//:modules_Scommon_msgs_Schassis_msgs_Cchassis_proto","@common-msgs//:modules_Scommon_msgs_Scontrol_msgs_Ccontrol_pad_msg_proto","@common-msgs//:modules_Scommon_msgs_Scontrol_msgs_Cinput_debug_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Scontrol_msgs_Ccontrol_interactive_msg_proto",
    srcs = ["lib/modules/common_msgs/control_msgs/lib_control_interactive_msg_proto_mcc_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Scontrol_msgs_Ccontrol_pad_msg_proto",
    srcs = ["lib/modules/common_msgs/control_msgs/lib_control_pad_msg_proto_mcc_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Scontrol_msgs_Cinput_debug_proto",
    srcs = ["lib/modules/common_msgs/control_msgs/lib_input_debug_proto_mcc_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sdreamview_msgs_Cchart_proto",
    srcs = ["lib/modules/common_msgs/dreamview_msgs/lib_chart_proto_mcd_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sdreamview_msgs_Chmi_config_proto",
    srcs = ["lib/modules/common_msgs/dreamview_msgs/lib_hmi_config_proto_mcd_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sdreamview_msgs_Chmi_mode_proto",
    srcs = ["lib/modules/common_msgs/dreamview_msgs/lib_hmi_mode_proto_mcd_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Chmi_status_proto","@common-msgs//:modules_Scommon_msgs_Smonitor_msgs_Csystem_status_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sdreamview_msgs_Chmi_status_proto",
    srcs = ["lib/modules/common_msgs/dreamview_msgs/lib_hmi_status_proto_mcd_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Smonitor_msgs_Csystem_status_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sdreamview_msgs_Csimulation_world_proto",
    srcs = ["lib/modules/common_msgs/dreamview_msgs/lib_simulation_world_proto_mcd_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto","@common-msgs//:modules_Scommon_msgs_Schassis_msgs_Cchassis_proto","@common-msgs//:modules_Scommon_msgs_Sconfig_msgs_Cvehicle_config_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Cchart_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_barrier_gate_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_clear_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_crosswalk_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_overlap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_parking_space_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_pnc_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_road_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_rsu_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_signal_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_speed_bump_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_stop_sign_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_yield_sign_proto","@common-msgs//:modules_Scommon_msgs_Smonitor_msgs_Cmonitor_log_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Ctraffic_light_detection_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cdecision_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cnavigation_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_internal_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Csl_boundary_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sdrivers_msgs_Ccan_card_parameter_proto",
    srcs = ["lib/modules/common_msgs/drivers_msgs/lib_can_card_parameter_proto_mcd_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sexternal_command_msgs_Caction_command_proto",
    srcs = ["lib/modules/common_msgs/external_command_msgs/lib_action_command_proto_mce_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sexternal_command_msgs_Cchassis_command_proto",
    srcs = ["lib/modules/common_msgs/external_command_msgs/lib_chassis_command_proto_mce_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sexternal_command_msgs_Ccommand_status_proto",
    srcs = ["lib/modules/common_msgs/external_command_msgs/lib_command_status_proto_mce_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sexternal_command_msgs_Cexternal_geometry_proto",
    srcs = ["lib/modules/common_msgs/external_command_msgs/lib_external_geometry_proto_mce_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sexternal_command_msgs_Cfree_space_command_proto",
    srcs = ["lib/modules/common_msgs/external_command_msgs/lib_free_space_command_proto_mce_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Cexternal_geometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sexternal_command_msgs_Clane_follow_command_proto",
    srcs = ["lib/modules/common_msgs/external_command_msgs/lib_lane_follow_command_proto_mce_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Cexternal_geometry_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Clane_segment_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sexternal_command_msgs_Clane_segment_proto",
    srcs = ["lib/modules/common_msgs/external_command_msgs/lib_lane_segment_proto_mce_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sexternal_command_msgs_Cpath_follow_command_proto",
    srcs = ["lib/modules/common_msgs/external_command_msgs/lib_path_follow_command_proto_mce_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Cexternal_geometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sexternal_command_msgs_Cspeed_command_proto",
    srcs = ["lib/modules/common_msgs/external_command_msgs/lib_speed_command_proto_mce_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sexternal_command_msgs_Cvalet_parking_command_proto",
    srcs = ["lib/modules/common_msgs/external_command_msgs/lib_valet_parking_command_proto_mce_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Cexternal_geometry_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Clane_segment_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sguardian_msgs_Cguardian_proto",
    srcs = ["lib/modules/common_msgs/guardian_msgs/lib_guardian_proto_mcg_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto","@common-msgs//:modules_Scommon_msgs_Schassis_msgs_Cchassis_proto","@common-msgs//:modules_Scommon_msgs_Scontrol_msgs_Ccontrol_cmd_proto","@common-msgs//:modules_Scommon_msgs_Scontrol_msgs_Ccontrol_pad_msg_proto","@common-msgs//:modules_Scommon_msgs_Scontrol_msgs_Cinput_debug_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Slocalization_msgs_Cgps_proto",
    srcs = ["lib/modules/common_msgs/localization_msgs/lib_gps_proto_mcl_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Slocalization_msgs_Cimu_proto",
    srcs = ["lib/modules/common_msgs/localization_msgs/lib_imu_proto_mcl_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto",
    srcs = ["lib/modules/common_msgs/localization_msgs/lib_localization_proto_mcl_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto",
    srcs = ["lib/modules/common_msgs/localization_msgs/lib_localization_status_proto_mcl_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Slocalization_msgs_Cpose_proto",
    srcs = ["lib/modules/common_msgs/localization_msgs/lib_pose_proto_mcl_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Slocalization_msgs_Ctrans_msg_proto",
    srcs = ["lib/modules/common_msgs/localization_msgs/lib_trans_msg_proto_mcl_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_area_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_area_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_barrier_gate_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_barrier_gate_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_clear_area_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_clear_area_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_crosswalk_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_crosswalk_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_geometry_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_id_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_id_proto_mcm_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_junction_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_junction_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_lane_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_overlap_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_overlap_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_parking_space_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_parking_space_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_pnc_junction_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_pnc_junction_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_barrier_gate_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_clear_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_crosswalk_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_overlap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_parking_space_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_pnc_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_road_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_rsu_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_signal_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_speed_bump_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_stop_sign_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_yield_sign_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_road_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_road_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_rsu_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_rsu_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_signal_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_signal_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_speed_bump_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_speed_bump_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_speed_control_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_speed_control_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_stop_sign_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_stop_sign_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smap_msgs_Cmap_yield_sign_proto",
    srcs = ["lib/modules/common_msgs/map_msgs/lib_map_yield_sign_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smonitor_msgs_Cmonitor_log_proto",
    srcs = ["lib/modules/common_msgs/monitor_msgs/lib_monitor_log_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smonitor_msgs_Csmart_recorder_status_proto",
    srcs = ["lib/modules/common_msgs/monitor_msgs/lib_smart_recorder_status_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Smonitor_msgs_Csystem_status_proto",
    srcs = ["lib/modules/common_msgs/monitor_msgs/lib_system_status_proto_mcm_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sperception_msgs_Cperception_benchmark_proto",
    srcs = ["lib/modules/common_msgs/perception_msgs/lib_perception_benchmark_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sperception_msgs_Cperception_camera_proto",
    srcs = ["lib/modules/common_msgs/perception_msgs/lib_perception_camera_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sperception_msgs_Cperception_lane_proto",
    srcs = ["lib/modules/common_msgs/perception_msgs/lib_perception_lane_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_camera_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto",
    srcs = ["lib/modules/common_msgs/perception_msgs/lib_perception_obstacle_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sperception_msgs_Ctraffic_light_detection_proto",
    srcs = ["lib/modules/common_msgs/perception_msgs/lib_traffic_light_detection_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Splanning_msgs_Cdecision_proto",
    srcs = ["lib/modules/common_msgs/planning_msgs/lib_decision_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Splanning_msgs_Cnavigation_proto",
    srcs = ["lib/modules/common_msgs/planning_msgs/lib_navigation_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_barrier_gate_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_clear_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_crosswalk_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_overlap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_parking_space_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_pnc_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_road_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_rsu_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_signal_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_speed_bump_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_stop_sign_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_yield_sign_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Splanning_msgs_Cpad_msg_proto",
    srcs = ["lib/modules/common_msgs/planning_msgs/lib_pad_msg_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Splanning_msgs_Cplanning_command_proto",
    srcs = ["lib/modules/common_msgs/planning_msgs/lib_planning_command_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Splanning_msgs_Cplanning_internal_proto",
    srcs = ["lib/modules/common_msgs/planning_msgs/lib_planning_internal_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto","@common-msgs//:modules_Scommon_msgs_Schassis_msgs_Cchassis_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Cchart_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_barrier_gate_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_clear_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_crosswalk_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_overlap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_parking_space_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_pnc_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_road_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_rsu_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_signal_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_speed_bump_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_stop_sign_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_yield_sign_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Ctraffic_light_detection_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cdecision_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cnavigation_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Csl_boundary_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Splanning_msgs_Cplanning_proto",
    srcs = ["lib/modules/common_msgs/planning_msgs/lib_planning_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdrive_state_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_id_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cvehicle_signal_proto","@common-msgs//:modules_Scommon_msgs_Schassis_msgs_Cchassis_proto","@common-msgs//:modules_Scommon_msgs_Sdreamview_msgs_Cchart_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Clocalization_status_proto","@common-msgs//:modules_Scommon_msgs_Slocalization_msgs_Cpose_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_barrier_gate_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_clear_area_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_crosswalk_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_overlap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_parking_space_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_pnc_junction_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_road_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_rsu_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_signal_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_speed_bump_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_stop_sign_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_yield_sign_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Ctraffic_light_detection_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cdecision_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cnavigation_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cplanning_internal_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Csl_boundary_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Splanning_msgs_Csl_boundary_proto",
    srcs = ["lib/modules/common_msgs/planning_msgs/lib_sl_boundary_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto",
    srcs = ["lib/modules/common_msgs/prediction_msgs/lib_feature_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto",
    srcs = ["lib/modules/common_msgs/prediction_msgs/lib_lane_graph_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sprediction_msgs_Cprediction_obstacle_proto",
    srcs = ["lib/modules/common_msgs/prediction_msgs/lib_prediction_obstacle_proto_mcp_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cscenario_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto",
    srcs = ["lib/modules/common_msgs/prediction_msgs/lib_prediction_point_proto_mcp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sprediction_msgs_Cscenario_proto",
    srcs = ["lib/modules/common_msgs/prediction_msgs/lib_scenario_proto_mcp_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Srouting_msgs_Cpoi_proto",
    srcs = ["lib/modules/common_msgs/routing_msgs/lib_poi_proto_mcr_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto",
    srcs = ["lib/modules/common_msgs/routing_msgs/lib_routing_geometry_proto_mcr_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Srouting_msgs_Crouting_proto",
    srcs = ["lib/modules/common_msgs/routing_msgs/lib_routing_proto_mcr_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cconti_radar_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_conti_radar_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cdelphi_esr_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_delphi_esr_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cgnss_best_pose_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_gnss_best_pose_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cgnss_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_gnss_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cgnss_raw_observation_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_gnss_raw_observation_proto_mcs_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cheading_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_heading_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cimu_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_imu_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cins_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_ins_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cmobileye_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_mobileye_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cnano_radar_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_nano_radar_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Coculii_radar_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_oculii_radar_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cpointcloud_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_pointcloud_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cracobit_radar_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_racobit_radar_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cradar_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_radar_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cradarpointcloud_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_radarpointcloud_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Csensor_image_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_sensor_image_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Csmartereye_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_smartereye_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssensor_msgs_Cultrasonic_radar_proto",
    srcs = ["lib/modules/common_msgs/sensor_msgs/lib_ultrasonic_radar_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssimulation_msgs_Cagent_proto",
    srcs = ["lib/modules/common_msgs/simulation_msgs/lib_agent_proto_mcs_bin.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssimulation_msgs_Cgrading_condition_proto",
    srcs = ["lib/modules/common_msgs/simulation_msgs/lib_grading_condition_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssimulation_msgs_Cgrading_metric_proto",
    srcs = ["lib/modules/common_msgs/simulation_msgs/lib_grading_metric_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cgrading_condition_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Ssimulation_msgs_Cscenario_proto",
    srcs = ["lib/modules/common_msgs/simulation_msgs/lib_scenario_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Ctraffic_light_detection_proto","@common-msgs//:modules_Scommon_msgs_Splanning_msgs_Cpad_msg_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cagent_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cgrading_condition_proto","@common-msgs//:modules_Scommon_msgs_Ssimulation_msgs_Cgrading_metric_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sstorytelling_msgs_Cstory_proto",
    srcs = ["lib/modules/common_msgs/storytelling_msgs/lib_story_proto_mcs_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Stask_manager_msgs_Ctask_manager_proto",
    srcs = ["lib/modules/common_msgs/task_manager_msgs/lib_task_manager_proto_mct_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Cexternal_geometry_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Clane_follow_command_proto","@common-msgs//:modules_Scommon_msgs_Sexternal_command_msgs_Clane_segment_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Cpoi_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_geometry_proto","@common-msgs//:modules_Scommon_msgs_Srouting_msgs_Crouting_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Stransform_msgs_Ctransform_proto",
    srcs = ["lib/modules/common_msgs/transform_msgs/lib_transform_proto_mct_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Scommon_msgs_Sv2x_msgs_Cv2x_traffic_light_proto",
    srcs = ["lib/modules/common_msgs/v2x_msgs/lib_v2x_traffic_light_proto_mcv_bin.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cdirection_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
