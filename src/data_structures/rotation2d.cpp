#include "yeastcpp/data_structures/rotation2d.hpp"

namespace yeast_motion
{
    Rotation2D::Rotation2D()
    {

    }

    Rotation2D::Rotation2D(nlohmann::json json)
    {
        this->from_json(json);
    }

    void Rotation2D::from_json(nlohmann::json json)
    {
        this->theta = json["theta"];
    }

    nlohmann::json Rotation2D::to_json(void) const
    {
        nlohmann::json object;
        object["theta"] = theta;
        return object;
    }
}