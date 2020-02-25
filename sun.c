/* subroutine sun, dy, mn, yr, x */

/* This function calculates the apparent right ascension and declination
 of the sun at a given instant. */

#include <math.h>
#include "sunpos.h"


struct sol sun(double dy, int mn, int yr, double x)
{

  struct ecl appos;
  struct anom anomal;
  struct nut nutt;
  struct sol psun;
  
  double djd, t, t2, a, b, ls, ms, s, ma, a1, b1, c1, d1, e1, h1, dl, dr, lsn,
  rsn, lsnd;
  

  dy = dy + x/24.0;
  djd = julday(dy, mn, yr);
  t = djd / 36525.0;
  t2 = t * t;

  a = 1.000021359e2 * t;
  b = 360. * (a - floor(a));
  ls = 2.7969668e2 + 3.025e-4 * t2 + b;

  a = 9.999736042e1 * t;
  b = 360. * (a - floor(a));
  ms = 3.5847583e2 - (1.5e-4 + 3.3e-6 * t) * t2 + b;

  s = 1.675104e-2 - 4.18e-5 * t - 1.26e-7 * t2;

  ma = ms*PI/180;
  anomal = anomaly(ma, s);

  a = 6.255209472e1 * t;
  b = 360. * (a - floor(a));
  a1 = (153.23 + b)*PI/180;

  a = 1.251041894e2 * t;
  b = 360. * (a - floor(a));
  b1 = (216.57 + b)*PI/180;

  a = 9.156766028e1 * t;
  b = 360. * (a - floor(a));
  c1 = (312.69 + b)*PI/180;

  a = 1.236853095e3 * t;
  b = 360. * (a - floor(a));
  d1 = (350.74 - 1.44e-3 * t2 + b)*PI/180;

  e1 = (231.19 + 20.2 * t)*PI/180;

  a = 1.831353208e2 * t;
  b = 360. * (a - floor(a));
  h1 = (353.4 + b)*PI/180;

  dl = 1.34e-3 * cos(a1) + 1.54e-3 * cos(b1) + 2.0e-3 * cos(c1) +
  1.79e-3*sin(d1) + 1.78e-3 * sin(e1);

  dr = 5.43e-6 * sin(a1) + 1.57e-3 * cos(b1) + 1.627e-5 * sin(c1) + 3.076e-5 *
  cos(d1) + 9.27e-6 * sin(h1);

  lsn = anomal.nu + (ls - ms + dl)*PI/180;
  rsn = 1.0000002 * (1 - s * cos(anomal.ea)) + dr;

  while (lsn < 0) lsn = lsn + 2*PI;
  while (lsn > (2*PI)) lsn = lsn - 2*PI;

  lsn = lsn * 180/PI;
  
  nutt = nutat(dy, mn, yr);

  lsnd = lsn + nutt.dpsi - 5.69e-3;

  appos = eqecl(dy, mn, yr, lsnd, 0.0);

  psun.ra = appos.p;
  psun.dec = appos.q;

  return psun;
}
