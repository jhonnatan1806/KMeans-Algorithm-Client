#ifndef PROCESSOR_HPP
#define PROCESSOR_HPP

#include <cmath>
#include <vector>
#include "node.hpp"
#include "centroid.hpp"
#include "gather.hpp"

class Processor {
public:
    static void calculateClusters(const std::vector<Node>& nodes, const std::vector<Centroid>& centroids, std::vector<Gather>& gathers, bool& change);
};

int bestDistanceIndex(const Node& node, std::vector<Centroid> centroids);
float calculateDistance(const Node& node, const Centroid centroid);

#endif // PROCESSOR_HPP