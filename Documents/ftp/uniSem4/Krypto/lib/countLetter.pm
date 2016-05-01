use Exporter qw(import);


our @EXPORT_OK = qw(countLetters);

#Counting
sub countLetters{
	die "Too many arguments for subroutine" unless @_ <= 2;
	die "Too few arguments for subroutine" unless @_ >= 2;
	
	my $charToCount = $_[0];
	my $stringToCount = $_[1];
	
	my $count = eval("$stringToCount =~ tr/$charToCount//") or die $@;
		
	return $count;
	
}
1;


