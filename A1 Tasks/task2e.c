#include <stdio.h>

char toLower(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + ('a' - 'A');
  }
  return c;
}

int strlenth(const char *str) {
  const char *p;
  for (p = str; *p; ++p) {
  }
  return (p - str - 1);
}

const char *isPalindrome(const char *str) {
  int lenth = strlenth(str);
  int start = 0, end = lenth - 1;

  while (start < end) {
    if (toLower(str[start]) != toLower(str[end])) {
      return "Not Palindrome";
    }
    start++;
    end--;
  }
  return "Palindrome";
}

int main() {
  char str[100];
  int i;
  fgets(str, 100, stdin);

  printf("%s\n", isPalindrome(str));

  return 0;
}
