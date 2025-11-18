# 🤖 Sumo Robot – Arduino Project

This project implements an **autonomous sumo robot** based on Arduino UNO.  
It uses:
- *CNY70* infrared sensors for ring edge detection  
- *Sharp IR* distance sensors to detect the opponent  
- Motor control through an H-Bridge driver  
- LED-based start countdown  
- Autonomous search and attack behavior  

The robot identifies the opponent, chases it, and attempts to push it out of the ring while preventing itself from falling.

---

## 📦 Main Features

### 🔹 Match Start (via `attesa()`)
Pressing the start button launches a **LED countdown animation** before the robot enters battle mode.

### 🔹 Edge Detection (CNY sensors)
The robot avoids falling off the ring using two line sensors:

- Both sensors detect black → move backward + rotate  
- Only left sensor detects black → rotate right  
- Only right sensor detects black → rotate left  

This ensures safe repositioning inside the ring.

### 🔹 Opponent Detection (Sharp IR sensors)
The function `vista()` reads SHSX and SHDX:

- Opponent detected in front → move forward  
- Opponent on the right → turn right  
- Opponent on the left → turn left  
- No detection → search behavior (default: forward)

### 🔹 Motor Control
Each motor is controlled through:

```cpp
motore(pinA, pinB, pinEN, dir, vel);
