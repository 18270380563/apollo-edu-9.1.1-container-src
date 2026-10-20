#pragma once
#include <dirent.h>

#include "modules/sensor_calibration/lidar_to_camera/src/common/macro.h"

namespace apollo {
namespace sensor_calibration {

bool EnsureDirectoryExists(const std::string& path, std::string* err_message) {
    DIR* dir = opendir(path.c_str());
    if (dir) {
        // Directory exists.
        closedir(dir);
    } else if (ENOENT == errno) {
        // Directory does not exist, attempt to create it.
        if (mkdir(path.c_str(), 0755) == -1) {
            WRITE_ERR_MESSAGE("Error creating directory [" + path + "]");
        }
    } else {
        WRITE_ERR_MESSAGE("Error opening directory [" + path + "]");
    }
    return true;
}

}  // namespace sensor_calibration
}  // namespace apollo