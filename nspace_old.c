#include <stdio.h>
#include <errno.h>

#define MAXBUF 1024
#define BASE 10


int main (int argc, char ** argv) {
  long long int number, a, b, c, d;
  long int num=0;
  char buffer[MAXBUF+1];
  char *p, *q;

  while (fgets(buffer, MAXBUF, stdin) != NULL) {
    p = buffer; q = NULL;
    while (p != q) {
      number = strtoll(p, &q, BASE);
      if (p != q) {
        /* printf ("%lld\n", number); */
	p = q; q = NULL;
        
        /* number contains parsed value */
        a=b; b=c; c=d; d=number;
        /*printf ("a=%lld b=%lld c=%lld d=%lld\n", a, b, c, d);*/
	if (++num>=4) printf ("%lld %lld %lld\n", b-a, c-b, d-c);
      }
    }
  }

  return 0;
}

