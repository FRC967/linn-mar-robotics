Zach's Auto Changelog:
Checked out revision 184 on Nov 21
* changed all park() and wait1Msec lines to fullStop(), that kills the momentum
* changed jerk() to toBasket()
* toBasket() now slightly curves towards the bridge
* toBasket() now waits 400 milliseconds for movement instead of 500
* toBasket() now uses fullStop() instead of park()
- commented out all code except waitForStart() and toBasket() for testing

minor changes:
9:03 PM
+ Demo comment to test shell
10:13 PM
- deleted demo comment

Checked out revision 194 on Nov 23
+ started working on a trapezoid motor function
+ added a function to set all the drive motors to the same power
* toBasket now drives strait
- removed forward100()