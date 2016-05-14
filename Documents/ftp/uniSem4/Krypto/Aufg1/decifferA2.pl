open my $fh, '<', 'chiffrat2.txt' or die "Can't open file $!";
my $file_content = do { local $/; <$fh> };
my @count;
my %alphabetRef = ();

$countAll = $file_content =~ tr/A-Z/A-Z/;


foreach(A...Z){

		
	$count = $file_content =~ s/$_/$_/g;
	$alphabetRef{$_} = $count/$countAll;
	
}

foreach my $letter (sort {$alphabetRef{$b} <=> $alphabetRef{$a} or $a cmp $b} keys %alphabetRef){
	
	print "Anzahl von $letter = $alphabetRef{$letter}\n";
	
}


#my $count = &countLetters("a",$a);

#print $count."\n"
