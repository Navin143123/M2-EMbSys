## ABSTRACT

### The consumption of electrical energy is highly increasing now -a- days due to our day -to- day requirements. This will create a huge demand on electrical supply. This project describes the design and construction of fan speed control according to the room temperature. The temperature sensor was carefully chosen to gauge the room temperature.Depending upon the detection of temperature the system will work which is controlled by the Atmega328.

## IDENTIFYING FEATURES
###	* Atmega328 controller shall be used for the control of the system.
###	* LCD Display shall be provided to display temperature and Fan speed.
### * This system provides complete automation of rooms in home.
### * Considerable amount of electricity shall be saved.
### * Blind people shall get benefited.

## STATE OF ART
### This project can automatically switch ON room fan when at least one person presents in the room. The temperature and fan speed are displayed on 16*2 LCD through the Atemega328. This will save the electricity.  

## 5W’s 1H
![Screenshot (87)](https://user-images.githubusercontent.com/98948360/157295316-31769ebf-cd34-4bd0-a2df-2aefbe940f48.png)

## SWOT ANALYSIS
![Screenshot (89)](https://user-images.githubusercontent.com/98948360/157295451-ed1eaac2-5771-4f54-b9d9-5088b5255534.png)

## REQUIREMENTS

### High Level Requirements
| ID | High Level Requirements |
| :---: | :---: |
| HLR1 | System shall control fan |
| HLR2 | There shall be an LCD to display some contents |
| HLR3 | Driver shall be used to turn on or off the fan |
| HLR4 | System Shall detect temperature |

### Low Level Requirements
| ID | Low Level Requirements for HLR1 | ID	| Low Level Requirements for HLR2 |
| :---: | :---: | :---: | :---: |
| LLR1.1 |	According to sensor value, fan shall be controlled | LLR2.1 |	Temperature, person count shall be displayed |
| LLR1.2  |	The sensor shall be control by Atmega328 |	LLR2.2 |	Fan and temperature status shall be displayed |
| ID |	Low Level Requirements for HLR3 |	ID | Low Level Requirements for HLR4 |
| LLR3.1 | Driver shall be controlled by the Atmega328 |	LLR4.1 | Temperature sensor detect the room temperature |
| LLR3.2 | Driver on at certain time to operate the fan |	LLR4.2 | Temperature and fan speed shall be displayed |

## COMPONENTS REQUIRED
### Microcontroller (Atmega328)
#### ATmega328 is an 8-bit, 28-Pin AVR Microcontroller, manufactured by Microchip, follows RISC Architecture, and has a flash-type program memory of 32KB. It has an EEPROM memory of 1KB and its SRAM memory is 2KB. It has 8 Pins for ADC operations, which all combine to form Port A (PA0 – PA7). It also has 3 built-in Timers, two of them are 8 Bit timers while the third one is 16-Bit Timer. It operates ranging from 3.3V to 5.5V but normally we use 5V as a standard. Its excellent features include cost-efficiency, low power dissipation, programming lock for security purposes, real timer counter with separate oscillator.
![image](https://user-images.githubusercontent.com/98948360/157347867-a8d58a94-5c8f-44d3-9eba-65d3028fb35e.png)
### Temperature Sensor (LM35)
#### LM35 is a precision IC temperature sensor with its output proportional to the temperature (in °C). The sensor circuitry is sealed and therefore it is not subjected to oxidation and other processes. With LM35, temperature can be measured more accurately than with a thermistor. It also possesses low self-heating and does not cause more than 0.1°C temperature rise in still air. The operating temperature range is from -55°C to 150°C. The output voltage varies by 10mV in response to every° C rise/fall in ambient temperature (Scale factor is 0.01V/°C).
   ![image](https://user-images.githubusercontent.com/98948360/157297935-90c843f9-a854-421b-b52b-ea5ce9abd10e.png)
### Dc Fan   
#### A DC ceiling fan works pretty much on the same principle as the DC motor. A DC motor uses an internal arrangement of magnets with opposing polarity. As current passes through the coil around this arrangement, a strong magnetic field is produced. This magnetic field then creates a torque that causes the motor to rotate. DC fans use less energy (70% of AC Fans),quiet and more speed options.                                                           
   ![image](https://user-images.githubusercontent.com/98948360/157347252-773f1d47-1993-4145-84c1-dcdbe7af6f44.png)
### L293 motor driver   
#### L293D is a typical Motor driver or Motor Driver IC which allows DC motor to drive on either direction. L293D is a 16-pin IC which can control a set of two DC motors simultaneously in any direction. It means that you can control two DC motor with a single L293D IC. Dual H-bridge Motor Driver integrated circuit (IC).
   ![image](https://user-images.githubusercontent.com/98948360/157348281-7a706ee9-50af-4ab9-bcb3-a121071d229e.png)
### Lcd Display
#### LCD (Liquid Crystal Display) screen is an electronic display module and find a wide range of applications. A 16*2 LCD display is very basic module and is very commonly used in various devices and circuits. The data is the ASCII value of the character to be displayed on the LCD.
   ![image](https://user-images.githubusercontent.com/98948360/157347502-d804bd21-e987-4956-a620-5ba864199fa7.png)
   
