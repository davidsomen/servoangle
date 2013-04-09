#include "servoanglelib.h"
#include <signal.h>
#include <unistd.h>

#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define MAX_STEPS 20

// Default values
#define DELAY_DEFAULT 20
#define SERVO_DEFAULT 2
#define STEP_DEFAULT 3
#define REVERSE_DEFAULT 1

void handler(int num)
{
    servoOff(2);
}

int main(int argc, char *argv[])
{
    // Check for signal termination
    signal(SIGTERM, &handler);
    
    // Define values
    int angles[MAX_STEPS];
    int delay, servo, steps, reverse;
    
    // No argument passed
    if(argc == 1)
    {
        // Initial values
        delay = -1;
        servo = -1;
        steps = -1;
        reverse = -1;
        
        // Open config file
        FILE *config_fp = fopen("sweepd.conf", "r");
        if(config_fp == NULL)
        {
            printf("Couldn't open config file\n");
            return 0;
        }
        
        // Line variables
        char line[MAX_LINE_LEN + 1];
        char *token;
    
        while(fgets(line, MAX_LINE_LEN, config_fp) != NULL)
        {
            token = strtok(line, "\t =\n\r");
            
            if(token != NULL && token[0] != '#')
            {
                if(!strcmp(token, "delay"))
                    delay = atoi(strtok(NULL, "\t =\n\r"));
                
                if(!strcmp(token, "servo"))
                    servo = atoi(strtok(NULL, "\t =\n\r"));
                
                if(!strcmp(token, "steps"))
                    steps = atoi(strtok(NULL, "\t =\n\r"));
                
                if(!strcmp(token, "reverse"))
                {
                    if(!strcmp(strtok(NULL, "\t =\n\r"), "yes"))
                       reverse = 1;
                    else
                       reverse = 0;
                }
            }
        }
        
        // Check values are set
        if(delay == -1)
        {
            printf("delay not defined. Using default\n");
            delay = DELAY_DEFAULT;
        }
        if(servo == -1)
        {
            printf("servo not defined. Using default\n");
            servo = SERVO_DEFAULT;
        }
        if(steps == -1)
        {
            printf("steps not defined. Using default\n");
            steps = STEP_DEFAULT;
        }
        if(reverse == -1)
        {
            printf("reverse not defined. Using default\n");
            reverse = REVERSE_DEFAULT;
        }
        
        int stepAngle = 180/(steps-1);
        
        for(int i=0; i < steps; i++)
            angles[i] = stepAngle*i;
    }
    else
    {
        // Default values
        steps = STEP_DEFAULT;
        servo = SERVO_DEFAULT;
        reverse = REVERSE_DEFAULT;
        delay = DELAY_DEFAULT;
    }
    
    // Delay argument
    if(argc == 2)
    {
        delay = atoi(argv[1]);
        if(delay < 1)
        {
            printf("delay must be more than 1 (sec)");
            return 0;
        }
        
        angles[0] = 0;
        angles[1] = 90;
        angles[2] = 180;
    }
    
    // Delay and steps
    if(argc == 3)
    {
        delay = atoi(argv[1]);
        if(delay < 1)
        {
            printf("delay must be more than 1 (sec)");
            return 0;
        }
        
        steps = atoi(argv[2]);
        if(steps < 2)
        {
            printf("Must have at least 2 steps");
            return 0;
        }
        
        int stepAngle = 180/(steps-1);
        
        for(int i=0; i < steps; i++)
            angles[i] = stepAngle*i;
    }
    
    // Delay and angles argument
    if(argc > 3)
    {
        steps = argc-2;
        
        delay = atoi(argv[1]);
        if(delay < 1)
        {
            printf("delay must be more than 1 (sec)");
            return 0;
        }
        
        for(int i=0; i < steps; i++)
            angles[i] = atoi(argv[i+2]);
    }
    
    // Print configuration
    printf("servo:\t%i\n", servo);
    printf("delay:\t%i\n\n", delay);
    
    // Print angles
    for(int i=0; i<steps; i++)
        printf("angle %i:\t %i\n", i+1, angles[i]);

    // Sweep loop
    while(1)
    {
        // Forward
        for(int i = 0; i<steps; i++)
        {
            servoAngle(servo, angles[i]);
            sleep(delay);
        }
        
        // Backwards
        if(reverse)
        {
            for(int i = steps-2; i>0; i--)
            {
                servoAngle(servo, angles[i]);
                sleep(delay);
            }
        }
    }
    
	return 0;
}