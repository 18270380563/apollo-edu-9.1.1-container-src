/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include "gflags/gflags.h"

DECLARE_string(dv_plugin_msg_writer_topic);
DECLARE_string(dv_plugin_studio_connector_home_dir);
DECLARE_string(dv_plugin_studio_connector_studio_entrypoint);
DECLARE_string(dv_plugin_studio_connector_studio_cert_name_override);
DECLARE_string(dv_plugin_map_root_dir);
DECLARE_int64(dv_plugin_studio_connector_record_chunk_size);
DECLARE_string(dv_plugin_auca_agent_entrypoint);
DECLARE_string(dv_plugin_http_client_url_prefix);
DECLARE_int32(auca_grpc_service_connect_deadline_ms);
