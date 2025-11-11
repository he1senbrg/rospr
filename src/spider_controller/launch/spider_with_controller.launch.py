from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # Get package share directories
    spider_bringup_share = get_package_share_directory('spider_bringup')
    spider_controller_share = get_package_share_directory('spider_controller')
    
    # Declare launch arguments
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='false',
        description='Use simulation time'
    )
    
    servo_rate_arg = DeclareLaunchArgument(
        'servo_rate',
        default_value='50.0',
        description='Servo control frequency (Hz)'
    )
    
    joy_device_arg = DeclareLaunchArgument(
        'joy_device',
        default_value='/dev/input/js0',
        description='Xbox controller device path'
    )
    
    # Launch configuration
    use_sim_time = LaunchConfiguration('use_sim_time')
    servo_rate = LaunchConfiguration('servo_rate')
    joy_device = LaunchConfiguration('joy_device')
    
    # Include spider robot launch
    spider_robot_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([spider_bringup_share, 'launch', 'spider_robot.launch.py'])
        ]),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'servo_rate': servo_rate,
        }.items()
    )
    
    # Joy node for Xbox controller
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
        servo_rate_arg,
        joy_device_arg,
        spider_robot_launch,
        joy_node,
        spider_controller_node,
    ])