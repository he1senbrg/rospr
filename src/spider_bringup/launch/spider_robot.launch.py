#!/usr/bin/env python3
"""
Launch file for Spider Robot system
Starts all necessary nodes with proper configuration
"""

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch.conditions import IfCondition


def generate_launch_description():
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
    
    enable_controller_arg = DeclareLaunchArgument(
        'enable_controller',
        default_value='false',
        description='Enable Xbox controller support'
    )
    
    joy_device_arg = DeclareLaunchArgument(
        'joy_device',
        default_value='/dev/input/js0',
        description='Xbox controller device path'
    )
    
    # Launch configuration
    use_sim_time = LaunchConfiguration('use_sim_time')
    servo_rate = LaunchConfiguration('servo_rate')
    enable_controller = LaunchConfiguration('enable_controller')
    joy_device = LaunchConfiguration('joy_device')
    
    # Node definitions
    servo_controller_node = Node(
        package='spider_hardware',
        executable='servo_controller_node',
        name='servo_controller',
        parameters=[{
            'use_sim_time': use_sim_time,
            'servo_rate': servo_rate,
            'servo_pins': [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13],
            'min_angle': 0.0,
            'max_angle': 180.0
        }],
        output='screen'
    )
    
    kinematics_node = Node(
        package='spider_kinematics',
        executable='kinematics_node',
        name='kinematics',
        parameters=[{
            'use_sim_time': use_sim_time,
            'length_a': 55.0,
            'length_b': 77.5,
            'length_c': 27.5,
            'length_side': 71.0
        }],
        output='screen'
    )
    
    behavior_controller_node = Node(
        package='spider_behavior',
        executable='behavior_controller_node',
        name='behavior_controller',
        parameters=[{
            'use_sim_time': use_sim_time,
            'z_default': -50.0,
            'x_default': 62.0,
            'y_step': 40.0,
            'leg_move_speed': 8.0,
            'body_move_speed': 3.0,
            'spot_turn_speed': 4.0,
            'stand_seat_speed': 1.0
        }],
        output='screen'
    )
    
    # Optional Xbox controller nodes
    joy_node = Node(
        package='joy',
        executable='joy_node',
        name='joy_node',
        parameters=[{
            'device': joy_device,
            'deadzone': 0.05,
            'autorepeat_rate': 50.0,
            'coalesce_interval': 0.02,
            'use_sim_time': use_sim_time
        }],
        output='screen',
        condition=IfCondition(enable_controller),
        respawn=True,
        respawn_delay=1.0
    )
    
    spider_controller_node = Node(
        package='spider_controller',
        executable='controller_node',
        name='spider_controller', 
        parameters=[{
            'use_sim_time': use_sim_time
        }],
        output='screen',
        condition=IfCondition(enable_controller),
        respawn=True,
        respawn_delay=2.0
    )
    
    return LaunchDescription([
        use_sim_time_arg,
        servo_rate_arg,
        enable_controller_arg,
        joy_device_arg,
        servo_controller_node,
        kinematics_node,
        behavior_controller_node,
        joy_node,
        spider_controller_node,
    ])