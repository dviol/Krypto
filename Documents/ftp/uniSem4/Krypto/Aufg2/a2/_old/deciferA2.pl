open my $cipher, "<", "c2.txt" or die "Couldn't open File $!\n";
open my $debug, ">", "debug.txt" or die "Couldn't open FIle $!\n";
my $m = 26;
my $lDe = ord("A");
my @alph = (A...Z);
@cT = ();

while(!eof($cipher)){
	
	push @cT, <$cipher> or die "Readline Failed! $!\n";
	
}


@t1 = unpack("W*",$cT[0]);
@t2 = unpack("W*",$cT[1]);
@t3 = unpack("W*",$cT[2]);

for(my $i= 0; $i < scalar(@t1);$i++){
	$t1[$i] = $t1[$i] - $lDe;
	$t2[$i] = $t2[$i] - $lDe;
	$t3[$i] = $t3[$i] - $lDe;
	}


for(my $
