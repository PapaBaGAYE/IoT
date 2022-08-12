import serial

ser = serial.Serial('/dev/ttyUSB0',9600, timeout=1 )

while True:
    with open ("pape.txt", "r") as f:
        g = f.readlines()[-1]
    ser.write(g.encode())
    while (ser.in_waiting <= 0):
      pass

    a = ser.readline().decode().rstrip()
    b = a.split(',')

    print(b)

    file = open("serie_Ard_vers_pi.txt","w")
    file.write(a)
    file.close()
