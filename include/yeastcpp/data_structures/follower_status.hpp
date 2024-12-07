#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include <yeastcpp/json_parsable.hpp>

namespace yeast_motion
{
    class FollowerStatus : JSONParsable
    {
        public:
        
        FollowerStatus(nlohmann::json json);
    };
}