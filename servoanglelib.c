#include <servoanglelib.h>

int writeToServo(char *cServo, int pulse)
{
    // Open file
    FILE *fp = fopen("/dev/servoblaster", "w");
    if(fp == NULL)
    {
        printf("Couldn't open file\n");
        return 0;
    }
    
	// Write value to file
	fprintf(fp, "%s=%i\n", cServo, pulse);
    
	// Close file
	fclose(fp);
    
    return 1;
}

int servoAngle(char *cServo, char *cAngle)
{
    // Convert angle to int
    int angle = atoi(cAngle);
        
    // Check boundaries
    if (angle < 0 || angle > 180)
    {
        printf("Angle must be between 0 and 180\n");
        return 0;
    }
    
    // Convert angle to pulse width
    int pulse = angle + 60;
    
    if (writeToServo(cServo, pulse))
        return 1;
}

int servoOff(char *cServo)
{
    if(writeToServo(cServo, 0))
        return 1;
}