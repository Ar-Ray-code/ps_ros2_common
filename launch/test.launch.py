from launch import LaunchDescription
from launch.actions import Shutdown

from launch_ros.actions import Node


def generate_launch_description():
    """Generate launch file."""

    joy_node = Node(
        package='joy',
        executable='joy_node',
        on_exit=Shutdown(),
    )

    record_joy = Node(
        package='ps_ros2_common',
        executable='joy_test',
        output='screen',
        on_exit=Shutdown(),
    )

    return LaunchDescription([
        joy_node,
        record_joy,
    ])
