#!/usr/bin/perl

use strict;

binmode( STDIN );

while ( read( STDIN, my $buffer, 2 ) ) {

	my $x = unpack "s", $buffer;
	print "$x\n";

}
