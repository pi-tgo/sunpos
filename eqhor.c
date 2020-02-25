/* Subroutine EQHOR */

/* This function calculates the azimuth and altitude of a given
geographical latitude (phi) , hour angle (x) and declination (y). */

#include <math.h>
#include "sunpos.h"


struct hor eqhor(double x, double y)
{
  double phi,cphi,sphi,sy, cy, sx, cx, sq, q, cq, a, cp, p;
  struct hor res;

  phi = LATITUDE * PI / 180;
  x = x * PI / 180 * 15;
  y = y * PI / 180;

  cphi = cos(phi);
  sphi = sin(phi);
  sy = sin(y);
  cy = cos(y);
  sx = sin(x);
  cx = cos(x);

  sq = (sy * sphi) + (cy * cphi * cx);
  q = asin(sq);
  cq = cos(q);
  a = cphi * cq;

  /* a always positive, make sure it is never TOO close to zero */
  if (a < 1.0e-20) a = 1.0e20;

  cp = (sy - (sphi * sq)) / a;
  p = acos(cp);

  /* remove the ambiguity of taking inverse cosine */
  if (sx > 0) p = 2 * PI - p;

  res.azi = p * 180 / PI;
  res.alt = q * 180 / PI;

  return res;
}
