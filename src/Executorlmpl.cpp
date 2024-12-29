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
    std::unordered_map<char, std::function<void(PoseHandler& poseHandler)>>cmderMap;

    MoveCommand moveCommand;
    cmderMap.emplace('M', moveCommand.operate);
    
    TurnLeftCommand turnLeftCommand;
    cmderMap.emplace('L', turnLeftCommand.operate);

    TurnRightCommand turnRightCommand;
    cmderMap.emplace('R', turnRightCommand.operate);

    FastCommand fastCommand;
    cmderMap.emplace('F', fastCommand.operate);

    BackCommand backCommand;
    cmderMap.emplace('B', backCommand.operate);

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