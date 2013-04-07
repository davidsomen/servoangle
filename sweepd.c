#include "servoanglelib.h"
#include <signal.h>

void handler(int num)
{
    servoOff(2);
}

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        signal(SIGTERM, &handler);
        
        int delay = atoi(argv[1]);
        int servo = 2;
        int angle1 = 0;
        int angle2 = 90;
        int angle3 = 180;
        
        while(1)
        {
            servoAngle(servo, angle1);
            sleep(delay);
            servoAngle(servo, angle2);
            sleep(delay);
            servoAngle(servo, angle3);
            sleep(delay);
            servoAngle(servo, angle2);
            sleep(delay);
        }
    }
	return 0;
}

