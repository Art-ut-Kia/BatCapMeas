# BatCapMeas
Arduino-UNO based battery capacity-meter

<img src="https://raw.githubusercontent.com/Art-ut-Kia/BatCapMeas/master/Wiki%20illustrations/BCM_overallDevice.jpg"
width="500">

An arduino controls a transistor that switches a 100mA resistive load on the Li-ion battery.
The battery voltage (3.0V ... 4.2V) is measured and logged by the arduino.
The measurements are logged in the serial monitor of the arduino IDE.
When the battery voltage reaches 3.0V, the transistor is blocked by the arduino to disconnect the charge. This avoids to damage the battery because of a too deep discharge, and it saves a boaring human monitoring of the measurement process.

For details, have a look [here in the wiki](https://github.com/Art-ut-Kia/BatCapMeas/wiki).

You can also run online simulations (in your browser) thanks to [tinkercad](https://www.tinkercad.com/things/fODc21Yx3Dx)
