import serial

ser = serial.Serial('/dev/ttyUSB0',9600, timeout=1 )

while True:
    with open ("file.txt", "r") as f:
        g = f.readlines()[-1]
    ser.write(g.encode())
    while (ser.in_waiting <= 0):
      pass

    a = ser.readline().decode().rstrip()
    b = a.split(',')

    print(b)

    file = open("Ard_to_rasp.txt","w")
    file.write(a)
    file.close()
