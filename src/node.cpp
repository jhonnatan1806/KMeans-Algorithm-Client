#include "../include/node.hpp"

Node::Node(int x, int y, int cluster) : x(x), y(y), cluster(cluster) {
    // Constructor
}

int Node::getX() const {
    return x;
}

int Node::getY() const {
    return y;
}

int Node::getCluster() const {
    return cluster;
}

void Node::setX(int x) {
    this->x = x;
}

void Node::setY(int y) {
    this->y = y;
}

void Node::setCluster(int cluster) {
    this->cluster = cluster;
}
