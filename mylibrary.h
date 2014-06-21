#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000ul
#define write_data PORTA
#define read_data PINA
#define read_status PINB
#define write_control PORTC
#define read_control PINC

unsigned char mydata, temp, control_temp;

//for read the data @address
unsigned char data_address = 0b00000000;
unsigned char status_address = 0b00000001;
unsigned char control_address = 0b00000010;

//for write a data to address
unsigned char writedata_address = 0b10000000;
unsigned char writecontrol_address = 0b10000010;

void initialize()
{
	CLKPR = 0b10000000;
	CLKPR = 0b00000000;
	
	//UART_initialize
	UBRR0 = 103;
	UCSR0B = 0b10011000;
	UCSR0C = 0b00000110;
	
	DDRA= 0b11111111;   //data
	DDRB = 0b00000000;  //status
	DDRC = 0b11111111;  //control
	
}

unsigned char UARTRead()
{
	unsigned char data;
	while( !(UCSR0A & (1<<RXC0)) ); 	//check if receiving is complete. if there are no data data in the receive buffer,
                                    //the loop will continue running. This is sometimes called busy-waiting because
                                    //you are consuming processing power but you are just waiting till you get any input.
										                //This is also called a blocking statement because the flow of your code is blocked 
										                //or stopped until you get your input. This means that if you have some important statements
										                //after this line, they will be delayed. 
	
	data=UDR0;							          //this lines read the UART data register. Reading this register gives you the content of the  Receive register.
                                    //you are also required to read this register to clear RXC1.
										
	return data;	
	
}

void UARTSend(unsigned char data)
{
	while( !( UCSR0A & (1<<UDRE0)) ); 	// same as the first one. But this checks the UART data Register to check if it is empty before writing to it.

	UDR0 = data;                     		// You write the data to UDR if you want to transmit.
}
