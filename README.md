# Protothreads Example
This repo is intended to show a basic example of how to context switch between two functions on an Arduino Nano. To run this update the `platformio.ini` file at the root of the project to the type of microcontroller you have
```
[env:megaatmega2560]
platform = atmelavr
board = nanoatmega328
framework = arduino
lib_deps = gitlab-airbornemint/Protothreads @ ^1.4.0-arduino.beta.1
```
Secondly make sure you have the latest libraries installed by running
```
pio lib install
```
Then upload the example code to your Arduino and monitor the output
```
pio run -t upload
pio device monitor
```
Happy coding <3
