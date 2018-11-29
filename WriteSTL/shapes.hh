#pragma once
#include <vector>
#include <string>
#include <fstream>

class Design{
    private:
    std::vector<Shape> list;

    public:
    Design(){};

    void add(Shape s);

    void write(string filename);
};

class Shape{
    public:
    double x,y,z;

    Shape(double x, double y, double z);

    void volume();

    void translate(double x, double y, double z);
};

class Cube:Shape{
    public:

    Cube(double x);
    void volume();
};

class Cylinder:Shape{
    public:

    Cylinder(double x, double y);
    void volume();
};