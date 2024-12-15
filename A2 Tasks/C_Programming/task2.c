#include <stdio.h>

int PerfectNumber_calculation(int the_num);
int main() {
    int first, last;

    scanf("%d", &first);
    scanf("%d", &last);

    while(first <= last) {
        if (PerfectNumber_calculation(first) == 0){
            printf("%d\n",first);
        }
        first++;
    }
    return 0;
}

int PerfectNumber_calculation(int the_num) {
    int total = 0;
    
    for (int i = 1; i < the_num; i++) {
        if (the_num % i == 0) {
            total += i;
        }
    }

    if (total == the_num) {
        return 0;
    } else {
        return -1;
    }
}