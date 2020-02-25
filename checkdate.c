/* check if the date given is valid */

int checkdate(int dy, int mn, int yr)
{
   int valid = 1, leap = 0, days = 0;
   
   /* first check the obvious */
   
   if (yr == 0) valid = 0;       /* no year zero */
   if ((dy < 1) || (mn < 1) || (mn > 12)) valid = 0; /* days and months
                                 cannot be negative and months cannot be
				 more than twelve */
   
   leap = yr % 4 == 0 && yr % 100 != 0 || yr % 400 == 0;
   
   switch (mn) {
   case 1: case 3: case 5: case 7: case 8 : case 10: case 12:
      days = 31;
      break;
   case 2:
      days = 28 + leap;
      break;
   case 4: case 6: case 9: case 11:
      days = 30;
      break;
   }
   
   if (dy > days) valid = 0;
   
   return valid;
}
