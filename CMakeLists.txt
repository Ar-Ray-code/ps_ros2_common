cmake_minimum_required(VERSION 3.5)
project(ps_ros2_common)

execute_process(COMMAND uname -r OUTPUT_VARIABLE UNAME_RESULT OUTPUT_STRIP_TRAILING_WHITESPACE)
string(REGEX MATCH "[0-9]+.[0-9]+" LINUX_KERNEL_VERSION ${UNAME_RESULT})
if (LINUX_KERNEL_VERSION LESS 5.13)
    message(WARNING "Linux kernel version should be greater than 5.13")
endif()

set(CMAKE_CXX_STANDARD 14)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp_components REQUIRED)

include_directories(
  include/ps_ros2_common
)

# add library ---------------------------------------------------------------
add_library(ps_ros2_common SHARED
  src/example_joy.cpp
)
rclcpp_components_register_nodes(ps_ros2_common
  "ps_ros2_common::example_joy")
target_compile_options(ps_ros2_common PUBLIC -Wall)

target_include_directories(ps_ros2_common PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(ps_ros2_common
  rclcpp
  rclcpp_components
  sensor_msgs
  std_msgs
)

install(TARGETS ps_ros2_common
  EXPORT export_${PROJECT_NAME}
  DESTINATION lib
)

# joy_test executable -------------------------------------------------------
add_executable(joy_test
  src/example_joy.cpp
)

ament_target_dependencies(joy_test
  rclcpp
  sensor_msgs
  std_msgs
  rclcpp_components
)

# testing --------------------------------------------------------------------
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  joy_test
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
