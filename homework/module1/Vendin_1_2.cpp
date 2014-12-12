#include <iostream>
#include <math.h>
float area(float a, float b, float c) {
    float p = (a + b + c) / 2;
    return sqrt(p*(p - a)*(p - b)*(p - c));
}

float length_side(int x1, int y1, int x2, int y2) {
    return sqrt ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

class polygon {
    private:
        float S = 0;
        int *ver_x, *ver_y, n;
    public:
        polygon();
        float area_polygon();
        friend float length_side(int, int, int, int);
        friend float area(int, int, int);
};

polygon::polygon() {
    std::cin >> n;
    ver_x = new int[n];
    ver_y = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> ver_x[i];
        std::cin >> ver_y[i];
    }
}

float polygon::area_polygon() {
    for (int t = 2; t < n; t++) {
        S += area(length_side(ver_x[0], ver_y[0], ver_x[t], ver_y[t]), length_side(ver_x[0], ver_y[0], ver_x[t - 1], ver_y[t - 1]), \
            length_side(ver_x[t - 1], ver_y[t - 1], ver_x[t], ver_y[t]));
    }
    std::cout << S <<std:: endl;
    return S;
}

int main() {
    polygon N;
    N.area_polygon();
    return 0;
}

