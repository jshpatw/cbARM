/*
 * Robot Arm Firmware
 * Hardware: ESP32 + 2x 74HC595 Shift Registers + A4988 Drivers
 * * HARDWARE MAPPING (Based on P-CB.net):
 * ESP32 SPI: SCK=18, MOSI=23, LATCH=5
 * * Shift Register U1 (Bits 0-7):
 * - J1 (Base):    STEP=QA(0), DIR=QB(1)
 * - J2 (Shoulder): STEP=QG(6), DIR=QF(5)
 * * Shift Register U2 (Bits 8-15):
 * - J3 (Elbow):   STEP=QA(8), DIR=QB(9)
 * - J4 (Wrist):   STEP=QE(12), DIR=QF(13)
 * * Note: Drivers are in Full-Step mode (MS1/2/3 floating).
 */

#include <SPI.h>

// configs
const int LATCH_PIN = 5;
const int MOTOR_STEPS_PER_REV = 200; // Full-step mode

struct Motor {
    int stepBit;
    int dirBit;
    float gearRatio;
};

// initialize Joints
const Motor J1 = {0, 1, 64.0};
const Motor J2 = {6, 5, 32.0};
const Motor J3 = {8, 9, 16.0};
const Motor J4 = {12, 13, 16.0};

uint16_t registerState = 0;

// Convert degrees to pulses
long degreesToSteps(float degrees, float gearRatio) {
    return (long)((abs(degrees) / 360.0) * gearRatio * MOTOR_STEPS_PER_REV);
}

void updateRegisters() {
    digitalWrite(LATCH_PIN, LOW);
    SPI.transfer16(registerState);
    digitalWrite(LATCH_PIN, HIGH);
}

void moveJoint(Motor m, float degrees, bool clockwise) {
    long steps = degreesToSteps(degrees, m.gearRatio);
    
    // Set Direction
    if (clockwise) registerState |= (1 << m.dirBit);
    else registerState &= ~(1 << m.dirBit);
    updateRegisters();

    // Move with Trapezoidal Ramp
    int delayVal = 3000; 
    for (long i = 0; i < steps; i++) {
        // Simple Acceleration/Deceleration Ramp
        if (i < steps / 10 && delayVal > 1200) delayVal -= 10;
        if (i > steps * 9 / 10 && delayVal < 3000) delayVal += 10;

        registerState |= (1 << m.stepBit); 
        updateRegisters();
        delayMicroseconds(delayVal);
        
        registerState &= ~(1 << m.stepBit);
        updateRegisters();
        delayMicroseconds(delayVal);
    }
}

void setup() {
    pinMode(LATCH_PIN, OUTPUT);
    SPI.begin();
    
    // Test Sequence: 180 degrees per Joint
    moveJoint(J1, 180, true); delay(500);
    moveJoint(J2, 180, true); delay(500);
    moveJoint(J3, 180, true); delay(500);
    moveJoint(J4, 180, true); delay(500);
}

void loop() {}