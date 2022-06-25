# Arduino_fire_extinguisher
Arduino project to measure temperature and activate the fan on excessive temperature to extinguish the fire.
Cristal display is used to display temperature but is not mandatory.

1. Temperature sensor needs to be close to the fire.
2. Fan needs to be aimed at the fire

To change the temperature trigger edit int trigger value.
![image](https://user-images.githubusercontent.com/104598825/175774903-21275eb1-740a-49ca-80f6-5be8f79996df.png)

Build could use transistor to get higher 12V power to the motor as the Arduino 5V pin is not powerfull enough to start the motor on its own.
