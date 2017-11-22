
#!/bin/bash
# Counting the number of lines in a list of files
# for loop over arguments



echo "$0 counts the lines of code" 

for f in `seq 35`
do
	../../a < input/A_$f > out/A_$f
	echo "$f"
	diff out/A_$f output/A_$f 
done

