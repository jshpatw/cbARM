# Assembly Guide: cbARM PCB and Housing

This guide details the construction of the cbARM control module. 

## PCB and Electronics

### Component Orientation and Sockets

* **ESP32 and Driver Sockets:** Solder female headers for the ESP32 and all seven A4988 motor drivers. Using sockets prevents direct thermal damage to chips during installation and enables future replacement.
* **Driver Orientation:** Align the VMOT pin on the A4988 driver precisely with the VMOT label on the PCB. Reversed installation will cause immediate hardware failure.
* **Capacitor Polarity:** Electrolytic capacitors (C1–C7) are polarized. The positive lead must connect to the VMOT pad, and the negative lead (indicated by a stripe on the component body) must connect to the GND pad. 

### Connector Configurations

* **NEMA 17 Stepper Connections:** Use the 4-pin headers (J2–J9) for motor phase connections. Verify motor wire mapping against driver outputs before applying power.
* **Servo Connections:** The 3-pin headers are designated for servo control. Pinout is: Signal, VCC, and GND. Confirm wiring to prevent damage to the servo electronics.
* **Voltage Regulation:** Connect the Mini 360 Buck Converter (J10) so the 24V supply enters the IN pins and the 3.3V output exits the OUT pins to the logic rail. 

### PCB Mounting and Enclosure

1. **Mounting:** Align the four PCB mounting holes with the standoffs within the Case Body.
2. **Fastening:** Secure the board using M3 x 10mm screws. Tighten carefully to avoid damaging the 3D-printed standoffs.
3. **Cable Management:** Route all motor and servo cables through the case ports before closing. Ensure wiring does not put physical stress on the solder joints. 
4. **Enclosure:** Attach the Case Cap using the press-fit mechanism. Use adhesive if additional stability is required.

### Pre-Power Inspection

1. **Continuity Check:** Use a multimeter to confirm no short circuits exist between the 24V rail and the 3.3V logic rail.
2. **Voltage Verification:** Apply 24V to the input terminal (J11) and measure the output of the Mini 360. Verify it reads exactly 3.3V before inserting the ESP32 or motor drivers into their sockets.
3. **Polarity Confirmation:** Verify the positive and negative connections at the 24V terminal block (J11) to prevent reverse polarity.

## J0 Parts
