#include "yeastcpp/data_structures/pose2d.hpp"

namespace yeast_motion
{
    void Pose2D::from_json(nlohmann::json json)
    {
        // TODO: Implement.
    }

    nlohmann::json Pose2D::to_json(void)
    {
        nlohmann::json object;
        object["translation"] = translation.to_json();
        object["rotation"] = rotation.to_json();
        return object;
    }
}