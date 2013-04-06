servoangle
==========

A library to be used in conjunction with ServoBlaster for the Raspberry Pi for using degrees rather than pulse widths. Currently, SerboBlaster daemon (servod) must be running beforehand for servoangle to work.

ServoBlaster can be found here: git://github.com/richardghirst/PiBits.git

To install, clone the repository and run 'make' in the repository directory to compile automagically. Moving the servoanglelib.o library file to /usr/local/lib and servoanglelib.h header file to /usr/local/lib should make the library globally available.

servoanglelib
===============

The servo angle library file contains 3 functions:

  - servoAngle(char *servo, char *angle) // Converts angle between 0-180 to pulse width and writes to selected servo
  - servoOff(char *servo) // Sets pulse width of servo to 0, turning it off
  - writeToServo(char *servo, int angle) // Private, writes pulse width to servo

servoangle.c
============

A test command line program that takes 2 arguments, servo and angle.
