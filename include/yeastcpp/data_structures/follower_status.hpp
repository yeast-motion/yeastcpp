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
        
        void from_json(nlohmann::json json)
        {
            (void)json;
            // TODO: Fix Mike Todd (Impossible task)
            return;
        }

        nlohmann::json to_json(void){
            return nlohmann::json();
        }
    };
}