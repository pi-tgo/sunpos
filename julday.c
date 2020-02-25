/* Subroutine JULDAY */

/* This routine calculates the number of days elapsed since the
   epoch 1900 January 0.5 (i.e. noon at Greenwich on 31 December 1999).
   To convert DJD to JD (Julian day), simply add 2415020. */

#include <math.h>

double julday(double dy, int mn, int yr)
{

  int mn1, yr1;
  double a, b, c, d, djd;
 
  mn1 = mn;
  yr1 = yr;
  b = 0.0;

  if (yr < 0)
    yr1 = yr1 + 1;
  if (mn < 3) {
    mn1 = mn1 + 12;
    yr1 = yr1 - 1;
  }
  if (yr > 1582 || (yr == 1582 && mn > 10) || (yr == 1582 && mn == 10 && dy > 15)) {
    a = floor(yr1/100.0);
    b = 2.0 - a + floor(a/4.0);
  }
  if (yr1 > 0)
    c = floor(365.25 * yr1) - 694025.0;
  else
    c = floor((365.25*yr)-0.75) - 694025.0;
  d = floor(30.6001*(mn1 + 1.0));
  djd = b + c + d + dy - 0.5;

  return djd;
}
