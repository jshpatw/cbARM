# cbARM (Cheese Burger ARM)

A 5-DOF (Degrees of Freedom) robot arm designed for high scalability, low cost, and ease of assembly using common makerspace materials.
<img width="1410" height="2000" alt="Chese burger" src="https://github.com/user-attachments/assets/8f725038-098d-42d9-b407-b5f93a132ee2" />

## Project Overview

The cbARM project aims to recreate industry-standard robot arm functionality using affordable, accessible components. By utilizing NEMA 17 motors, 3D-printed planetary gearboxes, and 2020 aluminum extrusions, this project provides a modular, affordable, and highly repairable alternative to commercial robotic systems.

## Target Features

* 5 Degrees of Freedom for full spatial maneuverability.
* Accessible build requiring no specialized machining.
* Modular design utilizing 2020 aluminum extrusions for variable arm lengths.
* Scalable architecture for easy repair and upgrades.

## Bill of Materials (BOM)

### Electronics

| Category | Reference/Item | Qty | Value/Spec | Notes |
| :--- | :--- | :--- | :--- | :--- |
| Electronics | A1-A7 | 7 | Pololu_A4988 | Motor Drivers |
| Electronics | C1-C7 | 7 | 100uF_35V | Electrolytic Capacitor |
| Electronics | J2,J4-J9 | 7 | Conn_01x04 | Header Pins |
| Electronics | J3 | 1 | Conn_01x03 | Header Pins |
| Electronics | J10 | 1 | Mini360_Module | Buck Converter |
| Electronics | J11 | 1 | 2_Pin_Term_Block | 5.00mm Pitch |
| Electronics | J12,J13 | 2 | Conn_01x19 | Pin Socket |
| Electronics | U1,U2 | 2 | 74HC595 | Shift Register |
| Electronics | Power Supply | 1 | 24V 15A | Main System PSU |

### Mechanical

| Category | Item | Qty | Value/Spec | Notes |
| :--- | :--- | :--- | :--- | :--- |
| Mechanical | Stepper Motors | 7 | NEMA 17 (42HS60) | 1.8 Degree Step |
| Mechanical | Bearings | 100 | MR105ZZ (10x5x4mm) | Steel Shielded |
| Mechanical | Screws | 100 | M3 x 10mm | Socket Head Cap |
| Mechanical | Heat-Set Inserts | 100 | M3 Brass Insert | For PETG |
| Mechanical | Filament | 3kg | PETG 1.75mm | Chassis Material |

## Assembly and CAD Files

All STL files required for 3D printing the chassis and planetary gearboxes are available in the `/stl` directory of this repository. Refer to the pictures in journal.md portion for more complex parts and to see how I went about making things

* Recommended Material: PETG 3 or more wall loops 20% minimum density 100% for gears and parts holding torque and gyroid pattern for structural rigidity and heat resistance (feel free to use PLA and other settings to test fitments).
* Hardware: Ensure all M3 heat-set inserts are installed prior to joining arm segments. 
* Bearings: Ensure 10x5x4mm bearings are seated with light pressure to avoid binding within 3D-printed pockets.
* Remember to practice safety when soldering parts and make sure to get extras and expect electronic defects.

<img width="1270" height="746" alt="image" src="https://github.com/user-attachments/assets/acbcc022-6e69-42e4-b61c-722ff9506ffd" />
<img width="1184" height="684" alt="image" src="https://github.com/user-attachments/assets/554ea592-aa8d-4cba-860e-baa402e69c23" />
Above is are pictures of the final PCB design for the prodject as of now.

<img width="841" height="731" alt="image" src="https://github.com/user-attachments/assets/36f05a64-b429-4f4d-b044-ae5e1f970e56" />
Above shows how the arm should look like after the 3d printed parts are assembled. (note that wires and electronics arent shown in this picture.


## Firmware and Control
 
* Status: Development in progress. 
* Firmware: To be updated.
* Control Interface: To be updated.
* Communication Protocols: To be updated.

## Future Roadmap

* Integration of Inverse Kinematics (IK) libraries.
* Development of end-effector/gripper attachments.
* Optimization of planetary gearbox backlash and tolerances.

## Feedback

Im currently doing everything solo so im open for advice and would appreciate feedback regarding anything in the prodject. 

## License

This project is licensed under the MIT License.
