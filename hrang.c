/* subroutine hrang */

/* This function converts the right ascension (x) into hour angle
 given the geographical longitude, date and time.

 West longitudes are given as a negative number in degrees */

#include <math.h>
#include "sunpos.h"


double hrang(int dy, int mn, int yr, double tim, double x)
{
  
  double gst, lst, p;

  gst = gtime(dy, mn, yr, tim);
  lst = gst + (LONGITUDE/15);

  if (lst > 24) lst = lst - 24;
  if (lst < 0) lst = lst + 24;

  p = lst - x;
  if (p < 0) p = p + 24;

  return p;
}
