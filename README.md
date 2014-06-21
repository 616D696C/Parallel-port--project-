Parallel-port--project-
=======================

-----------------------------
 Instruction for the project
-----------------------------

1.  Create a program in atmel studio that will make your devices accept 
    and interpret 2 bytes of data and respond based on the sent data. 
    The first byte is the command+address and the second byte is the data if there's any.
  

  COMMAND	  ACTION(bit7)	  ADDRESS(bit 6-0)	  PARAMETER(1 byte)
   Read	         0	            XXXXXXX	             None
   Write	       1	            XXXXXXX	          DDDDDDDD
                                                                  Where:
                                                                      XXXXXXX: 7 bits of address
                                                                      DDDDDDDD: 8 bits of data
    
2.	The program should interpret the first byte first (the Action and the address) by checking the 7thbit. 
    If the action is to READ then, your program does not expect a data parameter 
    but instead, reply with an 8-bit value read from the Address. 
    Otherwise expect a second byte for the parameter.
    
3.	The address is just a variable in your program. 
    If the ADDRESS is 0b0000000, this points to the variable for the Data register. 
    So, if the action and address is 0b0000000, this means that your program should respond with 
    the current value in the Data register which is a variable in your program linked to a digital I/O port. 
    You can even use the PORT and PIN register directly. That is, when you read the data register, 
    you reply the value of PORT register if bidirectional is 0 and value of the PIN register if Bidirectional is 1. 
    Do the same with the status register (address = 0b0000001) and 
    some of the control register(address = 0b0000010) bits (read the parallel.pdf from beyondlogic). 
    
4.	You can test your hardware with the hyperterminal/realterm by sending a byte when reading and 2 bytes when writing. 
    Realterm is recommended. You can also do this without the actual hardware. 
    It is possible to setup the hardware in Proteus and connect the terminal instrument of 
    proteus to your hardware simulation. 
    
5.	I will allow you to use arduino code but your highest score will only be 75%. 

6.	You can test your code by attaching LEDs in the ports that you will use.



