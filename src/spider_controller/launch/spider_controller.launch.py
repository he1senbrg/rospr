from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Get package share directories
    spider_controller_share = get_package_share_directory('spider_controller')
    
    # Declare launch arguments
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation time if true'
    )
    
    joy_device_arg = DeclareLaunchArgument(
        'joy_device',
        default_value='/dev/input/js0',
        description='Joystick device path'
    )
    
    controller_config_arg = DeclareLaunchArgument(
        'controller_config',
        default_value=PathJoinSubstitution([spider_controller_share, 'config', 'controller_mapping.yaml']),
        description='Path to controller configuration file'
    )
    
    # Launch configuration
    use_sim_time = LaunchConfiguration('use_sim_time')
    joy_device = LaunchConfiguration('joy_device')
    controller_config = LaunchConfiguration('controller_config')
    
    # Joy node for reading joystick input
    joy_node = Node(
        package='joy',
        executable='joy_node',
        name='joy_node',
        parameters=[{
            'device': joy_device,
            'deadzone': 0.05,
            'autorepeat_rate': 50.0,  # Hz
            'coalesce_interval': 0.02,  # seconds
            'use_sim_time': use_sim_time
        }],
        output='screen',
        respawn=True,
        respawn_delay=1.0
    )
    
    # Spider controller node
    spider_controller_node = Node(
        package='spider_controller', 
        executable='controller_node',
        name='spider_controller',
        parameters=[{
            'use_sim_time': use_sim_time
        }],
        output='screen',
        respawn=True,
        respawn_delay=2.0
    )
    
    return LaunchDescription([
        use_sim_time_arg,
        joy_device_arg,
        controller_config_arg,
        joy_node,
        spider_controller_node,
    ])