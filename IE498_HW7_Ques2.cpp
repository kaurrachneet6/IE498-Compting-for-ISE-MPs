// IE 498 HW 7
// Question 2
// Defining class Circle and its member functions
#include<iostream>
using namespace std;
class Circle
{
	double radius;
	double pi = 3.14159; // Private memebers by default
public:
	Circle() { radius = 0.0; }  // Default constructor
	Circle(double r) { radius = r; }  // Constructor with parameter
	void setRadius(double r) { radius = r; }  // Assigning radius
	double getRadius() { return radius; }     // Returning radius
	double getArea() { return (pi *radius *radius); }  // Returning area
	double getDiameter() { return (2*radius); }    // Returning diameter
	double getCircumference() { return (2*pi*radius); }   // Returning circumference
};

int main()
{
	double r;
	cout << "Enter the radius: ";
	cin >> r;    // Taking radius as input from user
	Circle c;   // Creating class object
	c.setRadius(r);   // Setting the radius as r (taken from user as input)
	cout<<"\n Area for Circle is: "<<c.getArea();  // Printing area
	cout << "\n Diameter for Circle is: " << c.getDiameter();  // Printing Diameter
	cout << "\n Circumference for Circle is: " << c.getCircumference()<<"\n";  // Printing Circumference
	return 0;
}