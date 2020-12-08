# ArduinoCode-I2CEeromTest
This code was developed to do test of 8K bit (1024 bytes) I2C EEPROM from 24xx08x series of IC's.
Default device address is 0x50 (0xA0 in 8-bit format).
There is only page 0 is avaliable at this address.
To access page 1,2 and 3 address needs to be 0x51, 0x52 and 0x53.
this code is automaticaly does all of the address adjustment.
