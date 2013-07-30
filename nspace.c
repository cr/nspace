/* Phase space plot
 * Copyright (C) Christiane Ruetten
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 2 as
 * published by the Free Software Foundation at:
 * www.gnu.org/licenses/gpl-2.0.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXBUF 10240
#define MAXN 30

void insert (long long * seq, long long value, int dim) {
  int i;
  for (i=dim ; i>0 ; i--)
    seq[i] = seq[i-1];
  seq[0] = value;
}

void diffprint (long long * seq, int dim, long long wrap) {
  int i;
  long long diff;
  for (i=dim; i>0; i--) {
    diff = seq[i-1]-seq[i];
    if (diff<0) { diff += wrap ; }
    if (i>1) {
      printf ("%lld ", diff);
    } else {
      printf ("%lld\n", diff);
    }
  }
}

int main (int argc, char ** argv) {
  long long int number, a, b, c, d;
  long int num=0;
  int dim=3, base=10;
  long long wrap=0;
  char buffer[MAXBUF+1];
  char *p, *q;
  long long sequence[MAXN+1];

  while ((c = getopt (argc, argv, "b:d:w:")) != -1) {
    switch (c) {
      case 'b':
	base = atoi(optarg);
	break;
      case 'd':
	dim = atoi(optarg);
	break;
      case 'w':
	wrap = atoi(optarg);
	break;
      default:
        printf ("usage: nspace [-d num_dimensions] [-b conversion_base] [-w wrap_around_base]\n");
	exit (1);
    }
  }

  while (fgets(buffer, MAXBUF, stdin) != NULL) {
    p = buffer; q = NULL;
    while (p != q) {
      number = strtoll(p, &q, base);
      if (p != q) {
        /* printf ("%lld\n", number); */
	p = q; q = NULL;
        
        /* number contains parsed value */
        insert (sequence, number, dim);
	if (++num>dim) diffprint (sequence, dim, wrap);
      }
    }
  }

  return 0;
}

