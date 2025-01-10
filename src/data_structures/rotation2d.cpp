#include "yeastcpp/data_structures/rotation2d.hpp"

namespace yeast_motion
{
    void Rotation2D::from_json(nlohmann::json json)
    {
        // TODO: Implement.
    }

    nlohmann::json Rotation2D::to_json(void)
    {
        nlohmann::json object;
        object["theta"] = theta;
        return object;
    }
}