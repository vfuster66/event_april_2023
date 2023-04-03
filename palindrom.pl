#!/usr/bin/perl

print "Enter a string: ";
my $input = <STDIN>;
chomp $input;

if ($input eq reverse $input) {
    print "The input is a palindrome\n";
} else {
    print "The input is not a palindrome\n";
}

