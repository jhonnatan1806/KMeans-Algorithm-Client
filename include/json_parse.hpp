#ifndef JSONPARSE_HPP
#define JSONPARSE_HPP

#include "../lib/json.hpp"
#include "node.hpp" // Incluye la declaración de la clase Node
#include "centroid.hpp" // Incluye la declaración de la clase Centroid
#include "gather.hpp" // Incluye la declaración de la clase Gather

class JSONParse {
public:
    static nlohmann::json parseMessage(const std::string& message);
    static std::vector<Node> getNodes(const nlohmann::json& data);
    static std::vector<Centroid> getCentroids(const nlohmann::json& centroids);
    static std::vector<Gather> getGathers(int count);
    static nlohmann::json createMessage(const std::vector<Node>& nodes, const std::vector<Gather>& gathers, bool sendData, bool changed);
};

#endif // JSONPARSE_HPP
