#include <stdio.h>

int main() {
 
  int i, arryHigherNumber , arrySmallestNumber, v1[] = {15, 8, 42, 19, -30};
  
  	printf("testetstetsd %i\n\n ", arrySmallestNumber);
	for( i=0; i<(sizeof(v1) / sizeof(int )); i++) {
	 	if(arryHigherNumber < v1[i] ){
	 		arryHigherNumber = v1[i];	 
		}
		if(arrySmallestNumber > v1[i] ){
	 		arrySmallestNumber = v1[i];
		}
		printf("%i ", v1[i]);
   }
   
    printf("\nO maior numero do arry e: %i\nO menor numero e: %i", arryHigherNumber , arrySmallestNumber);
    return 0;
}