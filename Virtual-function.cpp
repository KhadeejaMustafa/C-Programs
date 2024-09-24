/*
# This program demonstrates the use of virtual functions.
# What is a virtual function? A virtual function is a member function that is declared within a base class and is re-defined (overridden) by a derived class.
# When you refer to a derived class object using a pointer or a reference to the base class,
you can call a virtual function for that object and execute the derived class’s version of the method.

# This program will display information about three people. Common attributes like ID, Name, Date of Birth will be defined in the Virtual function.
# whereas, when defining class for each person, we will add separate attributes that will be added with the virtual function.
*/


#include<iostream>

using namespace std;

class Person {

		int id;
		string name;
		int DoB;

	public:

		Person(int i, string n, int d) {

			id = i;
			name = n;
			DoB = d;

		}

		virtual int getId() {
			return id;
		}


		virtual string getName() {
			return name;
		}

		virtual int getDateOfBirth() {
			return DoB;
		}

		virtual void display() = 0;
};



class Author: public Person {
		string Book;

	public:
		Author(int i, string n, int d, string b): Person(i, n, d) {
			Book = b;
		}
		void display() {
			cout << "\n--- about the Author ---";
			cout<< "\n\n ID: " << getId();
			cout<< "\n\n Name: " << getName();
			cout<< "\n\n Date of birth: " << getDateOfBirth();
			cout<< "\n\n Book written: " << Book << "\n";
		}
};


class Actor: public Person {
		string Movie;

	public:

		Actor(int i, string n, int d, string m): Person(i, n, d) {
			Movie = m;
		}

		void display() {
			cout << "\n--- about the Actor ---";
			cout<< "\n\n ID: " << getId();
			cout<< "\n\n Name: " << getName();
			cout<< "\n\n Date of birth: " << getDateOfBirth();
			cout<< "\n\n Movie filmed: " << Movie << "\n";
		}
};

class Programmer: public Person {
		string Project;

	public:

		Programmer(int i, string n, int d, string p): Person(i, n, d) {
			Project = p;
		}

		void display() {
			cout << "\n--- about the Software Programmer ---";
			cout<< "\n\n ID: " << getId();
			cout<< "\n\n Name: " << getName();
			cout<< "\n\n Date of birth: " << getDateOfBirth();
			cout<< "\n\n Project made: " << Project<< "\n";
		}
};


main() {
	Person *p[2];
	p[0] = new Author(1, "Antoine", 1900, "The little prince");
	p[1] = new Actor(2, "Tom", 2000, "The star");
	p[2] = new Programmer(3, "Sam", 2002, "Social Media application");

	p[0] -> display();
	p[1] -> display();
	p[2] -> display();

}
