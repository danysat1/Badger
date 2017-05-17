#include <stdio.h>
#include <time.h>
#include "E101.h"


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
	
	
		
		
	while (true){	
	take_picture();
	
	while (read_analog(0)>250){
		char addr[15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6'};
		connect_to_server(addr, 1024);
		char anything[24] = {'P','l','e','a','s','e'};
		send_to_server (anything);
		char fromServer [24];
		receive_from_server (fromServer); 
		send_to_server (fromServer);
	//	sleep1(0,1000);		
	}
	
//	display_picture(1, 0);
	int sum=0;
	int i;
	int w;
	int num_wp=0;
	
	for (i=0; i<320; i++) {
	
		w=get_pixel(120,i, 3);
		if (w>80) { //If white value >127/254 then white. 
			num_wp++; //Increments the number of white pixels.
			sum = sum + (i-160);
		}
		
		double temp_sum = sum; //Needed temp variable to make negative so that calculations worked.
		if (temp_sum <0 ){ 
			temp_sum = temp_sum*-1;
		} 

		double scale = ((double)temp_sum*30.0/12000.0); //Ratio of sum and max value. Take this as a percentage of max motor value.
		int scale_int = (int)scale;
//		printf("%d %d %d \n", sum, scale_int,num_wp);
				
		if (num_wp > 80){

		if (sum > 0){ //Should turn to the right (more white values on the right side).
			set_motor(2,-1*(43+(scale_int))); 
//			sleep1(0,30);
			set_motor(1,(-43+(2*scale_int/3.0))); 
//			sleep1(0,30);
			}
		
	
		if (sum < 0){	//Should turn to the left (more white values onthe left side).
			set_motor(2,(-43+(2*scale_int/3.0))); 
//			sleep1(0,30);	
			set_motor(1,-1*(43+(scale_int))); 
//			sleep1(0,30);		
			}
		
		}

		else {

		set_motor(2,32);
//		sleep1(0,30);
		set_motor(1,40);
//		sleep1(0,30);

}

		}

	}
}


	

	
		
		

