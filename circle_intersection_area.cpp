#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592653589793;

double intersectionArea(double x1, double y1, double r1, double x2, double y2, double r2) {
    // Calculate the distance between the centers of the circles
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    // Case 1: No intersection
    if (d >= r1 + r2) {
        return 0.0;
    }

    // Case 2: One circle is completely inside the other
    if (d <= fabs(r1 - r2)) {
        double smallerRadius = min(r1, r2);
        return PI * smallerRadius * smallerRadius;
    }

    // Case 3: Partial overlap
    double angle1 = 2 * acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
    double angle2 = 2 * acos((d * d + r2 * r2 - r1 * r1) / (2 * d * r2));
    double area1 = 0.5 * r1 * r1 * (angle1 - sin(angle1));
    double area2 = 0.5 * r2 * r2 * (angle2 - sin(angle2));

    return area1 + area2;
}

int main() {
    double x1, y1, r1, x2, y2, r2;

    // Input the details of the two circles
    cout << "Enter the center (x1, y1) and radius (r1) of the first circle: ";
    cin >> x1 >> y1 >> r1;
    cout << "Enter the center (x2, y2) and radius (r2) of the second circle: ";
    cin >> x2 >> y2 >> r2;

    // Calculate the intersection area
    double area = intersectionArea(x1, y1, r1, x2, y2, r2);

    // Output the result
    cout << "The area of intersection is: " << area << endl;

    return 0;
}
