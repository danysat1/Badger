#include <stdio.h>
#include <time.h>
#include "E101.h"

int main() {
	/*init();
	take_picture(); 
	
	char wh[32]; 
	int index = 0;
	for (int col = 0; col < 320; col= col+ 10){ // from column 1 to column 320, do the following:
		wh[index] = get_pixel(100,col,3); // get pixel at row 100 and col if white can be seen
		index++;
	}
	for(int i = 0 ; i < index; i++) // for each wanted data, print them out on screen
	{
		printf("ind =%d wh=%d\n",i, wh[i]);
	}
	*/
	
	init();
<<<<<<< HEAD
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
=======
while (true){	
	take_picture();
		
	int sum=0;
	int i;
	int w;
	int num_wp;
	for (i=0; i<320; i++) {
		w=get_pixel(120, i, 3);
		if (w>127) { //this is to determine whether black or white pixel 
			num_wp++;
				sum = sum + (i-160);


	}
int temp_sum = sum;
if (temp_sum <0 ){ 
	temp_sum = temp_sum*-1;
	} 

double scale = ((double)temp_sum*255.0/14000.0);
int scale_int = (int)scale;
printf("%d %f %d \n", temp_sum, scale, scale_int );
	

	if (sum > 0){
		
		set_motor(2,scale); // right wheel
		sleep1(1,0);
		
		set_motor(1,-1*scale); // left wheel
		sleep1(1,0);
		
		}
	
	if (sum < 0){
		
		set_motor(2,-1*scale); // right wheel
		sleep1(1,0);
		
		set_motor(1,scale); // left wheel
		sleep1(1,0);
		
		}
	
	display_picture(1, 0);
	printf("%d\n", scale_int);
}
>>>>>>> ddf40be99920826b8328e47d48bd66120f6428ff
}
