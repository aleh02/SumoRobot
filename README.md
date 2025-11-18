# 🤖 Sumo Robot – Arduino Project

This project implements an **autonomous sumo robot** built with Arduino UNO.  

The robot uses:

- CNY70 line sensors (`CNYSX`, `CNYDX`) to detect the ring border  
- Sharp IR sensors (`SHSX`, `SHDX`) to detect the opponent  
- DC motors controlled via an H-bridge (`motore()`)  
- A LED start sequence handled by `attesa()`  
- Autonomous opponent search and movement logic inside `vista()`  

All variable names and function names match the original Arduino code (e.g., `avanti()`, `indietro()`, `rot_sinistra()`, etc.).

---

## 📦 Main Features

### 🔹 Start Sequence – `attesa()`
When the start button (`BOT`) is pressed, the robot runs a **LED countdown** using:

- `LED_1`
- `LED_2`
- `LED_3`
- `LED_4`

After the sequence finishes, the match begins.

### 🔹 Border Detection – CNY sensors
The robot checks the ring edge using:

- `cny_sx = analogRead(CNYSX)`
- `cny_dx = analogRead(CNYDX)`

With a configurable threshold (default: `50`):

- **Both sensors detect black (0)**  
  → `indietro()` + `rot_sinistra()`

- **Only `cny_sx` detects black**  
  → `rot_destra()`

- **Only `cny_dx` detects black**  
  → `rot_sinistra()`

This prevents the robot from falling outside the ring.

### 🔹 Opponent Detection – Sharp IR sensors
Function `vista()` reads:

```cpp
sh_sx = analogRead(SHSX);
sh_dx = analogRead(SHDX);
```
### Logic:

-If both sensors detect something → avanti()

-If only right sees something → destra()

-If only left sees something → sinistra()

-If nothing detected → default behavior is avanti()

-You can change this behavior inside vista().


## 🔌 Pin Mapping
| LED   | Pin |
| ----- | --- |
| LED_1 | 2   |
| LED_2 | 6   |
| LED_3 | 7   |
| LED_4 | 11  |

### Motors (H-Bridge)
| Motor | A         | B         | EN           |
| ----- | --------- | --------- | ------------ |
| MOT1  | MOT1A = 9 | MOT1B = 8 | MOT1EN = 10  |
| MOT2  | MOT2A = 4 | MOT2B = 5 | MOT2EN = 10* |

* Both motors share the same enable pin → same PWM speed.

### Sensors
| Sensor             | Pin |
| ------------------ | --- |
| CNYSX (left line)  | A0  |
| CNYDX (right line) | A1  |
| SHSX (left Sharp)  | A2  |
| SHDX (right Sharp) | A3  |

### Button
| Function | Pin |
| -------- | --- |
| BOT      | 12  |

---

## 🧠 Code Structure

-main.ino – Main loop and match logic

-attesa.cpp / attesa.h – LED start sequence

-motore.cpp / motore.h – Motor control functions (motore(), avanti(), indietro(), etc.)

-vista.cpp / vista.h – Opponent detection logic

-define_global.h – Pin definitions and timing constants (TEMPO_INDIETRO, TEMPO_ROTAZIONE, TEMPO_GIRO)

---

## 🚀 How to Use

1. Upload the sketch to Arduino UNO.

2. Place the robot inside the sumo ring.

3. Press the start button (BOT).

4. Watch the 4-step LED countdown.

5. The robot begins fighting automatically:

      -avoids the edge using cny_sx and cny_dx
   
      -searches using sh_sx and sh_dx
   
      -moves using avanti(), destra(), sinistra(), and rotations

---

## 🔧 Customization

You can easily tune the robot by modifying constants in define_global.h:
```cpp
#define TEMPO_INDIETRO 500
#define TEMPO_ROTAZIONE 500
#define TEMPO_GIRO 500
#define SOGLIA_CNY 50
```
Modify vista() to change search/aggression behavior.

---

## 🛠 Hardware Used

-Arduino UNO

-L298 / L293 H-bridge motor driver

-2x DC motors

-2x CNY70 reflective sensors

-2x Sharp IR distance sensors

-Start button (active LOW)

-4 LEDs

-LiPo battery

---

## 📜 License

This project is open-source and free to use for education, competitions and personal learning.

---

## ✨ Author

Developed and maintained by **Alessandro Han**.

