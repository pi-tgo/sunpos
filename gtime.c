/* SUBROUTINE gtime */

/*  This function converts a given Universal Time (UT) into
    Greenwich Mean Sidereal Time (GMST). */


#include <math.h>
#include "sunpos.h"


double gtime(int dy, int mn, int yr, double x)
{
  double tim, xdjd, djd, t, r, r1, b, t0, gtm;
  int xmn, xdy;

  tim = x;
  xmn = mn;
  xdy = dy;
  xdjd = julday(dy,mn,yr); 
  djd = julday(0,1,yr);
  t = djd / 36525.;

  r = 6.6460656 + (5.1262e-2 + (t * 2.581e-5)) * t;
  r1 = 2400. * (t - ((yr - 1900) / 100.));
  b = 24. - r - r1;
  t0 = ((xdjd - djd) * 6.57098e-2) - b;
  gtm = (tim * 1.002737908) + t0;

  if (gtm > 24) gtm = gtm - 24;
  if (gtm < 0)  gtm = gtm + 24;

  return gtm;
}
