#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

//the default value in the class constructor only in the .h file 
//and the develop methods also in the .h file

class Squere;

class twoPoint {
public:
	twoPoint (int = 1, int = 2);
	static int howExists;
	static void getHowExists ();

	friend bool sameSide (twoPoint& point, Squere& squere);

	int getOne () const { return this->one; };
	int getTwo () const { return (*this).two; };

	void operator+ (const twoPoint& point);
	bool operator< (int);
	operator int () { return one + two; }	//converter operator with twoPoint to int

private:
	int one;
	int two;
};

int twoPoint::howExists{ 0 };	//must be initialized

int squereFunction (int x) { return x * x; }

//abstract class
class Shape {
public:
	virtual ~Shape () = default;	//virtual destructor

	virtual double field () = 0;	//abstract function
	virtual void setSide (int) = 0;
};

//inheritance class
class Squere : public Shape {
public:
	Squere () = default;	//all variables must be initialized
	Squere (int x) { side = x; }	//constructor with parameter

	double field () override;	//override virtual function

	void getSide () const;	//const function can not modify anything in it
	int getSideValue () const { return side; }
	void setSide (int x) override;

	friend bool sameSide (twoPoint& point, Squere& squere);

	Squere* operator+ (int);

private:
	int side{ 1 };
};

bool sameSide (twoPoint& point, Squere& squere);

void printFields (std::vector<Shape*> const shapes);

class Mid;

class Up {
protected:
	void methodA () { std::cout << "Up\n"; }
public:
	void getMidMethod ();
};

class Mid {
public:
	void methodB () { std::cout << "Mid\n"; }
	friend class Up;
};

//multi inheritances 
class Down : public Up, public Mid {
public:
	void all () {
		methodA ();
		methodB ();
	}
};

class Calculator {
public:
	//overload method
	int sum (int a, int b) { return a + b; }
	double sum (double a, double b) { return a + b; }
};

//pointer in class
class Pointer {
public:
	Pointer () { point = new int; }
	Pointer (int a) { point = new int; *point = a; }
	~Pointer () { point = nullptr; delete point; }
	void getPoint () { std::cout << *point << "\n"; }
	void setPoint (int x) { *point = x; }

private:
	int* point;
};

class FourthPoint {
public:
	FourthPoint (int a, int b, int c, int d) : firstPoint (a, b), secondPoint (c, d) { }
	twoPoint firstPoint;
	twoPoint secondPoint;
};

template<class T>
class IsAChar {
public:
	IsAChar (T a) : n (a) { std::cout << "n is not a char!\n"; };

	void getN ();
private:
	T n;
};

template<>
class IsAChar<char> {
public:
	IsAChar (char a) : n (a) { std::cout << "n is a char!\n"; };

private:
	char n;
};

template<typename T, int number, class R>
class PointThird {
public:
	PointThird (T d, R e) : a (d), b (e), c (number) {}
private:
	T a;
	R b;
	int c;
};

class Level1 {
	int a;
public:
	Level1 (int x = 0) :a (x) {}
	int getA ()const { return a; }

	class Level2 {
		int b;
	public:
		Level2 (int x = 0) : b (x) {}
		int getB ()const { return b; }
	};
};

class Point {
	int x;
	int y;
	std::string name;

public:
	Point (int one, int two = 2, std::string name = "ka") { x = one; y = two; this->name = name; }

	void showAll () const { std::cout << name << " " << this->x << " " << (*this).y << "\n"; }
	Point& setX (int one) { x = one; return *this; }
	Point& setY (int two) { y = two; return *this; }

	Point operator+ (Point);
	friend Point operator-(Point, Point);
	friend std::ostream& operator<<(std::ostream&, Point&);
};

int main_5 ()
{
	Squere first (5);
	Squere second;

	std::vector<Shape*> shapes;
	shapes.push_back (&first);
	shapes.push_back (&second);

	second.setSide (2);
	second.getSide ();

	printFields (shapes);

	/*-----------------------------------------------------------*/

	std::cout << "\n";

	twoPoint::getHowExists ();
	twoPoint point (2, 5);
	point.getHowExists ();

	/*-----------------------------------------------------------*/

	std::cout << "\n";
	twoPoint pointTwo (1, 3);
	point + pointTwo;

	std::cout << point.getOne () << " " << point.getTwo () << "\n";

	if (point < 1) std::cout << "Is hight.\n";
	else std::cout << "Is low.\n";

	/*-----------------------------------------------------------*/

	std::cout << "\n";

	Squere third (4);
	Squere fourth (3);

	Shape* shapeOne;
	shapeOne = &third;
	Shape* shapeTwo = &fourth;

	std::cout << shapeOne->field () << "\n";
	shapeTwo->setSide (15);
	shapeOne = &fourth;
	std::cout << shapeOne->field () << "\n";

	shapeOne = nullptr;
	shapeTwo = nullptr;
	delete shapeOne;
	delete shapeTwo;

	/*-----------------------------------------------------------*/

	std::cout << "\n";

	Squere* fifth = new Squere (2);
	std::cout << fifth->field () << "\n";

	delete fifth;

	/*-----------------------------------------------------------*/

	std::cout << "\n" <<
		sameSide (point, first) << "\n";

	/*-----------------------------------------------------------*/

	std::cout << "\n";

	Squere* sixth = second + 1;
	std::cout << sixth->field () << "\n";

	delete sixth;

	/*-----------------------------------------------------------*/

	std::cout << "\n";

	Down up;
	up.all ();

	/*-----------------------------------------------------------*/

	std::cout << "\n";

	Up upper;
	upper.getMidMethod ();

	/*-----------------------------------------------------------*/

	std::cout << "\n";

	Calculator calculator;
	std::cout << "Sum: " << calculator.sum (14, 4) << "\n";
	std::cout << "Sum: " << calculator.sum (14.0, 4.5) << "\n";

	/*-----------------------------------------------------------*/

	std::cout << "\n";

	Pointer* pointerTable = new Pointer[2];

	pointerTable[0].setPoint (3);
	pointerTable[0].getPoint ();

	delete[] pointerTable;

	/*-----------------------------------------------------------*/

	std::cout << "\n";

	std::cout << squereFunction (point) << "\n";

	/*-----------------------------------------------------------*/

	std::cout << "\n";

	FourthPoint pointing (1, 2, 3, 4);
	std::cout << pointing.firstPoint.getOne () << " " << pointing.firstPoint.getTwo () << "\n";

	/*-----------------------------------------------------------*/

	std::cout << "\n";

	IsAChar<int> charI (2);
	IsAChar<char> charC ('h');

	/*-----------------------------------------------------------*/

	PointThird<int, 3, double> thePoint (2, 5.4);
	
	/*-----------------------------------------------------------*/

	std::cout << "\n";
	Level1 lv1 (3);
	Level1::Level2 lv2 (4);
	std::cout << lv1.getA () << "\n";
	std::cout << lv2.getB () << "\n";
	std::cout << "\n";

	/*-----------------------------------------------------------*/

	Point point_1 (1, 2, "a");

	point_1.setX (3).setY (4).showAll ();

	std::cout << point_1;
	operator<<(std::cout, point_1);
	std::cout << "\n";

	/*-----------------------------------------------------------*/

	Point point_2 (2,1);

	Point sum = point_1 + point_2;
	sum = point_1.operator+(point_2);	//this is the same 
	std::cout << sum << "\n";

	sum = point_1 - point_2;		//and this too
	std::cout << sum << "\n";

	return 0;
}

twoPoint::twoPoint (int x, int y) : one (x), two (y) { howExists++; }	//initialization list

void twoPoint::getHowExists () {
	std::cout << "Now exists " << howExists << " twoPiont.\n";
}

void twoPoint::operator+(const twoPoint& point) {
	this->one = this->one + point.one;
	this->two = this->two + point.two;
}

bool twoPoint::operator<(int value)
{
	if (one < value || two < value)
		return false;
	else
		return true;
}

double Squere::field () {
	return side * side;
}

void Squere::getSide () const {
	std::cout << "Side is " << side << ".\n";
}

void Squere::setSide (int x) {
	side = x;
}

Squere * Squere::operator+(int)
{
	return new Squere (99);
}

bool sameSide (twoPoint & point, Squere & squere)
{
	int temp = point.getTwo () - point.getOne ();
	return temp == squere.getSideValue () ? true : false;
}

void printFields (std::vector<Shape*> const shapes) {
	for (auto elements : shapes) {
		std::cout << elements->field () << "\n";
	}
}

void Up::getMidMethod () {
	Mid mid;
	mid.methodB ();
}

template<class T>
void IsAChar<T>::getN () {
	std::cout << n << "\n";
}

Point Point::operator+(Point first) {
	return Point (x + first.x, y + first.y);
}

Point operator-(Point first, Point second) {
	return Point (first.x - second.x, first.y - second.y);
}

std::ostream & operator<<(std::ostream & stream, Point & point) {
	std::cout << point.name << " " << point.x << " " << point.y << "\n";
	return stream;
}