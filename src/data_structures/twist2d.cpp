#include "yeastcpp/data_structures/twist2d.hpp"

namespace yeast_motion
{
    Twist2D::Twist2D(nlohmann::json json)
    {
        this->from_json(json);
    }

    void Twist2D::from_json(nlohmann::json json)
    {
        this->x = json["x"];
        this->x = json["x"];
        this->omega = json["omega"];
    }

    nlohmann::json Twist2D::to_json(void)
    {
        nlohmann::json json;
        json["x"] = x;
        json["y"] = y;
        json["omega"] = omega;
        return json;
    }
}