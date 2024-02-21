#include <iostream>
#include <unistd.h>

using namespace std;

void set_lights(int i_param);
void print_lights();

char ch_NSlights;
char ch_WElights;
int i_timer;

int main()
{

    printf("Traffic lights - north-west & south-east directions\n");
    
    while (1)
    {
        i_timer = 0;
        ch_NSlights = ch_WElights = 'R';
        for(int i = 0; i < 40; i++)
        {
            set_lights(i_timer); 
            print_lights();
            i_timer++;
            sleep(1);
        }
    }
    return 0;
}


void set_lights(int i_param)
{
    if (i_param < 2)
    {
        ch_NSlights = 'R';
        ch_WElights = 'R';
    }
    else if (i_param >= 2 & i_param < 18)
    {
        ch_NSlights = 'G';
        ch_WElights = 'R';
    }
    else if (i_param >= 18 & i_param < 20)
    {
        ch_NSlights = 'A';
        ch_WElights = 'R';
    }
    else if (i_param >= 20 & i_param < 22)
    {
        ch_NSlights = 'R';
        ch_WElights = 'R';
    }
    else if (i_param >= 22 & i_param < 38)
    {
        ch_NSlights = 'R';
        ch_WElights = 'G';
    }
    else if (i_param >= 38)
    {
        ch_NSlights = 'R';
        ch_WElights = 'A';
    }
}

void print_lights()
{
    printf("NS road: %c\tWE road: %c\tcycle time: %i\n", ch_NSlights, ch_WElights, i_timer);
}
