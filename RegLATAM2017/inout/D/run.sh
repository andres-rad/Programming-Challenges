
#!/bin/bash
# Counting the number of lines in a list of files
# for loop over arguments



echo "$0 counts the lines of code" 

for f in `seq 66`
do
	../../d < input/D_$f > out/D_$f
	echo "$f"
	diff out/D_$f output/D_$f 
done

