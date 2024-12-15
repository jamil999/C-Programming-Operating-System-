#include <stdio.h>
int main() {
  char password[16];
  int lower = 0, upper = 0, digit = 0, special = 0;
  fgets(password, 16, stdin);
  for (int i = 0; i < 16; i++) {
    if (password[i] >= 'a' && password[i] <= 'z') {
      lower = 1;
    } else if (password[i] >= 'A' && password[i] <= 'Z') {
      upper = 1;
    } else if (password[i] >= '0' && password[i] <= '9') {
      digit = 1;
    } else if (password[i] == '_' || password[i] == '$' || password[i] == '#' ||
               password[i] == '@') {
      special = 1;
    }
  }

  if (lower == 1 && upper == 1 && digit == 1 && special == 1) {
    printf("OK");
  } else {
    if (lower == 0) {
      printf("Lowercase chracter Missing, ");
    }
    if (upper == 0) {
      printf("Upppercase chracter Missing, ");
    }
    if (digit == 0) {
      printf("Digit Missing, ");
    }
    if (special == 0) {
      printf("Special character Missing, ");
    }
  }

  return 0;
}