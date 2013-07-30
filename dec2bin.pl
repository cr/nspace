#!/usr/bin/perl

use strict;

while (<>) {
	
	chomp;

	foreach my $w ( split /  */ ) {
		
		print pack "c1", $w;

	}


}
