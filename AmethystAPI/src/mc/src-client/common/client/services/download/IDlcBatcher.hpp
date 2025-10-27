#pragma once
#include <vector>
#include <string>

class DlcId;
class IDlcBatchModel;
struct PackIdVersion;

class IDlcBatcher {
public:
    /// @vidx {0}
    virtual ~IDlcBatcher() = default;

    /// @vidx {1}
    virtual IDlcBatchModel& getDlcBatchModel(std::vector<DlcId> const&) = 0;

    /// @vidx {2}
    virtual IDlcBatchModel& getDlcBatchModel(std::vector<std::string> const&) = 0;

    /// @vidx {3}
    virtual IDlcBatchModel& getDlcBatchModel(std::vector<PackIdVersion> const&) = 0;
};