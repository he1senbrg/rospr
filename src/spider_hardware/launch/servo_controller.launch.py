from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    # Get the package share directory
    pkg_share = get_package_share_directory('spider_hardware')
    
    # Path to the configuration file
    config_file = os.path.join(pkg_share, 'config', 'servo_config.yaml')
    
    # Declare launch arguments
    config_arg = DeclareLaunchArgument(
        'config_file',
        default_value=config_file,
        description='Path to the servo configuration file'
    )
    
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation time if true'
    )
    
    # Servo controller node
    servo_controller_node = Node(
        package='spider_hardware',
        executable='servo_controller_node',
        name='servo_controller_node',
        parameters=[
            LaunchConfiguration('config_file'),
            {'use_sim_time': LaunchConfiguration('use_sim_time')}
        ],
        output='screen',
        emulate_tty=True,
    )
    
    return LaunchDescription([
        config_arg,
        use_sim_time_arg,
        servo_controller_node,
    ])