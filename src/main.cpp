#include <iostream>
#include <cstdlib>
#include <vector>
#include "../include/socket_manager.hpp"
#include "../include/json_parse.hpp"
#include "../include/processor.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Use: " << argv[0] << "<addr_IP> <port>" << std::endl;
        return 1;
    }

    const char* serverIP = argv[1];
    int serverPort = std::atoi(argv[2]);

    SocketManager client(serverIP, serverPort);
    if(!client.connectToServer()) {
        return -1;
    }


    // 1. Recibir datos del servidor
    std::string messageReceived;
    while (messageReceived.empty()) {
        messageReceived = client.receiveData();
    }

    // 2. Procesar datos
    nlohmann::json objectJSON = JSONParse::parseMessage(messageReceived);
    std::vector<Node> nodes = JSONParse::getNodes(objectJSON["data"]);
    std::vector<Centroid> centroids = JSONParse::getCentroids(objectJSON["centroids"]);
    std::vector<Gather> gathers = JSONParse::getGathers(centroids.size());
    bool sendData = objectJSON["senddata"];
    bool changed = objectJSON["changed"];

    while (true) {
        // 3. Calcular nuevos clusters de los nodos, nodo.cluster cambia de valor y change también cambia de valor si es necesario
        Processor::calculateClusters(nodes, centroids, gathers, changed);

        // 4. Enviar mensaje al servidor
        std::string messageToSend = JSONParse::createMessage(nodes, gathers, sendData, changed);
        client.sendData(messageToSend);

        // 5. Recibir datos del servidor
        messageReceived = client.receiveData();

        while (messageReceived.empty()) {
            messageReceived = client.receiveData();
        }

        // 6. Procesar datos
        objectJSON = JSONParse::parseMessage(messageReceived);
        centroids = JSONParse::getCentroids(objectJSON["centroids"]);
        gathers = JSONParse::getGathers(centroids.size());
        sendData = objectJSON["senddata"];
        changed = objectJSON["changed"];
    }

    return 0;
}