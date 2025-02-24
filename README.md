
# Air Quality Monitoring System for Campus Sustainability

## Problem Statement
Air quality has a direct impact on human health, cognitive function, and overall well-being. In confined environments like college campuses, poor air quality can cause:
- Respiratory issues due to high pollution levels.
- Reduced concentration and productivity among students and staff.
- Long-term exposure risks, including asthma, allergies and lung diseases.
Despite its importance, many campuses lack a proper monitoring system to
track air quality in real time. Students, faculty, and staff are often unaware of
the quality of air they breathe, exposing them to potential health hazards.

## Need of Air Quality System

Traditional air quality testing methods rely on manual sampling and lab testing, which are:
- Time-consuming – Results take days or weeks.
- Expensive – Requires professional analysis and specialized equipment.
- Not Real-Time – Does not capture sudden changes in pollution levels.
To address these limitations, we need an automated, real-time monitoring
system that can:
- Continuously track air quality parameters like temperature, humidity, and pollutants.
- Provide instant alerts when pollution levels exceed safe limits.
- Store and analyze data to identify long-term trends and pollution sources.

## Objectives
### Real-Time Air Quality Monitoring
Develop an IoT-based system using sensors (DHT11, MQ135) to continuously measure: 
- Temperature – Impact of heat on air quality.
- Humidity – Role in pollution retention.
- Air Quality Index (AQI) – Level of harmful gases (CO2, NO2, VOCs, etc.).
### Data Collection & Transmission
1) Collect air quality data and transmit it.
2) Enable remote access through a web or mobile application (Blynk App).
### Alert System for Immediate Action
1) Buzzer and notifications to warn about unhealthy air quality levels.
2) Color-coded AQI display (Green = Safe, Red = Dangerous).

## Technologies Used
### Hardware Components
1) IOT Sensors:-
- DHT11 Sensor
- MQ135 Gas Sensor
- I2C Converter

2) Microcontrollers:-
- ESP8266

3) Display:-
- LCD
4) Alert mechanism:-
- Buzzer

### Software Components
- Arduino IDE
- Blynk

## AQI Calculation and Alerting mechanism
1) Sensor Readings Interpretation: The model interprets sensor readings (e.g.,concentration of CO2, temperature, humidity) and assigns an AQI value based
on the predefined algorithm.

2) Threshold Setting: Establish thresholds for different AQI levels, indicatingwhen the air quality is considered good, moderate, unhealthy, etc.
### Remember that AQI values are typically categorized into different color codesrepresenting various health risk levels.
- 0-50: Good (Orange) - Air quality is satisfactory, and there's minimal risk to health.
- 51-100: Moderate (Blue) - Air quality is acceptable, but some pollutants may be a concern for people who are unusually sensitive to air pollution.
- 101-150: Unhealthy (Yellow) - Members of sensitive groups (e.g., children, elderly,individuals with respiratory or heart conditions) may experience health effects, and the general public is not likely to be affected.
- 151-200: Unhealthy (Red) - Everyone may begin to experience health effects, and members of sensitive groups may experience more significant health effects.

Triggering Alerts: If the calculated AQI crosses a predefined threshold(above 150) indicating poor air quality, the alert system is activated, triggering the local
buzzer and sending alerts to the Blynk app for remote notification.

## Conclusion
The "Air Quality Monitoring System for Campus Sustainability" project represents a significant step toward ensuring a healthier, more sustainable, and
safer campus environment. This initiative has been driven by the recognition of the critical role that air quality plays in the well-being and productivity of our college community.
Moreover, this project has positioned our college as a trailblazer in adopting innovative technology to address air quality concerns in an academic setting. By
showcasing our commitment to a safer and healthier campus environment, we inspire other educational institutions to follow suit.
Overall, this project is not just a technical endeavor but a testament to our dedication to the well-being of our campus community and our responsibility toward environmental sustainability. As we continue to refine and expand this system, we are poised to make a lasting impact on the quality of life within our
campus and serve as a beacon for other institutions seeking to enhance their own environmental initiatives.