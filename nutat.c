/* subroutine nutat, dy, mn, yr */

/* This function calculates the nutation in ecliptic longitude
   and in the obliquity of the ecliptic for a given date. */


#include <math.h>
#include "sunpos.h"

   
struct nut nutat(double dy, int mn, int yr)
{

  double djd, t, t2, a, b, ls, ld, ms, md, nm, tls, tnm, tld;
  struct nut res;
  
  
  djd = julday(dy, mn, yr);
  t = djd / 36525.0;
  t2 = t * t;

  a = 1.000021358e2 * t;
  b = 360 * (a - floor(a));
  ls = 2.796967e2 + 3.03e-4 * t2 + b;

  a = 1.336855231e3 * t;
  b = 360 * (a - floor(a));
  ld = 2.704342e2 - 1.133e-3 * t2 + b;

  a = 9.999736056e1 * t;
  b = 360 * (a - floor(a));
  ms = 3.584758e2 - 1.5e-4 * t2 + b;

  a = 1.325552359e3 * t;
  b = 360 * (a - floor(a));
  md = 2.961046e2 + 9.192e-3 * t2 + b;

  a = 5.372616667 * t;
  b = 360 * (a - floor(a));
  nm = 2.591833e2 + 2.078e-3 * t2 - b;

  tls = 2 * ls*PI/180;
  nm = nm*PI/180;
  tnm = 2 * nm*PI/180;
  ms = ms*PI/180;
  tld = 2 * ld*PI/180;
  md = md*PI/180;

  res.dpsi = (-17.2327 - 1.737e-2 * t) * sin(nm) + (-1.2729 - 1.3e-4 * t) * sin(tls)
  + 2.088-1 * sin(tnm) - 2.037-1 * sin(tld) + (1.261e-1 - 3.1e-4 * t) *
  sin(ms) + 6.75e-2 * sin(md) - (4.97e-2 - 1.2e-4 * t) * sin(tls + ms) - 3.42e-2
  * sin(tld - nm) - 2.61e-2 * sin(tld + md) + 2.14e-2 * sin(tls - ms) - 1.49e-2
  * sin(tls - tld + md) + 1.24e-2 * sin(tls - nm) + 1.14e-2 * sin(tld - md);

  res.deps = (9.21 + 9.1e-4 * t) * cos(nm) + (5.522e-1 - 2.9e-4 * t) * cos(tls) -
  9.04e-2 * cos(tnm) + 8.84e-2 * cos(tld) + 2.16e-2 * cos(tls+ms) + 1.83e-2 *
  cos(tld - nm) + 1.13e-2 * cos(tld + md) - 9.3e-3 * cos(tls - ms) - 6.6e-3 *
  cos(tls - nm);

  res.dpsi = res.dpsi / 3600.0;      /* in degrees */
  res.deps = res.deps / 3600.0;      /* in degrees */

  return res;
}
