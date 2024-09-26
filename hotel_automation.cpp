/*this program will implement the concept of inheritance as well as aggregation relationship. we have a class called 'Student' for a general
education institution. some students live in hostels and some do not. while those that are hostelized, need to be registered with the Hostel.
for that we have a class called 'Hostel'.
1. We will make an inheritance relationship between class 'Student' and 'hosterlized-student'.
2. We will make an aggregate relationship between class 'Hostel' and 'hosterlized-student'.


*/
#include<iostream>

using namespace std;

//student class
class Student {
	protected:
		string name;
		int rollnumber;
	public:
		void Set_name(string n) {
			name = n;
		}

		void Set_rollnumber(int rollnum) {
			rollnumber = rollnum;
		}
};

//hostel class
class Hostel {
	private:
		string name;
	public:
		Hostel() {}
		Hostel(string name) {
			this->name = name;
		}

		string get_name() {
			return name;
		}
};
// Hostalized student class
class Hostalized_student: public Student {
	private:
		int Room_number;
		int room_rent;
		bool rent_status;
		Hostel H; // as hostel class has aggregate relation with this class.

	public:

		Hostalized_student(int rn, int rr, bool rs) {
			Room_number = rn;
			room_rent = rr;
			rent_status = rs;
			H = Hostel("Seashine Hostel");
		}
		void display() {

			cout << "Student Name: " << name;
			cout << "\nRoll Number: " << rollnumber;
			cout << "\nHotel Name: " << H.get_name();
			cout << "\nRoom Number: " << Room_number;
			cout << "\nRoom Rent: " << room_rent;
			cout << "\nRent Status: ";
			Pay_rent();


		}

		void Pay_rent() {
			if(rent_status == 1) {
				cout << "Rent of the current month paid.";

			} else {

				cout << "Rent of the current month not paid yet.";
				cout << "\nStudent is requested to complete his/her dues.";


			}


		}
};




main() {
	
	cout << " --- Hostel Students Information ---\n\n";
	Hostalized_student Stdent1(1001, 2000, true);
	Stdent1.Set_rollnumber(43);
	Stdent1.Set_name("Sam");
	Stdent1.display();

	cout << "\n\n";

	Hostalized_student Stdent2(1002, 2200, false);
	Stdent2.Set_rollnumber(22);
	Stdent2.Set_name("Mark");
	Stdent2.display();
	return 0;

}