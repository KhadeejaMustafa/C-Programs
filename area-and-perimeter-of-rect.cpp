#include <iostream>
#define perimeter(x, y) x+x+y+y
#define areaOfRect(x,y) x*y
using namespace std;
int main()
{
	
	int x, y;
	cout << "\n-- CALCULATING PERIMETER AND AREA OF A RECTANGLE --";
	cout << "\n\n Enter height of Rectangle: ";
    cin >> x;
    cout << "\n Enter width of Rectangle: ";
    cin >> y;

    cout << "\n--------------------------------\n PERIMETR OF RECTANGLE = " << perimeter(x, y);
   
    cout << "\n AREA OF RECTANGLE = " << areaOfRect(x,y);


}