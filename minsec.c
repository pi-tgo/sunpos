/* Subroutine MINSEC
   Transform HH MM SS to decimal hour */

#include <stdlib.h>
#include <math.h>

double minsec(int hour, int minute, double second)
{
  int sign, hour1, minute1;
  double dechour;

  sign = 1;

  if (hour < 0 || minute < 0 )
    sign = -1;
  hour1 = abs(hour);
  minute1 = abs(minute);
  dechour = ( ( ( ( second / 60.0 ) + minute1 ) / 60.0 ) + hour1 ) * sign;

  return dechour;
}
