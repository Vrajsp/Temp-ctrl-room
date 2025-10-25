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

## Visual Elements

- **Fan Animation**
![Fan GIF](https://media.giphy.com/media/l0HlOvJ7yaacpuSas/giphy.gif)

- **Degree Symbol (°C)**
![°C Icon](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e8/Degree_sign.svg/120px-Degree_sign.svg.png)

- **Thermometer Bar Highlight**
![Thermometer GIF](https://media.giphy.com/media/3o7TKx8L3m1k0Nq6e0/giphy.gif)

- **Alert Highlight**
![Alert GIF](https://media.giphy.com/media/l0HlA6vQZt9hklOiI/giphy.gif)

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

Developed by **Viraj Sharad Patil**
GitHub: [https://github.com/Vrajsp](https://github.com/Vrajsp)
LinkedIn: [https://www.linkedin.com/in/viraj-sp](https://www.linkedin.com/in/viraj-sp)





I can also **make a “super animated” README version** with **sliding banners, multiple GIFs in sequence, and mini charts** like a real dashboard if you want it to look next-level on GitHub.  

Do you want me to do that?
```
