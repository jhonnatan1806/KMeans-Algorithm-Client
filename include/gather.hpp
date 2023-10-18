#ifndef GATHER_H
#define GATHER_H

class Gather {
public:
    Gather();  // Declaración del constructor
    int getX() const;
    int getY() const;
    int getSize() const;
    void collectData(int x, int y);

private:
    int x;
    int y;
    int size;
};

#endif
