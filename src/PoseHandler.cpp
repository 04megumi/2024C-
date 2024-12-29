#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose), fast(false) {}

void PoseHandler::Move(void) noexcept
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

void PoseHandler::TurnLeft(void) noexcept
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

void PoseHandler::TurnRight(void) noexcept
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

void PoseHandler::Fast(void) noexcept
{
    fast = !fast;
}

bool PoseHandler::IsFast(void) const noexcept
{
    return fast;
}

Pose PoseHandler::Query(void) const noexcept
{
    return pose;
}

}