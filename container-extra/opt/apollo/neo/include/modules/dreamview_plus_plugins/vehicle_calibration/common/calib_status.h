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
 ******************************************************************************/

#pragma once

#include <string>

/**
 * @namespace apollo::dreamview
 * @brief apollo::dreamview
 */
namespace apollo {
namespace dreamview {

/**
 * @class CalibStatus
 */
class CalibStatus {
public:
    CalibStatus() {}
    explicit CalibStatus(bool ok, const std::string& message = "") : ok_(ok), message_(message) {}
    /**
     * @brief If the status is OK.
     */
    bool IsOk() const {
        return ok_;
    }

    /**
     * @brief Get the status message.
     */
    std::string GetMessage() const {
        return message_;
    }

    /**
     * @brief Set error status message.
     */
    void SetErrorMessage(std::string message) {
        SetStatusMessage(false, message);
    }

    /**
     * @brief Set normal status message.
     */
    void SetNormalMessage(std::string message) {
        SetStatusMessage(true, message);
    }

    /**
     * @brief Set status and message.
     */
    void SetStatusMessage(bool ok, std::string message) {
        SetStatus(ok);
        SetMessage(message);
    }

    /**
     * @brief Only set status.
     */
    void SetStatus(bool ok) {
        ok_ = ok;
    }

    /**
     * @brief Only set message.
     */
    void SetMessage(std::string message) {
        message_ = message;
    }

private:
    bool ok_ = true;
    std::string message_;
};
}  // namespace dreamview
}  // namespace apollo
