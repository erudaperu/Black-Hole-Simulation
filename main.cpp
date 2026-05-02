#include <iostream>
#include <cmath>

struct Vec2{
    float x,y;
    //Creating operators
    Vec2 operator+(const Vec2& other) const{
        Vec2 result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }
    
    Vec2 operator-(const Vec2& other) const{
        Vec2 result;
        result.x = x - other.x;
        result.y = y - other.y;
        return result;
    }

    Vec2 operator*(float scalar) const{
        Vec2 result;
        result.x = x * scalar;
        result.y = y * scalar;
        return result;
    }

    float length() const{
        return std::sqrt(x*x + y*y);
    }

    float normalized() const{
        Vec2 result;
        result.x = x/length;
        result.y = y/length;
        return result;

    }
};


int main() {
    Vec2 a{1,2};
    Vec2 b{3,4};
    Vec2 c = a + b;
    std::cout << c.x << "," << c.y <<std::endl;
    std::cout << "Sub: " << (a - b).x << "," << (a - b).y << std::endl;
    std::cout << "Mul: " << (a * 2).x << "," << (a * 2).y << std::endl;
    std::cout << "Len a: " << a.length() << std::endl;
}