#include <stdio.h>

int main() {
  FILE *File1, *File2;
  char buffer[100];
  int space = 0;

  File1 = fopen("input.txt", "r");
  File2 = fopen("output.txt", "w");

  while (fgets(buffer, 100, File1) != NULL) {
    for (int i = 0; buffer[i] != '\0'; i++) {
      if (buffer[i] == ' ') {
        if (!space) {
          fputc(' ', File2);
          space = 1;
        }
      } else {
        fputc(buffer[i], File2);
        space = 0;
      }
    }
  }

  fclose(File1);
  fclose(File2);

  printf("success.\n");

  return 0;
}
