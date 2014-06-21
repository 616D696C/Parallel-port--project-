
#include "mylibrary.h"

int main(void)
{
	initialize();
	while(1)
	{
			mydata = UARTRead();
		
// **********************************FOR DATA PORT*******************************
				// if write
				if(mydata == writedata_address)
				{
					if(((read_control) & 0b00100000) == 0)
					{
						temp = UARTRead();
						//DDRA = 0xFF;
						write_data = temp;
					}
					else {
						
						UARTSend(read_data);
					}
					
					/*if((mydata>>7) == 1)
					{
						
					} */
				}					
					
				//else read
				else if (mydata == data_address)
				{
					if(((read_control) & 0b00100000) == 0)
					{
						UARTSend(write_data);
					}
					else
					{
						UARTSend(read_data);
					}	
				}
			
		
// ********************************FOR STATUS PORT************************************
				else if(mydata == status_address)
				{
					// if read		
					UARTSend(read_status & (0b11111100));
				}				
			
		
// *********************************FOR CONTROL PORT**********************************
				//if write
				else if(mydata == writecontrol_address)
				{
					temp = UARTRead();
					write_control = temp;
					
					/*if((mydata>>7) == 1)
					{
						temp = UARTRead();
						control_temp = 0b00111111 & temp;
						write_control = 0b00001111 & control_temp;
					}
					*/
				}					
				//else read
				else if (mydata == control_address)
				{
					UARTSend(read_control & 0b00111111);
				}				
	}
}
