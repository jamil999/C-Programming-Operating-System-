#include <stdio.h>
int main() {
  char domain[20];
  fgets(domain, 20, stdin);
  for (int i; i < 20; i++) {
    if (domain[i] == '@') {
      if (domain[i + 1] == 'k') {
        printf("Email address is outdated");
      } else {
        printf("Email address is ok");
      }
    }
  }

  return 0;
}