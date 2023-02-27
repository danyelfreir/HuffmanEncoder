Students: Daníel Freyr Grétarsson & Marín Guðmundsdóttir Jacobsen

We managed to implement a real life compression tool for text files. Unfortunately it does not play well with binary files, it does not play well with negative numbers and it sometime causes some undefined behavior and we simply could not figure out what was causing it.

We did run the compressor on a ~63mb text file and it it compressed it down to about 41mb and it did so in 18 seconds on an Intel Macbook Pro.
It also decompressed it to it's original size on the same computer in 4 seconds.

To compile it simply type `make` and an executable named `compressor` will compile.
Then you can run for example `./compressor -c data/mega.txt mega.cmp`,
and to decompress run `./compressor -d mega.cmp lorem.txt`
