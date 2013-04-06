#include <servoanglelib.h>

int main(int argc, char *argv[])
{
	if(argc == 3)
	{
        if(!strcmp(argv[2], "off"))
            servoOff(argv[1]);
        else
            servoAngle(argv[1], argv[2]);
        
		return 0;
	}
    
    printf("Invalid input USAGE:<servo 0-7> <angle 0-180, off>\n");
	return 0;
}