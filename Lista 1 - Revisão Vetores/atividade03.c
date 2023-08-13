#include <stdio.h>

int main() {
 
  int i, v1[] = {15, 8, 42, 19, -30};
  int arrayHigherNumber = v1[0], arraySmallestNumber = v1[0];
  
	for( i=0; i<(sizeof(v1) / sizeof(int )); i++) {
	 	if(arrayHigherNumber < v1[i] ){
	 		arrayHigherNumber = v1[i];	 
		}
		if(arraySmallestNumber > v1[i] ){
	 		arraySmallestNumber = v1[i];
		}
   }
   
    printf("\nO maior numero do array e: %i\nO menor numero do array e: %i", arryHigherNumber , arrySmallestNumber);
    return 0;
}
