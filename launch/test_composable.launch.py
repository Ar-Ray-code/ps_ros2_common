from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode


def generate_launch_description():
    """Generate launch file."""

    component = ComposableNodeContainer(
        name='joy_container',
        namespace='',
        package='rclcpp_components',
        executable='component_container',
        composable_node_descriptions=[
            ComposableNode(
                package='ps_ros2_common',
                plugin='ps_ros2_common::example_joy',
                name='joy_common_comp',
            ),
            ComposableNode(
                package='joy',
                plugin='joy::Joy',
                name='joy_node_comp',
            ),
        ],
        output='screen',
    )

    return LaunchDescription([
        component
    ])
