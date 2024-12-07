#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

#include <cppyeastdefinitions/json_parsable.hpp>
#include <cppyeastdefinitions/data_structures/follower_status.hpp>

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