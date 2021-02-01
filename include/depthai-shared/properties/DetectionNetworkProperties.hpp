#pragma once

// std
#include <vector>

// libraries
#include <nlohmann/json.hpp>

// project
#include "NeuralNetworkProperties.hpp"
#include "depthai-shared/common/DetectionNetworkType.hpp"
#include "depthai-shared/common/optional.hpp"

namespace dai {

/**
 * Properties for DetectionNetwork
 */
struct DetectionNetworkProperties : NeuralNetworkProperties {
    /// Generic Neural Network properties
    DetectionNetworkType nnFamily;
    float confidenceThreshold;

    /// YOLO specific network properties
    int classes;
    int coordinates;
    std::vector<float> anchors;
    std::map<std::string, std::vector<int>> anchorMasks;
    float iouThreshold;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
    DetectionNetworkProperties, nnFamily, blobUri, blobSize, confidenceThreshold, classes, coordinates, anchors, anchorMasks, iouThreshold, numFrames)

}  // namespace dai
