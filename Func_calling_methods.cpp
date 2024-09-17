/*In this program, we'll try the different methods by which we can call functions.

1. Call by Value.
2. Call by Reference.
3. Call by Pointers.

first, we'll define a structure that contains a string of 1000 characters. 
then we'll use the three methods of function calling to manipulate that string.
we'll declare and define a function for each calling method.
*/

#include<iostream>

using namespace std;
//defining a structure named "Quote".

struct Quote{
	char text[1000];
}

Qt1 = {"A warm smile is the universal language of kindness."};


//declaring three functions, that contain the structure as their parameter.

void valFunc(Quote v1);  // call by value
void refFunc(const Quote &r1); // call by reference
void ptrFunc(const Quote *p1); // call by pointer


//function definitions

void valFunc(Quote v1){
	cout << "call by value:" << endl;
	cout << v1.text << endl;
}


void refFunc(const Quote &r1){
	cout << "call by reference:" << endl;
	cout << r1.text << endl;
}


void ptrFunc(const Quote *p1){
	cout << "call by pointer:" << endl;
	cout << p1->text;
}


//main function
main(){
	
	valFunc(Qt1);
	refFunc(Qt1);
	ptrFunc(&Qt1);
}
