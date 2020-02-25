/* Subroutine SECMIN
   Transform decimal hour to SIGN HH MM SS */


#include <math.h>
#include "sunpos.h"


struct time secmin(double x)
{
  double xp, a;
  struct time tt;

  tt.sign = '+';

  if (x < 0 )
    tt.sign = '-';
  xp = fabs(x);
  tt.h = floor(xp);
  a = (xp - tt.h) * 60;
  tt.m = floor(a);
  tt.s = floor((a - tt.m) * 600 + 0.5) / 10;
  
  return tt; 
}
