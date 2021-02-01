#pragma once

#include <depthai-shared/common/optional.hpp>
#include <nlohmann/json.hpp>
#include <vector>

#include "NeuralNetworkProperties.hpp"

namespace dai {

/**
 * Properties for DetectionNetwork
 */
struct DetectionNetworkProperties : NeuralNetworkProperties {
    // Generic Neural Network Info
    uint32_t nnFamily;
    float confidenceThreshold;

    // YOLO specific
    int classes;
    int coordinates;
    std::vector<float> anchors;
    std::map<std::string, std::vector<int>> anchorMasks;
    float iouThreshold;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(
    DetectionNetworkProperties, nnFamily, blobUri, blobSize, confidenceThreshold, classes, coordinates, anchors, anchorMasks, iouThreshold, numFrames)

}  // namespace dai