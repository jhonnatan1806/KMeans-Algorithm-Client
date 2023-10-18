#ifndef NODE_H
#define NODE_H

class Node {
public:
    Node(int x, int y, int cluster);  // Declaración del constructor
    int getX() const;
    int getY() const;
    int getCluster() const;
    void setX(int x);
    void setY(int y);
    void setCluster(int cluster);

private:
    int x;
    int y;
    int cluster;
};

#endif


