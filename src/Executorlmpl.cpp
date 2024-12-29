#include "Executorlmpl.hpp"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new(std::nothrow)Executorlmpl(pose);
}

Executorlmpl::Executorlmpl(const Pose& pose) noexcept : poseHandler(pose)
{
    cmderMap['M'] = std::make_unique<MoveCommand>();
    cmderMap['L'] = std::make_unique<TurnLeftCommand>();
    cmderMap['R'] = std::make_unique<TurnRightCommand>();
    cmderMap['F'] = std::make_unique<FastCommand>();
    cmderMap['B'] = std::make_unique<BackCommand>();
}

void Executorlmpl::Execute(const std::string &commands) noexcept
{
    for(const auto cmd :commands) {
        const auto it = cmderMap.find(cmd);

        if(it != cmderMap.end()) {
            it->second->DoOperate(poseHandler);
        }
    }
}

Pose Executorlmpl::Query(void) const noexcept
{
    return poseHandler.Query();
}

}