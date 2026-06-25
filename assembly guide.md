# Assembly Guide: cbARM PCB and Housing

This guide details the construction of the cbARM control module. 

## PCB and Electronics
To better understand, please refer to the images below:
<img width="1543" height="812" alt="image" src="https://github.com/user-attachments/assets/49428790-350b-4c70-921e-239055744103" />
<img width="1662" height="884" alt="image" src="https://github.com/user-attachments/assets/d8f369ee-8a52-415f-9717-89770dbdb99f" />
<img width="1664" height="897" alt="image" src="https://github.com/user-attachments/assets/dd2feeef-a59b-4ce6-a51c-1714a1428c73" />
<img width="1920" height="1020" alt="image" src="https://github.com/user-attachments/assets/d6d3621f-b2d4-49c4-a686-20f09bbe325f" />
<img width="1920" height="1020" alt="image" src="https://github.com/user-attachments/assets/db565db8-2bc4-4dfb-a2ae-ccf1fa266a1a" />
<img width="1920" height="1020" alt="image" src="https://github.com/user-attachments/assets/79388c71-88aa-46b3-9d66-fe869959a9c1" />


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
the assembly of theese parts are very simplistic and dont need as complicated instructions 

* The object "STLs/j0 -the plastic tray- base and center of gravity.stl" acts as the main object for the j0 portion. On all four sides on its base are holes for 2020 aluminium extrutions. Slot the leftover 2020 extrutions from cutting the other parts and make them long enough such that they can handle the shifting weight of the whole arm. (any measurment is good as long as it works as a core target of this prodject is the users controll on how long the arm can be by simply cutting longer extrutions) I recommend atleast 120 mm coming out from all sides though.

* The object "STLs/j0 -wrapper- vertical nema 17 mount.stl" fits right into it using 4 heat set m3 screws. Together they sadwich the nema 17 42hs60 stepper motor it should look like this <img width="1284" height="1712" alt="image" src="https://github.com/user-attachments/assets/ad1de9a6-b581-485f-9bd4-6881f798ce35" />

* On top of the motor mount lies the gearbox its layered kind of like a hamburger:
  1. STLs/j0 -bottom bun- .stl
  2. STLs/Jn 1ststage sungear.stl
  3. 3x STLs/Jn planetgear.stl
  4. STLs/Jn converter.stl
  5. STLs/j0 -patty-.stl
  6. STLs/Jn 2ndstage sungear.stl
  3. 3x STLs/Jn planetgear.stl
  4. STLs/Jn converter.stl
  5. STLs/j0 -top bun-.stl
 
It should look like this but ignore the bottom most part:
<img width="1284" height="1712" alt="image" src="https://github.com/user-attachments/assets/4f6407ad-7449-437e-982c-4d050f97e045" />
<img width="1284" height="1712" alt="image" src="https://github.com/user-attachments/assets/47dd1f6e-6d2d-4fd0-be0e-4376236a9afb" />
<img width="1284" height="1712" alt="image" src="https://github.com/user-attachments/assets/dc1c1d3c-ed22-44c5-878d-7188ae8bdea5" />
<img width="1292" height="968" alt="image" src="https://github.com/user-attachments/assets/237d2a5e-86f7-41d5-abc7-f491b2203b47" />

* To make the thrust bearing and j0 in general to work, snap fit STLs/Lazy_Susan_160_v3.0/PIN (print 16).stl and STLs/Lazy_Susan_160_v3.0/CARRIER.stl together and put them on top of STLs/j0 -the plastic tray- base and center of gravity.stl. Press fit STLs/j0 key.stl on top of the gearbox and STLs/j0 -the disposable plate- thrust bearing upper portion & j1 base.stl wich then snap fits into STLs/j0 -the plastic tray- base and center of gravity.stl

Refer to this image to better understand the thrust bearing.
<img width="1200" height="1464" alt="image" src="https://github.com/user-attachments/assets/31686f09-b7ce-48f7-9d17-511f95676804" />

In the end J0 should look like this alltogether.
<img width="757" height="477" alt="image" src="https://github.com/user-attachments/assets/95b1272b-7898-419e-a64f-192376da1e93" />

