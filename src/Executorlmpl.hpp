#pragma once
#include "Executor.hpp"

namespace adas
{
class Executorlmpl final : public Executor
{
public:
    explicit Executorlmpl(const Pose& pose)noexcept;
    ~Executorlmpl()noexcept=default;

    Executorlmpl(const Executorlmpl&)=delete;
    Executorlmpl& operator=(const Executorlmpl&)=delete;

public:
    void Execute(const std::string& commands) noexcept override;
    Pose Query(void) const noexcept override;


private:
    Pose pose;

private:
    void Move(void) noexcept;
    void TurnLeft() noexcept;
    void TurnRight() noexcept;

    
    class ICommand
    {
    public:
        virtual ~ICommand()=default;
        virtual void DoOperate(Executorlmpl& executor) const noexcept=0;
    };

    class MoveCommand final : public ICommand
    {
    public:
        void DoOperate(Executorlmpl& executor) const noexcept override
        {
            executor.Move();
        }
    };

    class TurnLeftCommand final : public ICommand
    {
    public:
        void DoOperate(Executorlmpl& executor) const noexcept override
        {
            executor.TurnLeft();
        }
    };

    class TurnRightCommand final : public ICommand
    {
    public:
        void DoOperate(Executorlmpl& executor) const noexcept override
        {
            executor.TurnRight();
        }
    };

};
}