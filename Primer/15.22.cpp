#include <iostream>
#include <string>

class Shape {
	std::string _id;
public:
	Shape(const std::string& i = "unknown") : _id(i) {}
	std::string id() const {
		return _id;
	}
	virtual double area() const = 0;
};

class Polygon: public Shape {
public:
	Polygon(const std::string& n) : Shape(n) {}
};

class Rectangle: public Polygon {
protected:
	double angle_a;
	double angle_b;
	double side_a;
	double side_b;
public:
	Rectangle(double ang_a, double ang_b, double sa, double sb, const std::string& id = "unknown")
		: Polygon(id), angle_a(ang_a), angle_b(ang_b), side_a(sa), side_b(sb) {}
	double area() const override {
		return side_a * side_b;
	}
};

class Square: public Rectangle {
public:
	Square(double side, const std::string& id = "unknown")
		: Rectangle(90, 90, side, side, id) {}
};

int main () {
	Square s(10, "first square");
	std::cout << s.area() << std::endl;
	std::cout << s.id() << std::endl;
}
