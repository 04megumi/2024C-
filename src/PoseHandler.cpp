#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept : point(pose.x,pose.y), facing(&Direction::GetDirection(pose.heading)), fast(false), back(false) 
{}

void PoseHandler::Move(void) noexcept
{
    if(!back) {
        point+=facing->Move();
    } else {
        point-=facing->Move();
    }   
}

void PoseHandler::TurnLeft(void) noexcept
{
    facing=&(facing->LeftOne());
}

void PoseHandler::TurnRight(void) noexcept
{
    facing=&(facing->RightOne());
}

void PoseHandler::Fast(void) noexcept
{
    fast = !fast;
}

void PoseHandler::Back(void) noexcept
{
    back = !back;
}

bool PoseHandler::IsFast(void) const noexcept
{
    return fast;
}

bool PoseHandler::IsBack(void) const noexcept
{
    return back;
}

Pose PoseHandler::Query(void) const noexcept
{
    Pose pose;
    pose.x = point.GetX(), pose.y = point.GetY();
    pose.heading = facing->GetHeading();
    return pose;
}

}