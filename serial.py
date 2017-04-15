# requires python-serial
# apt-get install python-serial
import serial
import sys

ser = serial.Serial("/dev/ttyAMA0",9600)
# test.open()
# opening causes an error for an unknown reason

ser.write(chr(int(sys.argv[1])))
ser.write(chr(int(sys.argv[2])))
ser.write(chr(int(sys.argv[3])))
ser.write(chr(int(sys.argv[4])))

ser.close()
