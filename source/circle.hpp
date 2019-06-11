#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include <cmath>
#include <string>
#include <set>
#include "vec2.hpp"
#include "color.hpp"


class Circle{
    public:
        Circle():
        center_{1, 1}, radius_{1}, color_{0.5, 0.5, 0.5} {}
        Circle(Vec2 const& a, float const& radius, rgb const& color):
        center_{a}, radius_{radius}, color_{color} {}
        Circle(Vec2 const& a, float const& radius, rgb const& color, std::string name):
        center_{a}, radius_{radius}, color_{color}, name_{name} {}
    public:
        float circumference(Circle circ){
            float res = 2 * M_PI * circ.radius_;
            return res;
        }
        /*
        void draw(Window const& window, rgb const& color_) const{
	        for (int i = 0; i < 360; i++){
		        // Grad zu Bogenmaß
		        float grad1 = i * M_PI / 180.0f;
		        float grad2 = (i + 1) * M_PI / 180.0f;

		        window.draw_line(center_.x + (radius_*sin(grad1)), center_.y + (radius_*cos(grad1)), center_.x + (radius_*sin(grad2)), center_.y + (radius_*cos(grad2)), color_.r, color_.g, color_.b);
	        }
        }
        void draw(Window const& window, rgb const& color_, float const& thickness) const{
	        for (int i = 0; i < 360; i++){
		        // Grad zu Bogenmaß
		        float grad1 = i * M_PI / 180.0f;
		        float grad2 = (i + 1) * M_PI / 180.0f;

		        window.draw_line(center_.x + (radius_*sin(grad1)), center_.y + (radius_*cos(grad1)), center_.x + (radius_*sin(grad2)), center_.y + (radius_*cos(grad2)), color_.r, color_.g, color_.b, thickness);
	        }
        }
        */
        bool isInside(Vec2 const& point){
            bool inside = false;
            float distance = sqrt(pow((point.x - center_.x), 2) + pow((point.y - center_.y), 2));
            if(distance <= radius_){
                inside = true;
            }
            return inside;
        }
        std::ostream& print(std::ostream& ostream) const{
            ostream << "Name: " << name_ << std::endl << "Position im Koordinatensystem: " << center_.x << ", " << center_.y << std::endl << "Radius: " << radius_ << std::endl << "Farbe in rgb: " << color_.r << ", " << color_.g << ", " << color_.b << std::endl;
            return ostream;
        }
        std::string getName() const{
            return name_;
        }
        float getRadius() const{
            return radius_;
        }
        bool operator<(Circle const& circle)const{
            return(radius_ < circle.radius_);
        }
        bool operator>(Circle const& circle)const{
            return(radius_ > circle.radius_);
        }
        bool operator==(Circle const& circle)const{
            return(radius_ == circle.radius_);
        }
    private:
        std::string name_;
        float radius_;
        Vec2 center_;
        rgb color_;
};

std::ostream& operator<<(std::ostream& ostream, Circle const& circle){
    circle.print(ostream);
    return ostream;
}

#endif // CIRCLE_HPP