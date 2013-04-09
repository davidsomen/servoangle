#include "servoanglelib.h"

int main(int argc, char *argv[])
{
	if(argc == 3)
	{
        char *servo = argv[1];
        char *angle = argv[2];
        
        if(!strcmp(angle, "off"))
        {
            servoOff(atoi(servo));
        }
        else
        {
            servoAngle(atoi(servo), atoi(angle));
        }
        
		return 0;
	}
    
    printf("Invalid input USAGE:<servo 0-7> <angle 0-180, off>\n");
	return 0;
}