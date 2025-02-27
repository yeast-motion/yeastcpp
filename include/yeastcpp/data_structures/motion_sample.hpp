#pragma once

#include <iostream>

#include "yeastcpp/data_structures/pose2d.hpp"
#include "yeastcpp/data_structures/twist2d.hpp"
#include "yeastcpp/data_structures/odometry_sample.hpp"
#include "yeastcpp/json_parsable.hpp"

namespace yeast_motion
{
    class OdometrySample;
    
    class MotionSample : JSONParsable
    {
        public:
        bool pose_valid;
        Pose2D pose;
        bool velocity_valid;
        Twist2D velocity;
        bool acceleration_valid;
        Twist2D acceleration;

        MotionSample();
        MotionSample(nlohmann::json json);
        nlohmann::json to_json() const;
        void from_json (nlohmann::json json);

        MotionSample& operator=(const OdometrySample& other);
    };
}