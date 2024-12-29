#pragma once
#include "PoseHandler.hpp"

namespace adas
{

class ICommand
{
public:
    virtual ~ICommand()=default;
    virtual void DoOperate(PoseHandler& poseHandler) const noexcept=0;
};

class MoveCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        if(poseHandler.IsFast())
        {
            poseHandler.Move();
        }
        poseHandler.Move();
    }
};

class TurnLeftCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        if(poseHandler.IsFast()){
            poseHandler.Move();
        }
        if(!poseHandler.IsBack()) {
            poseHandler.TurnLeft();
        } else {
            poseHandler.TurnRight();
        }
    }
};

class TurnRightCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        if(poseHandler.IsFast()){
            poseHandler.Move();
        }
        if(!poseHandler.IsBack()){
            poseHandler.TurnRight();
        } else {
            poseHandler.TurnLeft();
        }
    }
};

class FastCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        poseHandler.Fast();
    }
};

class BackCommand final : public ICommand
{
public:
    void DoOperate(PoseHandler& poseHandler) const noexcept override
    {
        poseHandler.Back();
    }
};

}