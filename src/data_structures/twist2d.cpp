#include "yeastcpp/data_structures/twist2d.hpp"

namespace yeast_motion
{
    void Twist2D::from_json(nlohmann::json json)
    {
        return;
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