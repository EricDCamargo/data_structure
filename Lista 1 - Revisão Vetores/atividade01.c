#include <stdio.h>
 
int main() {
 
  int i, v1[] = {10,10,10}, v2[]= {3,2,1}, v3[3];

	for(i=0; i<3; i++){
		v3[i] = v1[i] + v2[i];
		
		printf("%i\n", v3[i]);
	}
    return 0;
}