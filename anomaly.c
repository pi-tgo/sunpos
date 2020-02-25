/* Subroutine ANOMALY */

/* This routine finds the values of the eccentric and true
   anomalies in elliptical motion, given the mean anomaly and the
   eccentricity.

   ma : mean anomaly
   nu : true anomaly
   ea : eccentric anomaly
   s  : eccentricity of the orbit

   The solution is to solve the Kepler equation:

   ea - s * sin(ea) = ma */

#include <math.h>
#include "sunpos.h"


struct anom anomaly(double ma, double s)
{
  double m, dla, tnu2;
  struct anom res;

  m = (ma - 2 * PI * floor(ma / (2 * PI)));
  res.ea = m;
  dla = res.ea - (s*sin(res.ea)) - m;

  while (fabs(dla) > 1.0e-6)
  {
   dla = dla / (1 - (s * cos(res.ea)));
   res.ea = res.ea - dla;
   dla = res.ea - (s*sin(res.ea)) - m;
  }

  tnu2 = sqrt((1 + s)/(1 - s)) * tan(res.ea / 2);
  res.nu = 2 * atan(tnu2);

  return res;
}
