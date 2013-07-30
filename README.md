# nspace

A collection of scripts for phase space plotting.

## Usage

```
gcc nspace.c -o nspace
dd if=/bin/sh bs=1024 skip=40 | ./plotnz.sh | head -n 20000 >output.dat
gnuplot
gnuplot> set term x11
gnuplot> splot "output.dat" w dot
```

## Remarks

* dd is used in the example to skip the first 40k of the file.
* plotnz.sh will skip zero blocks in the file, plot.sh (script not quite up to date) won't.
* The scripts are tailored to a Unix-style environment. Use Linux, Mac OS X, or Cygwin.
* On OS X, gnuplot's x11 output outperforms the default aqua setting by an order of magnitude.
* The example limits output to 20k dots. A plot tends to overcrowd beyond the 50k mark, and gnuplot/x11 output gets sluggish beyond 100k.
