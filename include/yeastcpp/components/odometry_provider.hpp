#pragma once

#include <iostream>

#include "yeastcpp/data_structures/rotation2d.hpp"
#include "yeastcpp/data_structures/odometry_sample.hpp"
#include "yeastcpp/data_structures/swerve_module_status.hpp"
#include "yeastcpp/data_structures/absolute_pose_estimate.hpp"

namespace yeast_motion
{
    class OdometryProvider
    {
        public:
        virtual OdometrySample update (std::vector<SwerveModuleStatus> status, Rotation2D gyro_angle) = 0;
        virtual OdometrySample reset (OdometrySample reset_sample) = 0;
        virtual void provide_absolute_position_estimate (AbsolutePoseEstimate estimate) = 0;
    };
}