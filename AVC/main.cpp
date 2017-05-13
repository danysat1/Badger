#include <stdio.h>
#include <time.h>
#include "E101.h"

int main() {

	init();
	while (true){	
	take_picture();
	
	display_picture(1, 0);
	int sum=0;
	int i;
	int w;
	//int num_wp;
	
	for (i=0; i<320; i++) {
		w=get_pixel(120,i, 3);
		if (w>80) { //If white value >127/254 then white. 
			//num_wp++; //Increments the number of white pixels.
			sum = sum + (i-160);
		}
		
		double temp_sum = sum; //Needed temp variable to make negative so that calculations worked.
		if (temp_sum <0 ){ 
			temp_sum = temp_sum*-1;
		} 

		double scale = ((double)temp_sum*70.0/12000.0); //Ratio of sum and max value. Take this as a percentage of max motor value.
		int scale_int = (int)scale;
		printf("%d %d \n", sum, scale_int);
		
		

		if (sum > 0){ //Should turn to the right (more white values on the right side).
			set_motor(2,-1*(70+(scale_int))); 
			sleep1(0,5);
			set_motor(1,-1*(70-(scale_int))); 
			sleep1(0,5);
			}
		
	
		if (sum < 0){	//Should turn to the left (more white values onthe left side).
			set_motor(2,-1*(70-(scale_int))); 
			sleep1(0,5);	
			set_motor(1,-1*(70+(scale_int))); 
			sleep1(0,5);		
			}
		
		
		}

	}
