# yeastcpp - Growth Opportunities

## Missing Features

### 1. No equality/comparison operators
None of the data structures provide `operator==` or `operator!=`. This makes it impossible to compare states, write assertions in tests, or deduplicate data without manual field-by-field comparison.

### 2. No timestamp on `OdometrySample` or `MotionSample`
Unlike `AbsolutePoseEstimate` which has a `timestamp` field, `OdometrySample` and `MotionSample` have no temporal information. This makes it difficult to compute derivatives (velocity from position, acceleration from velocity) or perform time-based filtering.

### 3. No arithmetic operators on geometric types
`Translation2D`, `Rotation2D`, and `Twist2D` lack arithmetic operators (`+`, `-`, `*`), making it cumbersome to do basic geometric math outside these classes. `Twist2D::norm()` is the only utility method provided.

### 4. Trajectory has no typed access or validation
`Trajectory` (trajectory.hpp) stores raw JSON. Adding typed accessors for waypoints, constraints, and events would catch errors at construction time rather than at follow time.

## Architectural Enhancements

### 5. Use `double` instead of `float` for all numeric fields
Align with the JSON schema (`"type": "number"` = double) and ROS2 messages (`float64`). Currently every conversion between yeast types and ROS2/WPILib involves implicit float-to-double narrowing.

### 6. Consolidate `OdometrySample` and `MotionSample`
These are structurally identical. Consider making one an alias or deriving from a common base to eliminate ~100 lines of duplicate code.

### 7. Template or CRTP the JSON serialization pattern
Every data structure follows the identical pattern: constructor from JSON, `from_json`, `to_json`. A CRTP base or code generator would reduce boilerplate and eliminate the inconsistencies (like the missing `accel` in SwerveModuleCommand serialization).

### 8. Make component interfaces accept `const&` parameters
`DriveController::drive()` takes `MotionCommand` by value. `DriveFilter::filter()` takes both args by value. `Follower::begin()` takes `Trajectory` and `MotionState` by value. All should take `const&` to avoid copies.

## Testing Gaps

### 9. No unit tests whatsoever
There is no test directory, no test CMakeLists.txt, and no test files. Critical areas that need testing:
- JSON round-trip for every data structure (serialize then deserialize, check equality)
- Edge cases in `from_json` (missing keys, wrong types, empty objects)
- `MotionSample`/`OdometrySample` cross-assignment operators
- `Twist2D::norm()` correctness

### 10. No CI configuration
No `.github/workflows`, no `.gitlab-ci.yml`, no build/test automation of any kind.
