# 🔐 UART Password Protected LED Control System (LPC2148)

## 📌 Project Overview
This project implements a **UART-based password-protected embedded system** using the LPC2148 microcontroller.

After successful authentication, the user can control an LED through serial commands via a terminal interface.

---

## 🚀 Features
- UART Communication (Transmit & Receive)
- Password authentication with masked input (`*`)
- 3-attempt security lock system
- Command-based control system
- GPIO interfacing for LED control
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
- ISIS professional
- UART Protocol


## 🎥 Demo Video
👉 Watch here:  
https://drive.google.com/file/d/1lX05-ZX1k4kVRBKpg2hh1WkZr2BFr0zb/view?usp=drive_link

---



## 🔐 Working Principle
1. User enters password via UART terminal  
2. Input is masked using `*`  
3. If password is correct:
   - Access is granted to command system  
4. If password is wrong:
   - Only 3 attempts allowed  
   - System locks after 3 failed attempts  
5. User can control LED using commands  
6. `EXIT` command logs out user  


---

## 👨‍💻 Author
**Aswin**  
Aspiring Embedded Systems Engineer  

---

## 🔗 Connect with Me
LinkedIn: https://www.linkedin.com/in/aswinsanthosh2509/
