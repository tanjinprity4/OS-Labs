#include <stdio.h>
#include <stdlib.h>

typedef int (*Operation) (int a, int b);

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);


int main (void)
{
  // Array of functions of type
	Operation operations[4];
	char operation[10];
  int operation_n;
	
	operations[0] = &add;
	operations[1] = &subtract;
	operations[2] = &multiply;
	operations[3] = &divide;
  
  int a = 6;
  int b = 3;
  int result;
  
  while(1){
		printf("Operand 'a' : %d | Operand 'b' : %d Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3: divide | 4 : exit):", 
           a, b);
		scanf("%s", operation);
    operation_n = atoi(operation);
    while (operation_n > 4) {
      printf("Specify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3: divide | 4 : exit):");
      scanf("%s", operation); 
      operation_n = atoi(operation);
    }
		
		if (operation_n == 4){
			printf("Quit Program.\n");
			break;
		}
		
		// Depending on user input, performs the operation on intergers a and b and prints the result. 
		result = (*operations[operation_n])(a, b);
		printf("x = %d\n", result);
	}

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
