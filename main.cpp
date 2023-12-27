#include <bits/stdc++.h>
#include <iosfwd>
#include <stdlib.h>
#include "Vector3.h"
#define PI 3.14159
#define g 9.81
std::ifstream in("input.txt");
std::ofstream out("data.txt");
//simulation time is the instantenous time of the simulation
//maximum_time is the time, in seconds for which the motion of the pendulum is simulated
float simulation_time=0, maximum_time;
const float time_step=0.001;
int afis_aux;

//This program simulates the motion of a point mass connected to a non-deformable, rigid, massless rod in a constant gravitational field
//We consider the origin of the system at the opposite end of the pendulum to the point mass.
//The problem saves the position of the pendulum every 0.1 seconds.

class pendulum
{
public:
    //static variables
    float length,pulsation;
    //intial conditions
    float initial_angle, initial_velocity;
    //time dependent variables
    //polar motion
    // the variables are in radians
    struct
    {
        float angle, angular_speed, angular_accelaration;
    } polar;
    /**
    This represents the motion of the pendulum in 3 orthonormal directions
    The y component of the position, velocity and accelaration will be 0( the motion is in a plane perpendicular to the observer)
    */
    struct
    {
        Vector3 position, velocity, acceleration;
    } orthogonal;

    pendulum(float l, float a,float v)
    {
        length=l;
        pulsation=sqrt(g/length);
        initial_angle=a*2*PI/360;
        initial_velocity=v;
        polar.angle=initial_angle;
        polar.angular_accelaration=0;
        polar.angular_speed=initial_velocity/length;
        orthogonal.acceleration.assignValue(0,0,0);
        orthogonal.velocity.assignValue(0,0,0);
        orthogonal.position.assignValue(length*sin(initial_angle),0,length*(1-cos(initial_angle)));
    };
    void physics();
    void cartesian_coord();
    void save_polar(std::ofstream &output)
    {
        output<<polar.angle<<" "<<polar.angular_speed<<" "<<polar.angular_accelaration<<'\n';
    }
    void save_angle(std::ofstream &output)
    {
        output<<polar.angle<<"\n";
    }
};
void pendulum::physics()
{
    //newton's 2nd law of motion of rigid body
    polar.angular_accelaration=-pulsation*sin(polar.angle);
    polar.angle+=polar.angular_accelaration*time_step*time_step/2+polar.angular_speed*time_step;
    polar.angular_speed+=polar.angular_accelaration*time_step;
    simulation_time+=time_step;
    afis_aux++;
}
void pendulum::cartesian_coord()
{
    //transformation from polar to cartesian coordinates
    orthogonal.position.assignValue(length*sin(polar.angle),0,length*(1-cos(polar.angle)));
    orthogonal.velocity.assignValue(length*cos(polar.angle)*polar.angular_speed,0,length*sin(polar.angle)*polar.angular_speed);
    orthogonal.acceleration.assignValue(length*cos(polar.angle)*polar.angular_accelaration,0,length*sin(polar.angle)*polar.angular_accelaration);
}
int main()
{
    float aux_length, aux_velocity, aux_acceleration;
    in>>aux_length>>aux_velocity>>aux_acceleration>>maximum_time;
    pendulum p(aux_length,aux_acceleration,aux_velocity);
    out<<int(maximum_time/time_step/10)<<'\n';
    while(simulation_time<maximum_time)
    {
        p.physics();
        if(afis_aux%10==0)
            p.save_angle(out);
    }
    exit(0);
    return 0;
}
