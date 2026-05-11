#include <iostream>
#include <cmath>

struct Vec2{
    float x,y;
<<<<<<< HEAD

//Addition
=======
    //Creating operators
>>>>>>> b56f3e09deb23b59cea32d70303db5e0d0637c59
    Vec2 operator+(const Vec2& other) const{
        Vec2 result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }
<<<<<<< HEAD

//Subtraction 
=======
    
>>>>>>> b56f3e09deb23b59cea32d70303db5e0d0637c59
    Vec2 operator-(const Vec2& other) const{
        Vec2 result;
        result.x = x - other.x;
        result.y = y - other.y;
        return result;
    }

<<<<<<< HEAD
//Scalar multiplication
=======
>>>>>>> b56f3e09deb23b59cea32d70303db5e0d0637c59
    Vec2 operator*(float scalar) const{
        Vec2 result;
        result.x = x * scalar;
        result.y = y * scalar;
        return result;
    }

<<<<<<< HEAD
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
=======
>>>>>>> b56f3e09deb23b59cea32d70303db5e0d0637c59
    float length() const{
        return std::sqrt(x*x + y*y);
    }

<<<<<<< HEAD
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
=======
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
>>>>>>> b56f3e09deb23b59cea32d70303db5e0d0637c59
