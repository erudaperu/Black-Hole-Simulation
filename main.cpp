#include <iostream>
#include <cmath>

struct Vec2{
    float x,y;

//Addition
    Vec2 operator+(const Vec2& other) const{
        Vec2 result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }

//Subtraction 
    Vec2 operator-(const Vec2& other) const{
        Vec2 result;
        result.x = x - other.x;
        result.y = y - other.y;
        return result;
    }

//Scalar multiplication
    Vec2 operator*(float scalar) const{
        Vec2 result;
        result.x = x * scalar;
        result.y = y * scalar;
        return result;
    }

//Division
    Vec2 operator/(float scalar) const{
        if (scalar == 0){
            return {0,0};
        }

        Vec2 result;
        result.x = x / scalar;
        result.y = y / scalar;
        return result;
    }

//Magnitude (length)
    float length() const{
        return std::sqrt(x*x + y*y);
    }

//Unit vector (normalized)
    Vec2 normalized() const{
        float len = length();
        if(len == 0){
            return {0,0};
        }
        return {x/len,y/len};
    }

//Dot product
    float dot(const Vec2& other) const{
        return x*other.x + y*other.y;
    }

//+=
    Vec2& operator+=(const Vec2& other){
        x = x + other.x;
        y = y + other.y;
        return *this;
        }
    };

struct Body{
    Vec2 position;
    Vec2 velocity;
};


int main(){
    Vec2 center = {0,0};
    Body body = {{10,10},{0,0}};
    
    for(int i=0; i<100; i++){
        Vec2 directionVector = center - body.position;
        float distance = directionVector.length();
        Vec2 directionVectorNormalized = directionVector.normalized();
        float gravity = 500;
        float softening = 100;
        float gravityStrength = gravity / (distance * distance + softening);
        Vec2 acceleration = directionVectorNormalized*gravityStrength;
        body.velocity+= acceleration;
        body.position+=body.velocity;

        std::cout 
                    << "Position: {" << body.position.x << "," << body.position.y << "}" << std::endl
                    << "Velocity: {" << body.velocity.x << "," << body.velocity.y << "}" << std::endl
                    << "Distance {" << distance << "}" << std::endl;
    }
}
