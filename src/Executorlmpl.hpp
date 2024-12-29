#pragma once
#include "PoseHandler.hpp"
#include "Command.hpp"
#include <unordered_map>

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
    PoseHandler poseHandler;
};
}