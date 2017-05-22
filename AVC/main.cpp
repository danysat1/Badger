#include <stdio.h>
#include <time.h>
#include "E101.h"

/*AVC 2017 - Team Se7en
 * Dylan Ewens, Daniel Satur, Chansocheat Chheang, Angitha Ramesh and Elijah-Blue Simonson*/

int main() {
	init();
		
	while (true){	
	take_picture();
	
	/* Quadrant 1: 
	 * Opening a gate controlled by an Arduino based server*/
	
	while (read_analog(0)>250){ 											   //If the robot is CLOSE to the gate
		char addr[15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6'}; //Servers IP Address
		connect_to_server(addr, 1024); 										   //CONNECT to the server (IP Address, Port)
		char anything[24] = {'P','l','e','a','s','e'};
		send_to_server (anything);											   //SEND message "Please" to the server
		char fromServer [24]; 												   
		receive_from_server (fromServer);                                      //RECEIVE a message from the server
		send_to_server (fromServer); 										   //RETURN the message to the server, opening the gate	
	}
	
	/* Quadrant 2: 
	 * Following a white line using the robots camera*/
	
	int sum=0; 																   //INITIALISE the sum variable to be used for determining what direction to turn
	int i;																	   //DECLARE the dummy variable to increment over (number of horizontal pixels
	int w;																	   //DECLARE the white value variable to determine if a pixel is white or black
	int num_wp=0;															   //INITIALISE the number of white pixels variable to see if we are at the end of a line
	for (i=0; i<320; i++){
		w=get_pixel(120,i, 3);
		if (w>80) { 													       //If the white value of the pixel is more than 80 out of 254, its a WHITE PIXEL
			num_wp++; 														   //If it meets the requirements for being a white pixel, INCREMENT THE VARIABLE
			sum = sum + (i-160);
		}
		
		double temp_sum = sum; 												   //Temporary variable to force the sum to be positive (for use in SCALE CALCULATIONS)
		
		if (temp_sum <0 ){ 
			temp_sum = temp_sum*-1;
		} 

		double scale = ((double)temp_sum*30.0/12000.0); 					   //A Ratio of the sum to its expected max value, to be used for SCALING MOTOR SPEEDS
		int scale_int = (int)scale;											   
		
		//printf("%d %d %d \n", sum, scale_int,num_wp);  //Uncomment this for debugging. 
				
		if (num_wp > 80){ 													   //If MORE THAN HALF of the image is made up of white pixels...
		if (sum > 0){ 														   //Positive sum implies that there are more white pixles on the RIGHT side of the image
			set_motor(2,-1*(43+(scale_int))); 								   //Set the LEFT MOTOR to MODERATELY FORWARD
			set_motor(1,(-43+(2*scale_int/3.0))); 							   //Set the RIGHT MOTOR to SLIGHTLY FORWARD
			}
			
		if (sum < 0){														   //Negative sum implies that there are more white pixels on the LEFT side of the image
			set_motor(2,(-43+(2*scale_int/3.0))); 							   //Set the LEFT MOTOR to SLIGHTLY FORWARD
			set_motor(1,-1*(43+(scale_int))); 								   //Set the RIGHT MOTOR to MODERATELY FORWARD
			}
			
		if (num_wp > 200 && sum>4000){					 				       //200 out of 320 pixels are considered white and there are more white pixels on the RIGHT				   
			set_motor(1,0);													   //Set the RIGHT MOTOR to OFF
			set_motor(2,-55);												   //Set the LEFT MOTOR to 55 Forwards
			}
		}
		
		/* Quadrant 3: 
		 * Dealing with intersections and forks*/
		
		else { 																   //Implies that the robot is at the END OF A LINE, REVERSING and turning to the LEFT
		set_motor(2,50); 													   //Set the LEFT MOTOR to 50 BACKWARDS
		set_motor(1,32); 													   //Set the RIGHT MOTOR to 32 BACKWARDS
		}
		}
		
		/*Quadrant 4:
		 * Navigate a maze using IR sensors*/
		
		int r, g, b;
		for (int j=0; j<320; j++){
			r = get_pixel(120, j, 0);
			g = get_pixel(120, j, 1);
			b = get_pixel(120, j, 2);
			if (r>100 && g<50 && b < 50){
				while (true){
					set_motor(1, -47);
					set_motor(2, -50);
				}
			}
		}
	}
}
	

	
		
		

