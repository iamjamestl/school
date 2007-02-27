/* $Id: clock.c,v 1.8 2005/12/27 18:08:22 tom Exp $ */

#include <cdk_test.h>

#ifdef HAVE_XCURSES
char *XCursesProgramName="label_ex";
#endif

int main (int argc, char **argv)
{
   /* Declare variables. */
   CDKSCREEN *cdkscreen = 0;
   CDKLABEL *demo	= 0;
   WINDOW *cursesWin	= 0;
   int boxLabel		= 0;
   char *mesg[4], temp[256];
   struct tm *currentTime;
   time_t clck;
   int ret;

   /* Parse up the command line. */
   while ((ret = getopt (argc, argv, "b")) != -1)
   {
      switch (ret)
      {
	 case 'b' :
	      boxLabel = 1;
      }
   }

   /* Set up CDK */ 
   cursesWin = initscr();
   cdkscreen = initCDKScreen (cursesWin);

   /* Start CDK Colors */
   initCDKColor();

   /* Set the labels up. */
   mesg[0] = "</1/B>HH:MM:SS";

   /* Declare the labels. */
   demo = newCDKLabel (cdkscreen, CENTER, CENTER, mesg, 1, boxLabel, FALSE);

   /* Is the label null??? */
   if (demo == 0)
   {
      /* Clean up the memory. */
      destroyCDKScreen (cdkscreen);

      /* End curses... */
      endCDK();

      /* Spit out a message. */
      printf ("Oops. Can't seem to create the label. Is the window too small?\n");
      ExitProgram (EXIT_FAILURE);
   }

   curs_set(0);
   wtimeout (WindowOf(demo), 50);

   /* Do this for-a-while... */
   do
   {
      /* Get the current time. */
      time(&clck);
      currentTime = localtime (&clck);

      /* Put the current time in a string. */
      sprintf (temp, "<C></B/29>%02d:%02d:%02d", currentTime->tm_hour, currentTime->tm_min, currentTime->tm_sec);
      mesg[0] = copyChar (temp);

      /* Set the label contents. */
      setCDKLabel (demo, mesg, 1, ObjOf(demo)->box);

      /* Clean up the memory used. */
      freeChar (mesg[0]);

      /* Draw the label, and sleep. */
      drawCDKLabel (demo, ObjOf(demo)->box);
      napms (500);
   }
   while (wgetch(WindowOf(demo)) == ERR);

   /* Clean up */
   destroyCDKLabel (demo);
   destroyCDKScreen (cdkscreen);
   endCDK();

   ExitProgram (EXIT_SUCCESS);
}
