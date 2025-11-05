#!/usr/bin/env python3
"""
Launch file for Spider Robot system
Starts all necessary nodes with proper configuration
"""

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


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
    
    # Launch configuration
    use_sim_time = LaunchConfiguration('use_sim_time')
    servo_rate = LaunchConfiguration('servo_rate')
    
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
    
    return LaunchDescription([
        use_sim_time_arg,
        servo_rate_arg,
        servo_controller_node,
        kinematics_node,
        behavior_controller_node,
    ])