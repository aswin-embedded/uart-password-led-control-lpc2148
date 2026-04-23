# 🔐 UART Password Protected LED Control System (LPC2148)

## 📌 Project Overview
This project implements a **UART-based password-protected system** using the LPC2148 microcontroller.  

After successful authentication, the user can control an LED using serial commands through a terminal interface.

---

## 🚀 Features
- UART Communication (Transmit & Receive)
- Password authentication with masked input (`*`)
- 3-attempt security lock mechanism
- Command-based system using serial terminal
- GPIO control for LED operation
- Logout functionality

---

## 🖥️ Available Commands
- `LED_ON`  → Turn ON LED  
- `LED_OFF` → Turn OFF LED  
- `EXIT`    → Logout and return to login  

---

## 🛠️ Tools & Technologies Used
- Embedded C
- LPC2148 Microcontroller
- Proteus Simulation
- UART Protocol

---


## 🎥 Demo Video
Watch the working demo here:  
👉 https://drive.google.com/file/d/1lX05-ZX1k4kVRBKpg2hh1WkZr2BFr0zb/view?usp=drive_link

---

## 📂 Project Files
- `main.c` → Source code  
- `project.dsn` → Proteus schematic file  
- `circuit.png` → Circuit screenshot

---

## 🔐 System Working
1. User enters password via UART terminal  
2. Input is masked using `*`  
3. If correct:
   - Access granted to command system  
4. If wrong:
   - 3 attempts allowed  
   - System locks after 3 failures  
5. Commands control LED using GPIO  

---

## 🙌 Author
**Aswin**  
Aspiring Embedded Systems Engineer  

---

## 🔗 Connect with Me
(https://www.linkedin.com/in/aswinsanthosh2509/)
