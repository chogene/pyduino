import serial
import time

arduinoData = serial.Serial('COM3', 115200)
time.sleep(1)

while True:
    cmd = input('Please Enter Your Command: ')
    cmd = cmd + '\r'  # string + carriage return

    arduinoData.write(cmd.encode())  # Encode the string using the codec registered for encoding.
    # print(arduinoData.readline())


