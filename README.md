# ros2_pkg_template

template repository for ros2 package

## Required dependencies

> [!IMPORTANT]
> [At first, you need to install ROS2.](https://docs.ros.org/en/jazzy/Installation.html)

Just install by using `sudo apt install` the following packages:

- `clang-format`
- `ros-${ROS_DISTRO}$-ament-clang-format`
- `ros-${ROS_DISTRO}$-ament-cmake-clang-format`

e.g. (after running `source /opt/ros/<ros_distro>/setup.bash`):

```shell
sudo apt update && sudo apt install -y \
    clang-format \
    ros-${ROS_DISTRO}-ament-clang-format \
    ros-${ROS_DISTRO}-ament-cmake-clang-format
```

## Package creation

This package was created using the following command:

```shell
ros2 pkg create sample_package \
    --build-type ament_cmake \
    --dependencies rclcpp \
    --node-name sample_node \
    --library-name sample_lib
```

then, replace some cmake scripts with `ament_cmake_auto` tools:

```diff
# package.xml

+ <build_depend>ament_cmake_auto</build_depend>
```

```diff
# CMakeLists.txt

- find_package(ament_cmake REQUIRED)
- find_package(ament_cmake_ros REQUIRED)
- find_package(rclcpp REQUIRED)
- add_library(sample_lib src/sample_lib.cpp)
- add_library(sample_package::sample_lib ALIAS sample_lib)
- target_compile_features(sample_lib PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
- target_include_directories(..)
- ament_target_dependencies(..)
- target_compile_definitions(..)
- install(..)
- install(..)
- add_executable(sample_node src/sample_node.cpp)
- target_include_directories(..)
- target_link_libraries(sample_node sample_lib)
- install(..)
+ find_package(ament_cmake_auto REQUIRED)
+ ament_auto_find_build_dependencies()
+
+ ament_auto_add_library(sample_lib
+     src/sample_lib.cpp
+     include/sample_package/sample_lib.hpp
+     include/sample_package/visibility_control.h
+ )
```

```diff
# CMakeLists.txt

- ament_export_include_directories(..)
- ament_export_libraries(..)
- ament_export_targets(..)
- ament_package()
+ ament_auto_package()
```

and add `ament_cmake_clang_format` to test dependencies.

```diff
# package.xml

<test_depend>ament_lint_auto</test_depend>
<test_depend>ament_lint_common</test_depend>
+ <test_depend>ament_cmake_clang_format</test_depend>
```

```diff
# CMakeLists.txt

if(BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    ..
    set(ament_cmake_copyright_FOUND TRUE)
    set(ament_cmake_cpplint_FOUND TRUE)
+     set(ament_cmake_lint_cmake_FOUND TRUE)
    ament_lint_auto_find_test_dependencies()
endif()
```
