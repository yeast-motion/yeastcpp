#pragma once 

#include <iostream>

#include "yeastcpp/data_structures/pose2d.hpp"
#include "yeastcpp/data_structures/twist2d.hpp"
#include "yeastcpp/data_structures/motion_sample.hpp"
#include "yeastcpp/json_parsable.hpp"

namespace yeast_motion
{
    class MotionSample;

    class OdometrySample : JSONParsable
    {
        public:
        bool pose_valid;
        Pose2D pose;
        bool velocity_valid;
        Twist2D velocity;
        bool acceleration_valid;
        Twist2D acceleration;

        OdometrySample();
        OdometrySample(nlohmann::json json);
        nlohmann::json to_json() const;
        void from_json (nlohmann::json json);

       OdometrySample& operator=(const MotionSample& other);
    };
}