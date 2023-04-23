import smbus
import time
bus = smbus.SMBus(1)
time.sleep(1) #wait here to avoid 121 IO Error 

addr = 0x8 # bus address

numb = 1

ctr = 65
 
print ("Enter 1 for ON or 0 for OFF")
while numb == 1:
 
	#ledstate = input(">>>>   ")
 
	#if ledstate == "1":
    bus.write_byte(addr, ctr) # switch it on

    ctr = ctr + 1

    time.sleep(1)

	#elif ledstate == "0":
	#	bus.write_byte(addr, 66) # switch it on
	#else:
	#	numb = 0
