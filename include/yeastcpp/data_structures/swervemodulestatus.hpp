#pragma once

#include <iostream>

#include <yeastcpp.hpp>

class SwerveModuleStatus : JSONParsable
{
    public:
    float speed;
    float theta;

    SwerveModuleStatus (nlohmann::json json);
    nlohmann::json to_json();
    void from_json (nlohmann::json json);
};

