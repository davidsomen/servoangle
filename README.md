Servo Angle
==========

A library to be used in conjunction with ServoBlaster for the Raspberry Pi for using degrees rather than pulse widths. Currently, SerboBlaster daemon (servod) must be running beforehand for servoangle to work.

ServoBlaster can be found here: git://github.com/richardghirst/PiBits.git

To install, clone the repository and run 'make' in the repository directory to compile automagically. Moving the servoanglelib.o library file to /usr/local/lib and servoanglelib.h header file to /usr/local/include should make the library globally available.

servoanglelib
===============

The servo angle library file contains 2 public functions:

  - servoAngle(char *servo, char *angle) // Converts angle between 0-180 to pulse width and writes to selected servo
  - servoOff(char *servo)                // Sets pulse width of servo to 0, turning it off

sweepd
======

A daemon (or will be soon. Can run in background using sweepd &) that sweeps the servo through several steps at varying angles. Has 3 different usage syntax:

  - sweepd                                        // Uses config file
  - sweepd (delay in sec)                       // Set delay, rest is default
  - sweepd (delay in sec) (steps)                 // Set delay and number of steps, rest is default
  - sweepd (delay in sec) (angle1, angle2, ...)    // Set delay and limitless explicit angles to sweep to

Config file sets the following:

  - servo   // Servo to use
  - delay   // Delay in seconds between changing angle
  - steps   // Number of angles to equally spread through from 0 to 180
  - reverse // Takes "yes" to reverse the angles on the sweep back or to start over

servoangle
============

A test command line program that takes 2 arguments, servo and angle.
