# Smart Temperature-Controlled Room

**A mini smart room dashboard** with Arduino, OLED display, fan, and buzzer.  

Keep your room comfortable, monitor temperature & humidity in style, and get instant alerts when things get too hot!  

![Dashboard Demo](https://media.giphy.com/media/3oEjI6SIIHBdRxXI40/giphy.gif)

---

## Features
- Real-time **temperature & humidity monitoring**
- **Animated fan icon** reflecting temperature
- **Dynamic thermometer bar**
- **Buzzer alarm** for high temperature
- OLED dashboard with:
  - Top header: Room name + fan status + alerts
  - Center: Temp & Humidity blocks
  - Bottom: Comfort message & mini graphs
- Visual **alerts with inverted highlights**
- **History graph** of last 20 readings

---

## Components
- Arduino Uno  
- DHT11 Temperature & Humidity Sensor  
- 128x64 SSD1306 OLED  
- Small fan (relay controlled)  
- Relay module  
- Buzzer  
- Jumper wires & breadboard  

---

## 🔌 Wiring
| Component | Arduino Pin |
|-----------|------------|
| DHT11 DATA | D2 |
| OLED SDA | A4 |
| OLED SCL | A5 |
| Relay IN | D9 |
| Buzzer + | D8 |
| Fan | Relay NO & COM |

---

## Logs & Debug
Arduino outputs logs to Serial Monitor:  

```text
Temperature: 31.5°C
Humidity: 52%
Fan: ON
Buzzer: OFF
Alert: None
````

* Use these logs for troubleshooting or monitoring in real-time.

---

## Notes / Tips

* You can replace **DHT11** with **DHT22** for more accuracy.
* Modify `FAN_ON_TEMP` and `BUZZER_ON_TEMP` in the code for your comfort range.
* Dashboard layout can be extended for **multiple sensors or room zones**.

---

## credits

Developed by **Viraj Patil**
GitHub: [https://github.com/Vrajsp](https://github.com/Vrajsp)
LinkedIn: [https://www.linkedin.com/in/viraj-sp](https://www.linkedin.com/in/viraj-sp)
