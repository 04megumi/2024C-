#include "PoseHandler.hpp"

namespace adas
{
PoseHandler::PoseHandler(const Pose& pose) noexcept : pose(pose), fast(false), back(false) 
{}

void PoseHandler::Move(void) noexcept
{
    if(pose.heading=='E'){
        if(!back) {
            ++pose.x;
        } else {
            --pose.x;
        }   
    } else if(pose.heading=='W') {
        if(!back) {
            --pose.x;
        } else {
            ++pose.x;
        }   
    } else if(pose.heading=='N') {
        if(!back) {
            ++pose.y;
        } else {
            --pose.y;
        } 
    } else if(pose.heading=='S') {
        if(!back) {
            --pose.y;
        } else {
            ++pose.y;
        } 
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
    return pose;
}

}