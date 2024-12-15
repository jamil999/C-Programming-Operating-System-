#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        int value = atoi(argv[i]);
        
        if (value % 2 == 0) {
            printf("%d is even\n", value);
        } else {
            printf("%d is odd\n", value);
        }
    }
    
    return 0;
}
