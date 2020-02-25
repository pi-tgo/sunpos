/* global definition file for sunpos */

/* set location - assumed to be constant */

/* LATITUDE in degrees - positive in the northern hemisphere.
   LONGITUDE in degrees - positive east of Greenwich. */

#define    LATITUDE     69.661   /* Tromsø, Norway */
#define    LONGITUDE    18.939

/* --------NOTHING TO CHANGE BELOW THIS LINE--------*/

#ifndef PI
#define    PI           3.141592654
#endif

/* checkdate */
int checkdate(int, int, int);

/* minsec */
double minsec(int, int, double);

/* julday */
double julday(double, int, int);

/* gtime */
double gtime(int, int, int, double);

/* secmin */
struct time {
   char sign;
   int h;
   int m;
   double s;
} secmin(double);

/* hourmin */
struct shorttime {
   int h;
   int m;
   } hourmin(int, int);

/* eqhor */
struct hor {
   double azi;
   double alt;
} eqhor(double, double);

/* hrang */
double hrang(int, int, int, double, double);

/* obliq */
double obliq(double, int, int);

/* eqecl */
struct ecl {
   double p;
   double q;
} eqecl(double, int, int, double, double);

/* nutat */
struct nut {
   double dpsi;
   double deps;
} nutat(double, int, int);

/* anomaly */
struct anom {
   double ea;
   double nu;
} anomaly(double, double);

/* sun */
struct sol {
   double ra;
   double dec;
   } sun(double, int, int, double);
