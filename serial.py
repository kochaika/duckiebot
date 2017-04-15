# requires python-serial
# apt-get install python-serial
import serial
import sys

ser = serial.Serial("/dev/ttyAMA0",9600)
# test.open()
# opening causes an error for an unknown reason

#direction: 1 - forward; 0 - backward
ser.write(chr(int(sys.argv[1]))) #left drive direction
ser.write(chr(int(sys.argv[2]))) #left drive speed
ser.write(chr(int(sys.argv[3]))) #right drive direction
ser.write(chr(int(sys.argv[4]))) #right drive speed

ser.close()
