#include "CmderFactory.hpp"

namespace adas
{

CmderList CmderFactory::GetCmders(const std::string& commands) const noexcept
{
    CmderList cmders;
    bool flag = false;

    for(auto cmd : commands){
        if(cmd=='T')  flag = true;
        if(cmd=='R' && flag)
        {
            cmd = 'Z';
            flag = false;
        }
        const auto it = cmderMap.find(cmd);
        if(it!=cmderMap.end()){
            cmders.push_back(it->second);
        }
    }

    return cmders;
}

}