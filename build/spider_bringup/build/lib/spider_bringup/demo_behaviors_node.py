#!/usr/bin/env python3
"""
Demo Behaviors Node for Spider Robot
Executes a sequence of demo behaviors similar to Arduino loop()
"""

import rclpy
from rclpy.node import Node
from spider_msgs.srv import ExecuteBehavior
import time


class DemoBehaviorsNode(Node):
    def __init__(self):
        super().__init__('demo_behaviors_node')
        
        # Service client for behavior execution
        self.behavior_client = self.create_client(ExecuteBehavior, '/execute_behavior')
        
        # Wait for service to be available
        while not self.behavior_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for behavior service...')
        
        self.get_logger().info("Demo Behaviors Node initialized")
        
        # Start demo sequence
        self.run_demo_sequence()
    
    def execute_behavior(self, behavior_name, repetitions=1, speed_multiplier=1.0):
        """Execute a behavior and wait for completion"""
        request = ExecuteBehavior.Request()
        request.behavior_name = behavior_name
        request.repetitions = repetitions
        request.speed_multiplier = speed_multiplier
        
        self.get_logger().info(f"Executing: {behavior_name}")
        
        future = self.behavior_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        
        if future.result().success:
            self.get_logger().info(f"Success: {future.result().message}")
            return True
        else:
            self.get_logger().error(f"Failed: {future.result().message}")
            return False
    
    def run_demo_sequence(self):
        """Run the demo sequence similar to Arduino loop()"""
        self.get_logger().info("Starting spider robot demo sequence...")
        
        behaviors = [
            ("stand", 1, 1.0, 2.0),
            ("step_forward", 5, 1.0, 2.0), 
            ("step_back", 5, 1.0, 2.0),
            ("turn_left", 5, 1.0, 2.0),
            ("turn_right", 5, 1.0, 2.0),
            ("hand_wave", 3, 1.0, 2.0),
            ("hand_shake", 3, 1.0, 2.0),
            ("body_dance", 10, 1.0, 2.0),
            ("sit", 1, 1.0, 5.0)
        ]
        
        for behavior_name, reps, speed, delay in behaviors:
            if self.execute_behavior(behavior_name, reps, speed):
                time.sleep(delay)
            else:
                break
        
        self.get_logger().info("Demo sequence completed!")


def main(args=None):
    rclpy.init(args=args)
    node = DemoBehaviorsNode()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()