```
g++ -std=c++11 -O3 procpile.cpp procpile.main.cpp -o procpile
```

example:
```
samtools mpileup -aa -B -d 3000 -r Chr1 -b ./bamlist -f /path/to/reference.fa | ./procpile | gzip > read-depth.gz
```

Here *bamlist* is a file with the paths to all the .bam files that should be
included, in the same path the .bam index files should be present (.bam.bai)
