/******************************************************************************
 * Copyright 2023 The Apollo Authors. All Rights Reserved.
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

/**
 * @file
 */

#pragma once

#include <memory>
#include <regex>
#include <string>
#include <vector>

#include "CivetServer.h"

#include "cyber/common/log.h"
#include "cyber/cyber.h"
#include "modules/dreamview_plus_plugins/calibration_tool/common/calibration_gflags.h"
#include "modules/dreamview_plus_plugins/calibration_tool/conf_manager/conf_manager.h"

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */

namespace apollo {
namespace dreamview {

/**
 * @class
 * @brief The class of MapCreatorHandler. Build on top of CiveHandler.
 */
class CameraCalibHandler : public CivetHandler {
public:
    CameraCalibHandler(CalibConfManager *calib_conf_manager);

    /**
     * @brief Callback method for camera calib handler HTTP GET request.
     *
     * @param server The calling server.
     * @param conn The connection information.
     *
     * @return True if implemented, false otherwise.
     */
    bool handleGet(CivetServer *server, struct mg_connection *conn) override;

private:
    const CalibConfManager *calib_conf_manager_;
    std::string camera_calib_file_dir_;
};

}  // namespace dreamview
}  // namespace apollo
