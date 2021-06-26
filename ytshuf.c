#include <stdio.h>

// streaming shuffle with max deck size SHUFCAP and max line length MAXLEN

#define MAXLEN 32
#define SHUFCAP 4

static FILE *urandom;
static unsigned int rand() {
  if (SHUFCAP > 256)
    return (fgetc(urandom)<<8 | fgetc(urandom)) % SHUFCAP;
  else
    return fgetc(urandom) % SHUFCAP;
}
int main() {
  urandom = fopen("/dev/urandom", "r");
  char strings[SHUFCAP][MAXLEN] = { 0 };
  unsigned int r = rand(), R = 0;
  int c;
  while ((c = getchar()) != EOF) {
    if (c != '\n') {
      strings[r][R++] = c;
    } else {
      strings[r][R] = '\0';
      r = rand();
      R = 0;
      if (*strings[r]) {
        puts (strings[r]);
        strings[r][R] = '\0';
      }
    }
  }
  for (int i=0; i<SHUFCAP; ++i)
    if (*strings[i])
      puts(strings[i]);
  fclose(urandom);
  return 0;
}
