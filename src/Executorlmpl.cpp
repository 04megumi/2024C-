#include "Executorlmpl.hpp"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new(std::nothrow)Executorlmpl(pose);
}

Executorlmpl::Executorlmpl(const Pose& pose) noexcept : pose(pose)
{
}

void Executorlmpl::Execute(const std::string &commands) noexcept
{
    for(const auto cmd :commands) {
        if(cmd=='M'){
            Move();
        } else if(cmd=='L'){
            TurnLeft();
        } else if(cmd=='R'){
            TurnRight();
        }
    }
}

Pose Executorlmpl::Query(void) const noexcept
{
    return pose;
}
void Executorlmpl::Move(void) noexcept
{
    if(pose.heading=='E'){
        ++pose.x;
    } else if(pose.heading=='W') {
        --pose.x;
    } else if(pose.heading=='N') {
        ++pose.y;
    } else if(pose.heading=='S') {
        --pose.y;
    }
}
void Executorlmpl::TurnLeft() noexcept
{
    if(pose.heading=='E'){
        pose.heading='N';
    } else if(pose.heading=='N') {
        pose.heading='W';
    } else if(pose.heading=='W') {
        pose.heading='S';
    } else if(pose.heading=='S') {
        pose.heading='E';
    }
}
void Executorlmpl::TurnRight() noexcept
{
    if(pose.heading=='E'){
        pose.heading='S';
    } else if(pose.heading=='S') {
        pose.heading='W';
    } else if(pose.heading=='W') {
        pose.heading='N';
    } else if(pose.heading=='N') {
        pose.heading='E';
    }
}
}