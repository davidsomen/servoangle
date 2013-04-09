#include "servoanglelib.h"

int writeToServo(int servo, int pulse)
{
    // Open file
    FILE *fp = fopen("/dev/servoblaster", "w");
    if(fp == NULL)
    {
        printf("Couldn't open file\n");
        return 0;
    }
    
	// Write value to file
	fprintf(fp, "%i=%i\n", servo, pulse);
    
	// Close file
	fclose(fp);
    
    return 0;
}

int servoAngle(int servo, int angle)
{
    // Check boundaries
    if (angle < 0 || angle > 180)
    {
        printf("Angle must be between 0 and 180\n");
        return 0;
    }
    
    // Convert angle to pulse width
    int pulse = angle + 60;
    
    writeToServo(servo, pulse);
    
    return 0;
}

int servoOff(int servo)
{
    writeToServo(servo, 0);
    return 0;
}