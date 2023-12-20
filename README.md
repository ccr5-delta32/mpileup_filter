```procpile``` filters the output stream of mpileup down to only the read depths.

```
g++ -std=c++11 -O3 procpile.cpp procpile.main.cpp -o procpile
```

example:
```
samtools mpileup -aa -B -d 3000 -r Chr1 -b ./bamlist -f /path/to/reference.fa | ./procpile | gzip > read-depth.gz
```

Here *bamlist* is a file with the paths to all the .bam files that should be
included, in the same path the .bam index files should be present (.bam.bai)

The result is a table with read depths like this, where from column 4 onward the read depths for the bams in the bamlist appear in the respective order.

```
Chr1  3317906 A 49  17  13  
Chr1  3317907 T 51  18  14  
Chr1  3317908 T 49  18  13  
```
