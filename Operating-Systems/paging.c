/** The program shall calculate various paging parameters. 
1. Paging: a memory management scheme, with which physical address space is not required to be contiguous. 
2. paging parameters are p, d and f. 
3. we shall also calculate the physicall address size and the logical address size through these parameters. 
4. p is number of the page in the logical address space. Each logical address is divided into a page number and an offset within that page.
5. d is the offset within the page. It's used to locate the specific word or byte within the page.
6. f is the number of the frame in the physical memory where the page is currently stored. **/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(){
double pages, frames, memory, logicalAddress, physicalAddress, p, f, d;

printf("~ Paging Parameters Calculation program ~\n");

printf("\nEnter total memory: ");
scanf("%lf", &memory);

printf("Enter total number of pages: ");
scanf("%lf", &pages);


printf("\nEnter total number of physical frames: ");
scanf("%lf", &frames);
printf("\n\n");

// calculate p
p = log2(pages);
printf("Number of bits we need for p (Page number) are: %lf", ceil(p));
printf("\n\n");

// calculate f
f = log2(frames);
printf("Number of bits we need for f (Frame number) are: %lf", ceil(f));
printf("\n\n");

// calculate d
d = log2(memory);
printf("Number of bits we need for d (Offset) are: %lf", ceil(d));
printf("\n\n");

// calculate logical address size
logicalAddress = p + d;
printf("Logical Address size is %lf", logicalAddress);

// calculate physical address size
physicalAddress = f + d;
printf("\nPhysical Address size is %lf\n", physicalAddress);

system("pause");
} // end of main

// in shell: 
cd Desktop
gcc -o paging paging.c -lm
./paging
