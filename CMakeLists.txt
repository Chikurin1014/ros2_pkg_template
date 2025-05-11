cmake_minimum_required(VERSION 3.8)
project(xxxxxxxx)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_ros REQUIRED)
find_package(rclcpp REQUIRED)

add_library(sample_lib src/sample_lib.cpp)
add_library(xxxxxxxx::sample_lib ALIAS sample_lib)
target_compile_features(sample_lib PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_include_directories(sample_lib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
ament_target_dependencies(
    sample_lib
    "rclcpp"
)

# Causes the visibility macros to use dllexport rather than dllimport,
# which is appropriate when building the dll but not consuming it.
target_compile_definitions(sample_lib PRIVATE "XXXXXXXX_BUILDING_LIBRARY")

install(
    DIRECTORY include/
    DESTINATION include/${PROJECT_NAME}
)
install(
    TARGETS sample_lib
    EXPORT export_${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

add_executable(sample_node src/sample_node.cpp)
target_include_directories(sample_node PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)
target_link_libraries(sample_node sample_lib)

install(TARGETS sample_node
    DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    # the following line skips the linter which checks for copyrights
    # comment the line when a copyright and license is added to all source files
    set(ament_cmake_copyright_FOUND TRUE)
    # the following line skips cpplint (only works in a git repo)
    # comment the line when this package is in a git repo and when
    # a copyright and license is added to all source files
    set(ament_cmake_cpplint_FOUND TRUE)
    # the following line skips the linter which checks for cmake files
    set(ament_cmake_lint_cmake_FOUND TRUE)
    ament_lint_auto_find_test_dependencies()
endif()

ament_export_include_directories(
    "include/${PROJECT_NAME}"
)
ament_export_libraries(
    sample_lib
)
ament_export_targets(
    export_${PROJECT_NAME}
)

ament_package()
