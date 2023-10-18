#include "../include/json_parse.hpp"

nlohmann::json JSONParse::parseMessage(const std::string& message) {
    return nlohmann::json::parse(message);
}

std::vector<Node> JSONParse::getNodes(const nlohmann::json& dataJSON) {
    std::vector<Node> nodes;
    nodes.reserve(dataJSON.size());
    for (const auto &node : dataJSON)
    {
        nodes.emplace_back(node["x"], node["y"], node["cluster"]);
    }
    return nodes;
}

std::vector<Centroid> JSONParse::getCentroids(const nlohmann::json& centroidsJSON) {
    std::vector<Centroid> centroids;
    centroids.reserve(centroidsJSON.size());
    for (const auto &centroid : centroidsJSON)
    {
        centroids.emplace_back(centroid["x"], centroid["y"]);
    }
    return centroids;
}

std::vector<Gather> JSONParse::getGathers(int size) {
    std::vector<Gather> gathers(size);
    return gathers;
}

nlohmann::json JSONParse::createMessage(const std::vector<Node>& nodes, const std::vector<Gather>& gathers, bool sendData, bool changed)
{

    nlohmann::json jsonFull, jsonData, jsonGathers;

    if(sendData){
        for (size_t i = 0; i < nodes.size(); ++i) {
            nlohmann::json data;
            data["x"] = nodes[i].getX();
            data["y"] = nodes[i].getY();
            data["cluster"] = nodes[i].getCluster();
            jsonData[i] = data;
        }
    }else{
        jsonData = nlohmann::json::array();
    }

    for (size_t i = 0; i < gathers.size(); ++i) {
        nlohmann::json gather;
        gather["x"] = gathers[i].getX();
        gather["y"] = gathers[i].getY();
        gather["n"] = gathers[i].getSize();
        jsonGathers[i] = gather;
    }

    jsonFull["data"] = jsonData;
    jsonFull["centroids"] = jsonGathers;
    jsonFull["changed"] = changed;
    jsonFull["senddata"] = sendData;

    return jsonFull.dump();
}
