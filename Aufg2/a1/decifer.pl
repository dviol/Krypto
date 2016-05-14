open my $fh, '<', 'cipher1.txt' or die "Can't open file $!";
open my $pi,'<','pi.txt' or die "Can't open file $!";
open my $deb,'>','debug.txt' or die "Could not open file $!";

my $pi = do { local $/; <$pi> };
my $file_content = do { local $/; <$fh> };
my $M = 26;
my $m;
my $mMult = 0;
my @alphabet = (A...Z);

=pod
WENN SIE KEIN BROT MEHR HABEN SOLLEN SIE DOCH KUCHEN ESSEN 
MARIE ANTOINETTE WIRD FAELSCHLICHERWEISE NACHGESAGT SIE HAETTE DAMIT GEANTWORTET ALS IHR BERICHTET
WURDE DIE ARMEN DER BEVOELKERUNG HAETTEN KEIN BROT ZU ESSEN TATSAECHLICH STAMMT
DIESER SATZ AUS DEN CONFESSIONS VON JEAN JACQUES ROUSSEAU UND WURDE VEROEFFENTLICHT
ALSO EINIGE JAHRE VOR DER FRANZOESISCHEN REVOLUTION DER BEGRIFF BRIOCHE BEZEICHNETE
ZUDEM DAMALS EINE VARIANTE DES WEISSBROTS UND NICHT KUCHEN
=cut

@arr = unpack("W*",$pi);
foreach(@arr){
	
	$_ = chr($_);
}

$countAll = $file_content =~ tr/A-Z/A-Z/;
$index = 0;
foreach(@alphabet){

$count = $file_content =~ s/$_/$index/g;
#print "Count of $_ is $count und wird verwandelt in $index\n";
$index++;	
}
@encodedLetters = split(" ",$file_content);
@decryptet = ();


#Decryptet with offset = 76
for($i = 0; $i<100;$i++){
	#print "I'm $i\n";
	my $start = $i+1;
	@e_copy = @encodedLetters;
	for($j = 0; $j<scalar(@encodedLetters);$j++){
		my $combinedNum = $arr[$start++].$arr[$start++];
		
		
		if($combinedNum % 26 == 0){
		
		$e_copy[$j] = $alphabet[$e_copy[$j]];
		
		
		
		}
		
		
		push @decryptet , find($combinedNum,$encodedLetters[$j]);
		
	
		

}
foreach(@decryptet){
		
		if($_>25){
		print "something went wrong/n";
		}	
		
		$_ = $alphabet[$_];
}
print $deb $i." ";
print $deb @decryptet;
print $deb "\n-------------------\n";
undef @decryptet;

	
}


sub find{
	$combined = $_[0];
	$encLett = $_[1];
	
	for($k=0; $K <26; $k++){
		$sum = $k+$combined;
		$mod = $sum % 26;
		#print $deb "Testet number is $k\n";
	
	
		if($mod == $encLett){
		#print $deb "Worked!\n";	
		return $k;
		}
	
		
	}	 
	return -1;

}	
		


