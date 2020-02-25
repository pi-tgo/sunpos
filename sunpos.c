/* Main program: sunpos  */

/* This program calculates the apparent altitude and azimuth of
   the sun. */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "sunpos.h"

char *month_name(int n)
{
   static char *name[] = {
       "Illegal month", "January", "February", "March",
       "April", "May", "June", "July", "August",
       "September", "October", "November", "December"
   };
   
   return (n < 1 || n > 12) ? name[0] : name[n];
}

int main(int argc, char *argv[])
{

/*  float day; */
  int day, month, year, i, delta, valid;
  struct sol position;
  struct hor hh;
  struct shorttime res;
  double hourangle, t;
  char lats, longs;

  if (argc != 5)
  {
     printf("Usage: sunpos DY MN YR TM\n");
     printf("       DY = day\n");
     printf("       MN = month\n");
     printf("       YR = year\n");
     printf("       TM = tabular interval in minutes\n");
  } 
  else
  {
     day = atoi(argv[1]);
     month = atoi(argv[2]);
     year = atoi(argv[3]);
     delta = atoi(argv[4]);
     
     valid = checkdate(day, month, year);
     
     if (valid == 0)
        printf("The given date is not valid\n");
     else
     {
        if (LATITUDE < 0)
	   lats = 'S';
	else
	   lats = 'N';
	if (LONGITUDE < 0)
	   longs = 'W';
	else
	   longs = 'E';
	   
        printf("Position of the Sun from location:\n");
	printf("latitude: %7.3f %c, longitude: %7.3f %c\n",fabs(LATITUDE),
	lats, fabs(LONGITUDE), longs);
	
	printf("Date: %s %d, %d\n", month_name(month), day, year);
        printf("Time (UT) \t Altitude \t Azimuth\n");
	printf("----------------------------------------\n");
  
        i = 0;   /* ( i * delta ) is the number of seconds passed */
        for (t = 0.0; t < 24.0; t=t+minsec(0,delta,0.0))
        {   
          position = sun(day, month, year, t);
          hourangle = hrang(day, month, year, t, position.ra);
          hh = eqhor(hourangle, position.dec);
          res=hourmin(i,delta);
          printf("%2d : %2d \t %6.1f \t %6.1f\n", res.h, res.m, hh.alt, hh.azi);
          i++;
        }
     }
  }
  return EXIT_SUCCESS;
}
