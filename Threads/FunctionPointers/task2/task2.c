#include <stdio.h>
#include <stdlib.h>

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);


int main (void)
{
	/* IMPLEMENT ME: Insert your algorithm here */

	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { 
  printf ("Adding 'a' and 'b'\n"); 
  return a + b; 
}

int subtract (int a, int b) { 
  printf ("Subtracting 'b' from 'a'\n"); 
  return a - b; 
}

int multiply (int a, int b) { 
  printf ("Multiplying 'a' and 'b'\n"); 
  return a * b; 
}

int divide (int a, int b) { 
  printf ("Dividing 'a' by 'b'\n"); 
  return a / b; 
}
