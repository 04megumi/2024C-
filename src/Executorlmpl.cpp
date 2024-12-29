#include "Executorlmpl.hpp"
#include "CmderFactory.hpp"
#include "Singleton.hpp"

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
    const auto cmders = std::Singleton<CmderFactory>::Instance().GetCmders(commands);

    std::for_each(
        cmders.begin(),cmders.end(),
        [this](const Cmder& cmder)noexcept{cmder(poseHandler);});
}

Pose Executorlmpl::Query(void) const noexcept
{
    return poseHandler.Query();
}

}