#include<stdio.h>
#include<stdlib.h>

int main(){

	printf("This will print the length of Bytes of Variable for Local System.\n");
	printf("The System Arch is %s.\n",system("Ver"));
	printf("The length of \"int\": %d\n",sizeof(int));
	printf("The length of \"long\": %d\n",sizeof(long));
	printf("The length of \"longlong\": %d\n",sizeof(long long));
	printf("The length of \"short\": %d\n",sizeof(short));
	printf("The length of \"char\": %d\n",sizeof(char));
	printf("The length of \"float\": %d\n",sizeof(float));
	printf("The length of \"double\": %d\n",sizeof(double));
	return 0;
}

