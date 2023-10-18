#include "../include/processor.hpp"

void Processor::calculateClusters(const std::vector<Node>& nodes, const std::vector<Centroid>& centroids, std::vector<Gather>& gathers, bool& change) {
    for (const auto& node : nodes) {
        int index = bestDistanceIndex(node, centroids);
        if (node.getCluster() != index) {
            change = true;
        }
        const_cast<Node&>(node).setCluster(index);
        gathers[index].collectData(node.getX(), node.getY());
    }
}

int bestDistanceIndex(const Node& node, std::vector<Centroid> centroids) {
    float bestDistance = calculateDistance(node, centroids[0]);
    int bestIndex = 0;

    for (size_t i = 1; i < centroids.size(); ++i) {
        float distance = calculateDistance(node, centroids[i]);
        if (distance < bestDistance) {
            bestDistance = distance;
            bestIndex = i;
        }
    }
    return bestIndex;
}

float calculateDistance(const Node& node, const Centroid centroid) {
    float x = node.getX() - centroid.getX();
    float y = node.getY() - centroid.getY();
    return std::sqrt(x * x + y * y);
}