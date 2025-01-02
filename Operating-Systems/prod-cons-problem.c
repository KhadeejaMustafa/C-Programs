// This program is based on producer-consumer problem, where the producer produces information that is then consumed by the consumer.
// Buffer is where all the production and consumption will take place.
// The program will give three choice to the user, to either produce a value, consume a value, or quit the program.


#include<stdio.h>

int main() {
	int in = 0;
	int out = 0;
	int produce = 0;
	int consume = 0;
	int counter = 0;
	int buffersize;


	printf("Please enter size of the buffer: ");
	scanf("%d", &buffersize);

	int buffr[buffersize];
	char choice;

	printf("Enter p to produce an item in the buffer.\n");
	printf("Enter c to consume an item from the buffer.\n");
	printf("Enter q to quit the program.\n");

	do {
		scanf("%c", &choice);
		switch(choice) {
			case 'p':
				if(counter == buffersize)
					printf("The buffer is full.\n");
				else {

					printf("Enter the value to produce: ");
					scanf("%d", &produce);
					buffr[in] = produce;
					in = (in + 1)%buffersize;
					counter++;
				}
				break;

			case 'c':
				if(counter == 0){
				printf("The buffer is empty.\n");}
				
				else {
					consume = buffr[out];
					printf("The consumed value is %d\n", &consume);
					out = (out+1)%buffersize;
					counter--;
				}
				break;

		} // end of switch
	} // end of do

	while(choice != 'q'); // end of while
} // end of main function
