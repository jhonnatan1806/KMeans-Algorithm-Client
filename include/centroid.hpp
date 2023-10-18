#ifndef CENTROID_H
#define CENTROID_H

class Centroid {
public:
    Centroid(int x, int y);
    int getX() const;
    int getY() const;

private:
    int x;
    int y;
};

#endif

