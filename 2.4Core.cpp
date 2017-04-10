#include <stdio.h>
#include <time.h>
#include "E101.h"

//Mean of 5 readings from the sensor.

int main() {
  init();
  int readings[4];
  for (int i=0; i<5, i=i+1) {
    readings[i]=read_analog(0);
  {
  int mean=((readings[0]+readings[1]+readings[2]+readings[3]+readings[4])/5);
  printf("The mean is:", mean);
  
//Drive robot straight ahead.
 
  init();
  set_motor(0,120);
  sleep1(0,500000);
  set_motor(1, -120);
  sleep1(0,500000);
  
//Turn robot right (assuming motor 0 is on left side of robot).
  init();
  set_motor(0, 120);
  sleep1(0,500000);
  set_motor(1, 0);
  sleep1(0,500000);
  
 //Turn robot left (same assumption as before but other motor).
  init();
  set_motor(0, 0);
  sleep1(0,500000);
  set_motor(1, 120);
  sleep1(0,500000);
  
 //Make robot reverse slowly (same as forward but opposite values and smaller absolute values).
  init();
  set_motor(0,-60);
  sleep1(0,500000);
  set_motor(1,60);
  sleep1(0,500000);
  
 //Make robot reverse slowly if something is detected by IR sensor.
 //Mean should be more than a small number like 10 to make up for margin or error in sensor that sometimes returns
  positive values even though there is nothing in front of the sensor.
  
  init();
  int readings[4];
  for (int i=0; i<5, i=i+1) {
    readings[i]=read_analog(0);
  {
  int mean=((readings[0]+readings[1]+readings[2]+readings[3]+readings[4])/5);
  if (mean>10) {
  set_motor(0,-60);
  sleep1(0,500000);
  set_motor(1,60);
  sleep1(0,500000);
  }

return 0;
}
