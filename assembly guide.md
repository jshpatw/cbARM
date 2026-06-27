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
<img width="1200" height="1464" alt="image" src="https://github.com/user-attachments/assets/18e638dc-0bbf-42af-9d54-72e3c307583b" />


In the end J0 should look like this alltogether. But ignore the gearbox on top of it...
<img width="757" height="477" alt="image" src="https://github.com/user-attachments/assets/95b1272b-7898-419e-a64f-192376da1e93" />

## J1 Parts
J1 lies on top of the "STLs/j0 -the disposable plate- thrust bearing upper portion & j1 base.stl" Its also stacked like a hamburger: 
1. STLs/j1 -wrapper- nema 17 horizontal mount.stl
2. STLs/J1 -bottom bun- stationary mount connection.stl
3. STLs/Jn 1ststage sungear.stl
4. 3x STLs/Jn planetgear.stl
5. STLs/Jn converter.stl
6. STLs/J1 -tomatoes- stationary ring.stl
7. STLs/Jn  2ndstage sungear.stl
4. STLs/Jn planetgear.stl
5. STLs/Jn converter.stl
6. STLs/j1 -onions- pause print at ~12 mm .stl
7. STLs/j1 -pepper(1)- sun gear.stl (1cm, thicker gear)
8. 3x STLs/j1 -salt(3)- planet gears.stl (1cm, thicker gear)
9. STLs/J1 -onion rings- spinning gear.stl
10. 3x STLs/j1 -bun flags (3)- lockes gears in place.stl

You will have to pause "STLs/j1 -onions- pause print at ~12 mm .stl" at ~12mm and slot in the 1cm thick gears with thier bearings and then continue the print. You will then slot in the "STLs/J1 -onion rings- spinning gear.stl" such that the 1cm gears are inside it. After this, you will screw in the 3x "STLs/j1 -bun flags (3)- lockes gears in place.stl" into "STLs/j1 -onions- pause print at ~12 mm .stl" in order to keep the moving onion ring in place.


### J2 supports
Use the 6806 bearings, slot it into the 30 mm groves on  "STLs/j0 -the disposable plate- thrust bearing upper portion & j1 base.stl" and slot "STLs/J1-2 supports.stl" right into it and connect it to "STLs/J1 -onion rings- spinning gear.stl" via screws or just glue/pressfitting. Use atleast one side of this and use the second if arm will be used for more heavy torque.

<img width="922" height="418" alt="image" src="https://github.com/user-attachments/assets/3751cc31-ffa6-44c2-a7dc-0e8cb0cb203c" />

## J2 parts

J2 is prettymuch slotted on top "STLs/J1 -onion rings- spinning gear.stl". On its platform it is also stacked like hamburger:

1. STLs/J2 nema 17 mount.stl
2. STLs/J2 gearbox 1.stl
3. STLs/Jn 1ststage sungear.stl
4. 3x STLs/Jn planetgear.stl
5. STLs/Jn converter.stl
6. STLs/J2 gearbox 2.stl
7. STLs/Jn  2ndstage sungear.stl
8. 3x STLs/Jn planetgear.stl
9. STLs/J2 Converter.stl
10. STLs/J2 gearbox 3.stl

Some pics of j2:
<img width="637" height="509" alt="image" src="https://github.com/user-attachments/assets/1ede8ec3-2e0b-4707-b1d6-10ff9b35818e" /><img width="700" height="515" alt="image" src="https://github.com/user-attachments/assets/d427b66a-0cf1-44f1-89dc-a87ca3301bef" />



## J3 parts
J3 is connected to the main body via 2020 extrution to "STLs/J3 2020 6806 mount.stl". "STLs/J2-3 Elbow pulley & nema 17 mount.stl" Connects to this via  press fit and the 6806 bearings. After that its hamburger stacking again:

1. STLs/J2-3 Elbow pulley & nema 17 mount.stl
2. STLs/J3 Gearbox 1.stl
3. STLs/Jn 1ststage sungear.stl
4. 3x STLs/Jn planetgear.stl 
5. STLs/J3 Gearbox 2.stl
6.  STLs/Jn  2ndstage sungear.stl
7. 3x STLs/Jn planetgear.stl
8. STLs/J3 2020 converter .stl
9. STLs/J3 Gearbox 1.stl

This is what j3 looks like all together (highlight on 1. STLs/J2-3 Elbow pulley & nema 17 mount.stl)
<img width="1325" height="804" alt="image" src="https://github.com/user-attachments/assets/9a2949ba-a4d9-4f51-9088-650aea3c8427" />

## P.S. Keep a ruler or measuring device hand;
If a hole has a diamter of 6mm then a smaller circle, this means the hole is for m3 bolts
if the diameter is a bit smaller at about 4.5mm this is for the heat set inserts
diameter of 30mm / 42mm means "put the 6806 bearing here" 
diameter of 10mm / 5mm means "put the MR105ZZ bearing here". 


