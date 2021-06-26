#include <stdio.h>
#include <ctype.h>

static char randbit(FILE *urandom) {
  static unsigned char r, R = 128;
  if (R == 128) {
    r = fgetc(urandom);
    R = 1;
  } else {
    R <<= 1;
  }
  return !(r&R);
}
int main(void)
{
  FILE *urandom = fopen("/dev/urandom", "r");
  int c;
  while ((c=getchar()) != EOF) {
    if (randbit(urandom))
      putchar(toupper(c));
    else
      putchar(tolower(c));
  }
  fclose(urandom);
}
