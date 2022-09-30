
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Box {
private: // Access Specifier
	// Data Members
	int l, b, h; // Length, Breadth, Height

public:
	// Member Functions
	int getLength();  // Return box's length
	int getBreadth(); //Return box's breadth
	int getHeight();  // Return box's height
	long long CalculateVolume(); // Return the volume of the box

	// Constructors: 
	Box();
	Box(int, int, int);
	Box(Box &);

	// Operator Overloading
	bool operator< (Box& B);
	friend ostream& operator<< (ostream& outputLine, Box& B); // how did the 'friend' work?

};


Box::Box() {
	l = 0;
	b = 0;
	h = 0;
}
Box::Box(int length, int breadth, int height) {
	l = length;
	b = breadth;
	h = height;
	//length = l;
	//breadth = b;
	//height = h;
}
Box::Box(Box &B) {
	l = B.l;
	b = B.b;
	h = B.h;
}

bool Box::operator< (Box& B) {
	
	if (l < B.l) {
		return true;
	}
	else if ( (b < B.b) && (l == B.l) ) {
		return true;
	}
	else if ((h < B.h) && (b == B.b) && (l == B.l)) {
		return true;
	}
	else {
		return false;
	}
}

ostream& operator<< (ostream& outputLine, Box& B) {
	outputLine << B.l << ' ' << B.b << ' ' << B.h;
	return outputLine;
}

int Box::getLength() {
	//cout << "Hello" << endl;
	return l;
}  
int Box::getBreadth() {
	//cout << "Hello" << endl;
	return b;
}
int Box::getHeight() {
	//cout << "Hello" << endl;
	return h;
}
long long Box::CalculateVolume() {
	//cout << "Hello" << endl;
	//cout << "length breadth & height is " << l << b << h;
	long long vol = static_cast<long>(l) * static_cast<long>(b) * static_cast<long>(h);
	cout << "vol is: " << (long long) vol;
	return (long long) vol;
}


//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2() {
	
	cout << "Enter Number of Queries\n";
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++) {

		cout << "Enter Type of Query\n";
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cout << "Enter Length, Breadth, Height\n";
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cout << "Enter Length, Breadth, Height\n";
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << "Calculating Volume\n";
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			cout << "Copying Object content\n";
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}