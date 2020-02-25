/* subroutine obliq*/

/* This function calculates the value of the obliquity of the ecliptic
 for a given calendar date. */

#include <math.h>
#include "sunpos.h"


double obliq(double dy, int mn, int yr)
{
  
  double djd,t,c,eps;
  
  djd = julday(dy, mn, yr);
  t = djd / 36525;
  c = (((-1.81e-3 * t) + 5.9e-3) * t + 4.6845e1) * t;

  eps = 23.45229444 - (c / 3600);

  return eps;
}
