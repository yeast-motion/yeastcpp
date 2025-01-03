#pragma once

#include <iostream>

#include "yeastcpp/data_structures/translation2d.hpp"
#include "yeastcpp/data_structures/rotation2d.hpp"

namespace yeast_motion
{
    class Pose2D
    {
        public:
            Translation2D translation;
            Rotation2D rotation;
    };
}