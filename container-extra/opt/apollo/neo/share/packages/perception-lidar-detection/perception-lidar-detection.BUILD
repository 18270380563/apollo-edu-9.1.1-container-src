
load("@rules_cc//cc:defs.bzl", "cc_library", "cc_import")
load("@apollo_src//tools:apollo_package.bzl", "apollo_deps_library")
cc_library(
    name = "perception-lidar-detection",
    hdrs = glob(["include/modules/perception/lidar_detection/**/*.h"]) + glob(["include/modules/perception/lidar_detection/**/*.hpp"]),
    srcs = [],
    strip_include_prefix = "include",
    visibility = ["//visibility:public"],
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_CDO_NOT_IMPORT_lidar_detection_component",
    srcs = ["lib/modules/perception/lidar_detection/libDO_NOT_IMPORT_lidar_detection_component.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_benchmark_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@perception-common//:modules_Sperception_Scommon_Cperception_common_util","@perception-common//:modules_Sperception_Scommon_Cperception_gflags","@perception-common//:modules_Sperception_Scommon_Salgorithm_Capollo_perception_common_algorithm","@perception-common//:modules_Sperception_Scommon_Sbase_Capollo_perception_common_base","@perception-common//:modules_Sperception_Scommon_Scamera_Capollo_perception_common_camera_camera_frame","@perception-common//:modules_Sperception_Scommon_Sinference_Capollo_perception_common_inference","@perception-common//:modules_Sperception_Scommon_Sinference_Cinference_lib","@perception-common//:modules_Sperception_Scommon_Sinference_Clayer_lib","@perception-common//:modules_Sperception_Scommon_Sinference_Cperception_inference_operators_cuda","@perception-common//:modules_Sperception_Scommon_Sinference_Stensorrt_Capollo_perception_common_inference_tensorrt_plugins","@perception-common//:modules_Sperception_Scommon_Sinference_Stensorrt_Capollo_perception_inference_rt_common","@perception-common//:modules_Sperception_Scommon_Sinference_Stensorrt_Capollo_perception_inference_rt_net","@perception-common//:modules_Sperception_Scommon_Sinference_Sutils_Capollo_perception_common_utils","@perception-common//:modules_Sperception_Scommon_Slib_Capollo_perception_common_lib","@perception-common//:modules_Sperception_Scommon_Slidar_Capollo_perception_common_lidar","@perception-common//:modules_Sperception_Scommon_Slidar_Capollo_perception_common_lidar_common","@perception-common//:modules_Sperception_Scommon_Slidar_Capollo_perception_common_lidar_scene_manager","@perception-common//:modules_Sperception_Scommon_Slidar_Sscene_manager_Sground_service_Sproto_Cground_service_config_proto","@perception-common//:modules_Sperception_Scommon_Slidar_Sscene_manager_Sproto_Cscene_manager_config_proto","@perception-common//:modules_Sperception_Scommon_Slidar_Sscene_manager_Sroi_service_Sproto_Croi_service_proto","@perception-common//:modules_Sperception_Scommon_Sonboard_Capollo_perception_common_onboard","@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_info_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_process_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Cperception_config_schema_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Cplugin_param_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Crt_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Csensor_meta_schema_proto","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Canchor_mask_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Capollo_perception_lidar_detection","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Ccnn_segmentation_util","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cfeature_generator_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cnms_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpfe_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpoint_pillars_common","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpoint_pillars_postprocess_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpreprocess_points_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cscatter_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Sdetector_Scenter_point_detection_Sproto_Ccenter_point_model_param_proto","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Sdetector_Scnn_segmentation_Sproto_Cmodel_param_proto","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Sdetector_Smask_pillars_detection_Sproto_Cmodel_param_proto","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Sdetector_Spoint_pillars_detection_Sproto_Cmodel_param_proto","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Sproto_Clidar_detection_component_config_proto","@transform//:modules_Stransform_Capollo_transform"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Canchor_mask_cuda",
    srcs = ["lib/modules/perception/lidar_detection/libanchor_mask_cuda.so"],
    deps = ["@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpoint_pillars_common"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Capollo_perception_lidar_detection",
    srcs = ["lib/modules/perception/lidar_detection/libapollo_perception_lidar_detection.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_benchmark_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto","@common-msgs//:modules_Scommon_msgs_Stransform_msgs_Ctransform_proto","@common//:modules_Scommon_Sadapters_Cadapter_gflags","@common//:modules_Scommon_Sconfigs_Cconfig_gflags","@common//:modules_Scommon_Smath_Cmath","@common//:modules_Scommon_Smath_Sqp_solver_Cqp_solver","@common//:modules_Scommon_Sutil_Ccommon_util","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@perception-common//:modules_Sperception_Scommon_Cperception_common_util","@perception-common//:modules_Sperception_Scommon_Cperception_gflags","@perception-common//:modules_Sperception_Scommon_Salgorithm_Capollo_perception_common_algorithm","@perception-common//:modules_Sperception_Scommon_Sbase_Capollo_perception_common_base","@perception-common//:modules_Sperception_Scommon_Scamera_Capollo_perception_common_camera_camera_frame","@perception-common//:modules_Sperception_Scommon_Sinference_Capollo_perception_common_inference","@perception-common//:modules_Sperception_Scommon_Sinference_Cinference_lib","@perception-common//:modules_Sperception_Scommon_Sinference_Clayer_lib","@perception-common//:modules_Sperception_Scommon_Sinference_Cperception_inference_operators_cuda","@perception-common//:modules_Sperception_Scommon_Sinference_Stensorrt_Capollo_perception_common_inference_tensorrt_plugins","@perception-common//:modules_Sperception_Scommon_Sinference_Stensorrt_Capollo_perception_inference_rt_common","@perception-common//:modules_Sperception_Scommon_Sinference_Stensorrt_Capollo_perception_inference_rt_net","@perception-common//:modules_Sperception_Scommon_Sinference_Sutils_Capollo_perception_common_utils","@perception-common//:modules_Sperception_Scommon_Slib_Capollo_perception_common_lib","@perception-common//:modules_Sperception_Scommon_Slidar_Capollo_perception_common_lidar","@perception-common//:modules_Sperception_Scommon_Slidar_Capollo_perception_common_lidar_common","@perception-common//:modules_Sperception_Scommon_Slidar_Capollo_perception_common_lidar_scene_manager","@perception-common//:modules_Sperception_Scommon_Slidar_Sscene_manager_Sground_service_Sproto_Cground_service_config_proto","@perception-common//:modules_Sperception_Scommon_Slidar_Sscene_manager_Sproto_Cscene_manager_config_proto","@perception-common//:modules_Sperception_Scommon_Slidar_Sscene_manager_Sroi_service_Sproto_Croi_service_proto","@perception-common//:modules_Sperception_Scommon_Sonboard_Capollo_perception_common_onboard","@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_info_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_process_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Cperception_config_schema_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Cplugin_param_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Crt_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Csensor_meta_schema_proto","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Canchor_mask_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Ccnn_segmentation_util","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cfeature_generator_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cnms_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpfe_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpoint_pillars_common","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpoint_pillars_postprocess_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpreprocess_points_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cscatter_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Sdetector_Scenter_point_detection_Sproto_Ccenter_point_model_param_proto","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Sdetector_Scnn_segmentation_Sproto_Cmodel_param_proto","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Sdetector_Smask_pillars_detection_Sproto_Cmodel_param_proto","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Sdetector_Spoint_pillars_detection_Sproto_Cmodel_param_proto","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Sproto_Clidar_detection_component_config_proto","@transform//:modules_Stransform_Capollo_transform"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Ccnn_segmentation_util",
    srcs = ["lib/modules/perception/lidar_detection/libcnn_segmentation_util.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Cfeature_generator_cuda",
    srcs = ["lib/modules/perception/lidar_detection/libfeature_generator_cuda.so"],
    deps = ["@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cerror_code_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cgeometry_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cheader_proto","@common-msgs//:modules_Scommon_msgs_Sbasic_msgs_Cpnc_point_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_geometry_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_id_proto","@common-msgs//:modules_Scommon_msgs_Smap_msgs_Cmap_lane_proto","@common-msgs//:modules_Scommon_msgs_Sperception_msgs_Cperception_obstacle_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cfeature_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Clane_graph_proto","@common-msgs//:modules_Scommon_msgs_Sprediction_msgs_Cprediction_point_proto","@common//:modules_Scommon_Sutil_Cmessage_util","@common//:modules_Scommon_Sutil_Cutil_tool","@cyber//:cyber_Ccyber","@cyber//:cyber_Ccyber_binary","@cyber//:cyber_Ccyber_state","@cyber//:cyber_Sbase_Ccyber_base","@cyber//:cyber_Sblocker_Ccyber_blocker","@cyber//:cyber_Sclass_loader_Ccyber_class_loader","@cyber//:cyber_Sclass_loader_Sshared_library_Cshared_library","@cyber//:cyber_Sclass_loader_Sutility_Cclass_loader_utility","@cyber//:cyber_Scommon_Ccyber_common","@cyber//:cyber_Scomponent_Ccyber_component","@cyber//:cyber_Scontext_Ccyber_context","@cyber//:cyber_Scroutine_Ccyber_croutine","@cyber//:cyber_Sdata_Ccyber_data","@cyber//:cyber_Sevent_Ccyber_event","@cyber//:cyber_Sio_Ccyber_io","@cyber//:cyber_Slogger_Ccyber_logger","@cyber//:cyber_Smessage_Ccyber_message","@cyber//:cyber_Snode_Ccyber_node","@cyber//:cyber_Sparameter_Ccyber_parameter","@cyber//:cyber_Splugin_manager_Ccyber_plugin_manager","@cyber//:cyber_Sprofiler_Ccyber_profiler","@cyber//:cyber_Sproto_Cchoreography_conf_proto","@cyber//:cyber_Sproto_Cclassic_conf_proto","@cyber//:cyber_Sproto_Cclock_proto","@cyber//:cyber_Sproto_Ccomponent_conf_proto","@cyber//:cyber_Sproto_Ccyber_conf_proto","@cyber//:cyber_Sproto_Cparameter_proto","@cyber//:cyber_Sproto_Cperf_conf_proto","@cyber//:cyber_Sproto_Cproto_desc_proto","@cyber//:cyber_Sproto_Cqos_profile_proto","@cyber//:cyber_Sproto_Crecord_proto","@cyber//:cyber_Sproto_Crole_attributes_proto","@cyber//:cyber_Sproto_Crun_mode_conf_proto","@cyber//:cyber_Sproto_Cscheduler_conf_proto","@cyber//:cyber_Sproto_Ctopology_change_proto","@cyber//:cyber_Sproto_Ctransport_conf_proto","@cyber//:cyber_Srecord_Ccyber_record","@cyber//:cyber_Sscheduler_Ccyber_scheduler","@cyber//:cyber_Sservice_Ccyber_service","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery","@cyber//:cyber_Sservice_discovery_Ccyber_service_discovery_role","@cyber//:cyber_Sstatistics_Capollo_statistics","@cyber//:cyber_Ssysmo_Ccyber_sysmo","@cyber//:cyber_Stask_Ccyber_task","@cyber//:cyber_Stime_Ccyber_time","@cyber//:cyber_Stimer_Ccyber_timer","@cyber//:cyber_Stransport_Ccyber_transport","@perception-common//:modules_Sperception_Scommon_Sbase_Capollo_perception_common_base","@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_info_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_process_proto","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Ccnn_segmentation_util","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Sdetector_Scnn_segmentation_Sproto_Cmodel_param_proto"],
    linkopts = ["-lbvar"],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Cnms_cuda",
    srcs = ["lib/modules/perception/lidar_detection/libnms_cuda.so"],
    deps = ["@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpoint_pillars_common"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Cpfe_cuda",
    srcs = ["lib/modules/perception/lidar_detection/libpfe_cuda.so"],
    deps = ["@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpoint_pillars_common"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Cpoint_pillars_common",
    srcs = ["lib/modules/perception/lidar_detection/libpoint_pillars_common.so"],
    deps = [],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Cpoint_pillars_postprocess_cuda",
    srcs = ["lib/modules/perception/lidar_detection/libpoint_pillars_postprocess_cuda.so"],
    deps = ["@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cnms_cuda","@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpoint_pillars_common"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Cpreprocess_points_cuda",
    srcs = ["lib/modules/perception/lidar_detection/libpreprocess_points_cuda.so"],
    deps = ["@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpoint_pillars_common"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Cscatter_cuda",
    srcs = ["lib/modules/perception/lidar_detection/libscatter_cuda.so"],
    deps = ["@perception-lidar-detection//:modules_Sperception_Slidar_detection_Cpoint_pillars_common"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Sdetector_Scenter_point_detection_Sproto_Ccenter_point_model_param_proto",
    srcs = ["lib/modules/perception/lidar_detection/detector/center_point_detection/proto/lib_center_point_model_param_proto_mpldcp_bin.so"],
    deps = ["@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_info_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_process_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Sdetector_Scnn_segmentation_Sproto_Cmodel_param_proto",
    srcs = ["lib/modules/perception/lidar_detection/detector/cnn_segmentation/proto/lib_model_param_proto_mpldcp_bin.so"],
    deps = ["@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_info_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_process_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Sdetector_Smask_pillars_detection_Sproto_Cmodel_param_proto",
    srcs = ["lib/modules/perception/lidar_detection/detector/mask_pillars_detection/proto/lib_model_param_proto_mpldmp_bin.so"],
    deps = ["@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_info_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_process_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Sdetector_Spoint_pillars_detection_Sproto_Cmodel_param_proto",
    srcs = ["lib/modules/perception/lidar_detection/detector/point_pillars_detection/proto/lib_model_param_proto_mpldpp_bin.so"],
    deps = ["@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_info_proto","@perception-common//:modules_Sperception_Scommon_Sproto_Cmodel_process_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)


apollo_deps_library(
    name = "modules_Sperception_Slidar_detection_Sproto_Clidar_detection_component_config_proto",
    srcs = ["lib/modules/perception/lidar_detection/proto/lib_lidar_detection_component_config_proto_mplp_bin.so"],
    deps = ["@perception-common//:modules_Sperception_Scommon_Sproto_Cplugin_param_proto"],
    linkopts = [],
    visibility = ["//visibility:public"],
    alwayslink = True,
)
