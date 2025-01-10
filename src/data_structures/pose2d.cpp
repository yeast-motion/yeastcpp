#include "yeastcpp/data_structures/pose2d.hpp"

namespace yeast_motion
{
    Pose2D::Pose2D(nlohmann::json json)
    {
        this->from_json(json);
    }

    void Pose2D::from_json(nlohmann::json json)
    {
        this->translation = Translation2D(json["translation"]);
        this->rotation = Rotation2D(json["rotation"]);
    }

    nlohmann::json Pose2D::to_json(void)
    {
        nlohmann::json object;
        object["translation"] = translation.to_json();
        object["rotation"] = rotation.to_json();
        return object;
    }
}