/* Subroutine HOURMIN
   Calculates from decimal hour to HH MM
   Calling sequence:  hourmin(time)
   The function return a structure { h = integer hour
   and m = integer minutes }. */

#include <math.h>
#include "sunpos.h"

struct shorttime hourmin(int i, int delta)
{
  int time_passed;
  struct shorttime tt;

  time_passed = i * delta;

  tt.m = time_passed % 60;
  tt.h = (time_passed - tt.m) / 60;
  
  return tt; 
}
