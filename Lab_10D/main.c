#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
	FILE *file = fopen("graf1.txt", "r");
	double t, vMin = 0, vMax = 0, iMin = 0, iMax = 0;
	char s[400];
	for (int i = 0; i <= 400; i++){
		fscanf(file, "%s", s);
		t = atof(s);
		if (t > vMax){
			vMax = t;
			iMax = i;
		}
		if (t < vMin){
			vMin = t;
			iMin = i;
		}
	}
	printf("Max value = %.4f\nMaxV index = %.1f\nMin value = %.4f\nMinV index = %.1f\n", vMax, iMax, vMin, iMin);
	return 0;
}