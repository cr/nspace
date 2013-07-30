#!/usr/bin/perl

use strict;

while (<>) {
	
	chomp;

	my $sum = 0;
	my $cnt = 0;

	foreach my $w ( split /  */ ) {
		
		$sum += $w*$w;
		$cnt++;

	}

	$sum = int sqrt( $sum );
	print "$sum\n"; 


}
