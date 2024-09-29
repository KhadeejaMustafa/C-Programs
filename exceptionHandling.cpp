#include<iostream>

using namespace std;
//exception handling with single try
main(){
	
	/*
	try{
		int a, b;
		cout << "\nplease enter a's value: ";
		cin >> a;
	    cout << "\nplease enter b's value: ";
		cin >> b;
		
		if(b == 0){
			throw b;
		}
		
		else{
			cout << "\ndivision of a and b values is: " << a/b;
		}
	}
	
	
	catch(int problematicNum){
		
		cout << "\nwe have an error. the entered value that caused error is: " << problematicNum;
		
	} */
	cout << "\nThe program will ask the user to enter the value of a(nominator) and b(denominator), it will divide the two values and produce a result.";
	cout << "the program will throw an error in the following cases: \nIf the denominator is zero. \nif the denominator is less than 0. "; 
	
	//multiple catch handling
	try{
		int a, b;
		cout << "\nPlease enter value for a: ";
		cin >> a;
	    cout << "\nPlease enter value for b: ";
		cin >> b;
		
		if(b == 0 || b < 0){
			throw b;
		}
		
		else{
			cout << "\ndivision of " << a << " and " << b <<" gives " << a/b;
		}
	}
	
	
	catch(int b){
		cout << "\nError with entered values.";
		
	}
	
	
	catch(...){
		cout << "\nInvalid value entered in the denominator.";
		
	}
	
	

} 
