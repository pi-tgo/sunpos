/* subroutine eqecl  */

/*  This function converts geocentric ecliptic longitude and latitude
 into the corresponding right ascension and declination.

 dy = day, mn = month, yr = year
 x = ecliptic longitude
 y = ecliptic latitude

 The function return a structure:
 { p= right ascension and   q=declination } */

#include <math.h>
#include "sunpos.h"

struct ecl eqecl(double dy, int mn, int yr, double x, double y)
{

  double eps, deps, eps1, seps, ceps, cy, sy, cx, sx, ty, sq, p, q, a;
  struct ecl res;
  struct nut nt;


  x = x*PI/180;
  y = y*PI/180;

  eps = obliq(dy, mn, yr) * PI / 180;
  nt = nutat(dy, mn, yr);
  deps = nt.deps * PI / 180;
  eps1 = eps + deps;

  seps =sin(eps1);
  ceps = cos(eps1);
  cy = cos(y);
  sy = sin(y);
  cx = cos(x);
  sx = sin(x);

  if (fabs(cy) < 1.0e-20) cy = 1.0e-20;

  ty = sy/cy;
  sq = (sy * ceps) + (cy * seps * sx);

  q = asin(sq);
  a = (sx * ceps) - (ty * seps);
  p = atan(a / cx);

  if (cx < 0) p = p + PI;
  if (p > (2*PI)) p = p - 2*PI;
  if (p < 0) p = p + 2*PI;

  res.p = p*180/PI / 15;
  res.q = q*180/PI;

  return res;
}
