#include "Executorlmpl.hpp"
namespace adas
{
Executor* Executor::NewExecutor(const Pose& pose) noexcept
{
    return new(std::nothrow)Executorlmpl(pose);
}

Executorlmpl::Executorlmpl(const Pose& pose) noexcept : poseHandler(pose)
{
}

void Executorlmpl::Execute(const std::string &commands) noexcept
{
    const std::unordered_map<char,std::function<void(PoseHandler& poseHandler)>>cmderMap{
        {'M',MoveCommand()},
        {'L',TurnLeftCommand()},
        {'R',TurnRightCommand()},
        {'F',FastCommand()},
        {'B',BackCommand()},
    };

    for(const auto cmd :commands) {
        const auto it = cmderMap.find(cmd);

        if(it != cmderMap.end()) {
            it->second(poseHandler);
        }
    }
}

Pose Executorlmpl::Query(void) const noexcept
{
    return poseHandler.Query();
}

}