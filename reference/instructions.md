You are to **recreate the functionality of the attached Arduino sketch (`Spider.ino`)** #file:Spider.ino  as a **ROS2 (Kilted Kaiju) system**. Follow these rules carefully:

Follow ros2 best practics like proper structure like packages inside src dir in workspace etc

### Requirements

1. **Architecture Design**

   * Define a **clear ROS2 system architecture** that includes:

     * Nodes
     * Topics
     * Services (and actions if required)
     * Parameters
     * Message flow and interaction between components

2. **Implementation Rules**

   * **Do not manually create** packages, interfaces, services, or actions by writing out folder structures.
     Instead, use **`ros2` CLI commands** (like `ros2 pkg create`, `ros2 interface create`, `ros2 service create`, etc.) to generate them in your code.
   * Keep the generated code **simple, clean, and readable**.
   * Avoid unnecessary verbosity or over-engineering.

3. **Target Platform**

   * The code must be **fully compatible with Raspberry Pi 5** (running Ubuntu or Raspberry Pi OS).
   * Use only standard ROS2 (Kilted Kaiju) and Python/C++ libraries. Avoid external or non-standard dependencies.

4. **System Quality**

   * Ensure the system is **modular and scalable**, allowing future extensions (like additional sensors or actuators).
   * Use appropriate abstraction between hardware-level control (motors, servos, etc.) and higher-level behavior (movement, logic, feedback).

5. **Deliverables**

   * Step-by-step explanation of how the system maps to the original Arduino sketch.
   * Full ROS2 node code implementing the equivalent logic.
   * Launch file(s) to start all necessary nodes.
   * Instructions for building and running on Raspberry Pi 5.

6. **Documantation**

   * Place any documentation you generate (if any) in a docs/ folder.
   * keep the readme professional and minimal
