#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include <yeastcpp/json_parsable.hpp>
#include <yeastcpp/data_structures/follower_status.hpp>

namespace yeast_motion
{
    class EventTrigger : JSONParsable
    {
        public:
        virtual std::string name() = 0;
        virtual std::string type() = 0;
        virtual std::string criteria() = 0;

        virtual bool evaluate(FollowerStatus status) = 0;

        private:
        EventTrigger();
    };
}