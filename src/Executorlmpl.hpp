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
    
    class MoveCommand final
    {
    public:
        void DoOperate(Executorlmpl& executor) const noexcept
        {
            executor.Move();
        }
    };

    class TurnLeftCommand final
    {
    public:
        void DoOperate(Executorlmpl& executor) const noexcept
        {
            executor.TurnLeft();
        }
    };

    class TurnRightCommand final
    {
    public:
        void DoOperate(Executorlmpl& executor) const noexcept
        {
            executor.TurnRight();
        }
    };
};
}