#include <stdio.h>

void sorting(int array1[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array1[j] < array1[j + 1]) {
                int var1 = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = var1;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int array1[argc - 1];
    for (int i = 1; i < argc; i++) {
        array1[i - 1] = atoi(argv[i]);
    }
    int n;
    n = argc - 1;
    sorting(array1, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", array1[i]);
    } 
    return 0;
}
