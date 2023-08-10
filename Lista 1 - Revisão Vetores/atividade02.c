#include <stdio.h>

int main() {
 
  int i,sizeOfArry, arryElementsSum, v1[] = {10, 20, 30, 40, 50};
  
  sizeOfArry = sizeof(v1) / sizeof(int);
 
	for(int i=0; i<sizeof(v1) / sizeof(int ); i++) {
	 	arryElementsSum += v1[i];
   }
    printf("A media dos elementos do arry e: %d", arryElementsSum / sizeOfArry);
    return 0;
}