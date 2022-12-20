#include <iostream>

struct Rectangle {
    int x, y; // Lower left corner
    unsigned width, height;
};

/**
 * @brief Check if two rectangles are overlapping.
 * @param r1 
 * @param r2 
 * @return true 
 * @return false 
 */
Rectangle intersection(Rectangle r1, Rectangle r2) {
    int e1_x = r1.x + r1.width, e1_y = r1.y + r1.height;
    int e2_x = r2.x + r2.width, e2_y = r2.y + r2.height;

    // true if overlap -- s1 <= e2 && s2 <= e1
    if( (r1.x <= e2_x && r2.x <= e1_x) && 
        (r1.y <= e2_y && r2.y <= e1_y) ) {
        
        return {
            std::max(r1.x, r2.x), // 'worst' of starting x
            std::max(r1.y, r2.y), // 'worst' of starting y
            unsigned(std::min(e1_x, e2_x) - std::max(r1.x, r2.x)), 
            unsigned(std::min(e1_y, e2_y) - std::max(r1.y, r2.y))
        };
    }
    
    // no overlap return null rectangle
    return {0, 0, 0, 0};
}

void outputRectangle(Rectangle r) {
    std::cout << "(" << r.x << "," << r.y
        << ") -- [" << r.width << "," << r.height << "]" << std::endl;
}

int main() {
    // Test cases
    Rectangle t1_1({0,0,3,4}), t1_2({0,0,3,4});
    Rectangle t2_1({-2,4,3,3}), t2_2({-3,2,7,8});

    std::cout << "Test 1 Inputs:" << std::endl;
    outputRectangle(t1_1);
    outputRectangle(t1_2);
    
    std::cout << "Result 1:" << std::endl;
    outputRectangle(intersection(t1_1, t1_2));

    std::cout << std::endl << std::endl;

    std::cout << "Test 2 Inputs:" << std::endl;
    outputRectangle(t2_1);
    outputRectangle(t2_2);
    
    std::cout << "Result 2:" << std::endl;
    outputRectangle(intersection(t2_1, t2_2));
}