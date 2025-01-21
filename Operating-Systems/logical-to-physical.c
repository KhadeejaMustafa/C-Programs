// In this program we shall be translating a logical address into a physical address
#include <stdlib.h>
#include <stdio.h>

int main(){
// we shall declare the required variables
  int segment, offset, logicalAddress, physicalAddress;

  printf("16-bit Logical to 20-bit Physical address converter\n");

  printf("\nPlease enter the segment value: (16-bit)");
  scanf("%x", &segment);

  printf("\nPlease enter offset value: (16-bit)");
  scanf("%x", &offset);

  segment = segment*16;
  physicalAddress = (segment + offset);
  printf("\nThe 20-bit Physical address is: %x", &physicalAddress);


  system("pause");
}// end of main
