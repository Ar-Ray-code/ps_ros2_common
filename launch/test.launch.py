from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    joy_node = Node(
        package="joy",
        executable="joy_node",
    )

    record_joy = Node(
        package="ps_ros2_common",
        executable="joy_test",
    )

    return LaunchDescription([
        joy_node,
        record_joy,
  ])
