# yeastcpp - Issues

## Bugs / Correctness Problems

### 1. Inconsistent `public` inheritance from `JSONParsable` 
Most data structures use private inheritance from `JSONParsable` (e.g., `class Rotation2D : JSONParsable` in `include/yeastcpp/data_structures/rotation2d.hpp:9`), but `SwerveModuleCommand` uses `public` inheritance (`class SwerveModuleCommand : public JSONParsable` in `include/yeastcpp/data_structures/swerve_module_command.hpp:9`). This means polymorphic use via `JSONParsable*` pointers only works for `SwerveModuleCommand` -- all other types silently fail to be treated polymorphically. Either all should be `public` or the interface should not use virtual methods.

### 2. `MotionCommand` default constructor does not initialize `translation_valid`
In `src/data_structures/motion_command.cpp:5-9`, the default constructor sets `velocity_valid` and `acceleration_valid` to `false`, but never initializes `translation_valid`. This member is left uninitialized, which is undefined behavior when read.

### 3. `SwerveModuleCommand::from_json` ignores the `accel` field
In `src/data_structures/swerve_module_command.cpp:15-18`, `from_json` only parses `speed` and `theta`, but the class has an `accel` field (header line 13). Similarly, `to_json` (lines 22-26) only serializes `speed` and `theta`. The `accel` field is silently dropped during serialization round-trips, which means any acceleration data set on a `SwerveModuleCommand` is lost when going through JSON.

### 4. `SwerveModuleConfig::from_json` assigns `nlohmann::json` to `Translation2D` without conversion
In `src/data_structures/swerve_module_config.cpp:17`, `this->translation = json["translation"]` relies on implicit conversion from `nlohmann::json` to `Translation2D`. This requires nlohmann's ADL-based conversion which is never defined. This likely fails at compile time or produces wrong results -- other from_json implementations correctly call `Translation2D(json["translation"])` or `.from_json()`.

### 5. No JSON error handling anywhere
Every `from_json` method directly accesses keys with `json["key"]` (e.g., `absolute_pose_estimate.cpp:18`, `follower_status.cpp:18-20`, etc.) without checking for key existence or type. If any key is missing or has a wrong type, nlohmann::json throws `nlohmann::json::type_error` or `nlohmann::json::out_of_range` with no context about which data structure failed to parse.

### 6. `AbsolutePoseEstimate` missing `operator=` from `OdometrySample` implementation
The header `absolute_pose_estimate.hpp:23` declares `AbsolutePoseEstimate& operator=(const OdometrySample& other)` but this operator is never defined in `absolute_pose_estimate.cpp`. This will cause a linker error if ever used.

### 7. `float` precision for robot pose data
All geometric types (`Translation2D`, `Rotation2D`, `Twist2D`, `Pose2D`, etc.) use `float` (32-bit). For robotics odometry that accumulates over time, this provides only ~7 significant digits, which can cause visible drift for position tracking. The JSON schema uses `"type": "number"` (double-precision), and the ROS2 messages use `float64`.

## Code Smells

### 8. `OdometrySample` and `MotionSample` are nearly identical
`OdometrySample` and `MotionSample` have the exact same fields (`pose`, `pose_valid`, `velocity`, `velocity_valid`, `acceleration`, `acceleration_valid`) with identical implementations. They have cross-assignment operators to each other but are otherwise duplicate code.

### 9. Unnecessary `#include <iostream>` in almost every header
Nearly every header file includes `<iostream>` (e.g., `rotation2d.hpp:3`, `translation2d.hpp:3`, `twist2d.hpp` does not but most others do) even though none of them use any iostream functionality. This bloats compile times.

### 10. `Trajectory` is just a thin wrapper around `nlohmann::json`
`trajectory.hpp` wraps a raw `nlohmann::json` object with no structure, validation, or typed access. This pushes all validation responsibility to consumers and defeats the purpose of having a typed data structure library.

### 11. `from_json` takes `nlohmann::json` by value everywhere
All `from_json` methods and JSON constructors take `nlohmann::json` by value (e.g., `motion_command.hpp:24`), causing unnecessary copies. Should be `const nlohmann::json&`.

### 12. `CMakeLists.txt` uses `GLOB_RECURSE` for sources
`CMakeLists.txt:14-17` uses `file(GLOB_RECURSE SOURCES ...)` which will pick up files in the `build/` directory, potentially including CMake-generated .cpp files. This is a known CMake anti-pattern.
