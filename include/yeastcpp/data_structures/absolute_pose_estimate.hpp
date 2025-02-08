#pragma once

#include <iostream>

#include "yeastcpp/data_structures/pose2d.hpp"
#include "yeastcpp/data_structures/twist2d.hpp"
#include "yeastcpp/data_structures/odometry_sample.hpp"
#include "yeastcpp/json_parsable.hpp"

namespace yeast_motion
{
    class OdometrySample;

    class AbsolutePoseEstimate : JSONParsable
    {
        public:
        Pose2D pose;
        float timestamp;

        AbsolutePoseEstimate();
        AbsolutePoseEstimate(nlohmann::json json);
        nlohmann::json to_json() const;
        void from_json (nlohmann::json json);

        AbsolutePoseEstimate& operator=(const OdometrySample& other);
    };
}