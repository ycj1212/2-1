#include "pgm_circle.h"
#include "circle.h"

int main() {
    Circle donut;
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;
    
    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza 면적은" << area << endl;
}