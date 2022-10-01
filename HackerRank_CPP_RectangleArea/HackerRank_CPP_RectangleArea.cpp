#include <iostream>
using namespace std;

class Rectangle {
public:
    // Data Members
    int width, height;

    // Member Functions
    void display() {
        cout << width << " " << height << endl;
    }
};

class RectangleArea : public Rectangle {
public:
    void read_input() {
        cin >> width >> height;
        //cout << "I am a triangle\n";
    }
    int display() {
        int area = width * height;
        cout << area << endl;
        return area;
    }
};

/*
 * Create classes Rectangle and RectangleArea
 */


int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;

    /*
     * Read the width and height
     */
    r_area.read_input();

    /*
     * Print the width and height
     */
    r_area.Rectangle::display();

    /*
     * Print the area
     */
    r_area.display();

    return 0;
}