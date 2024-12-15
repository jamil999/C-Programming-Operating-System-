#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *opening;
	char txtfile[50];
	strcpy(txtfile, argv[1]);
	
	opening = fopen(txtfile,"w");
	
	char store[100];
	int x = 1;
	while (x) {
        printf("Enter a string: ");
        scanf("%s", store);
        if (strcmp(store, "-1") == 0) {
            fclose(opening);
            x = 0;
        } 
        else {
            fprintf(opening, "%s\n", store);
        }
        }


    return 0;
}
