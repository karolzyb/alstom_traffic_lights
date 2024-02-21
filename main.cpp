/*
* Title: Alstom Recruitment - C++ Implementation Test - Traffic lights
* Author: Karol Zyber
* Date: 2022-11-25
*/

#include <iostream>
#include <unistd.h>

using namespace std;

/* Structures */
struct st_Lights
{
    char ch_NS; /* char variable indicating the traffic light color for North-South direction */
    char ch_WE; /* char variable indicating the traffic light color for West-East direction */
};

/* Function prototypes */
st_Lights set_lights(int i_timer_param);
void print_lights(st_Lights st_Lights_param, int i_timer_param);

/* Main */
int main(int argc, char *argv[])
{

    printf("Traffic lights - north-west & south-east road directions\nColor legend: R - red; G - Green; A - Amber\n\n");

    st_Lights st_Intersection_lights;

    /* Infinite loop */
    while (1)
    {
        /* Initial values for variables */
        int i_timer = 0;
        st_Intersection_lights.ch_NS = st_Intersection_lights.ch_WE = 'R';

        /* 40-seconds cycle of traffic lights */
        for (int i = 0; i < 40; i++)
        {
            st_Intersection_lights = set_lights(i_timer);
            print_lights(st_Intersection_lights, i_timer);
            i_timer++;
            sleep(1);
        }
    }

    return 0;
}

st_Lights set_lights(int i_timer_param)
/* The function sets the proper color of the traffic lights; input is an integer of time counter; return is a structure of traffic light color. */
{
    if (i_timer_param < 2)
    {
        return {'R', 'R'};
    }
    else if (i_timer_param < 18)
    {
        return {'G', 'R'};
    }
    else if (i_timer_param < 20)
    {
        return {'A', 'R'};
    }
    else if (i_timer_param < 22)
    {
        return {'R', 'R'};
    }
    else if (i_timer_param < 38)
    {
        return {'R', 'G'};
    }
    else if (i_timer_param >= 38)
    {
        return {'R', 'A'};
    }
    else
    {
        return {'R', 'R'};
    }
}

void print_lights(st_Lights struct_Lights_Param, int i_timer_param)
/* The function prints the current traffic light color only during a transition; input is an integer of the time counter. */
{
    if (i_timer_param == 0 || i_timer_param == 2 || i_timer_param == 18 || i_timer_param == 20 || i_timer_param == 22 || i_timer_param == 38)
    {
        printf("N-S road: %c\tW-E road: %c\tcycle timer: %i\n", struct_Lights_Param.ch_NS, struct_Lights_Param.ch_WE, i_timer_param);
    }
}
