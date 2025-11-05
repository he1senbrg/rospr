#!/usr/bin/env python3
"""
Demo launch file for Spider Robot
Runs the system and executes a sequence of demo behaviors
"""

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    # Include main spider robot launch
    spider_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            PathJoinSubstitution([
                FindPackageShare('spider_bringup'),
                'launch',
                'spider_robot.launch.py'
            ])
        ])
    )
    
    # Demo behavior node
    demo_node = Node(
        package='spider_bringup',
        executable='demo_behaviors_node',
        name='demo_behaviors',
        output='screen'
    )
    
    # Delay demo start to allow system initialization
    delayed_demo = TimerAction(
        period=5.0,
        actions=[demo_node]
    )
    
    return LaunchDescription([
        spider_launch,
        delayed_demo,
    ])