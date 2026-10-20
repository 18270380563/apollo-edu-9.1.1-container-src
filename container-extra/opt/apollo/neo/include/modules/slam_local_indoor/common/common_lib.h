#ifndef _COMMON_LIB_H_
#define _COMMON_LIB_H_
#include <iostream>
#include <string>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

namespace commonlib {
class CommonLib {
public:
    CommonLib(const std::string& pkg_mode_);
    ~CommonLib();

    void PKG_VERSION(const std::string& pkg_mode_);

    template <typename T>
    float pointDistance(const T& p);

    template <typename T>
    float pointDistance(const T& p1, const T& p2);

    template <typename T>
    bool remapping(const T& value, const T& graph);
};
}  // namespace commonlib

#endif