====================================
=README-LABASS3 - STRING DICTIONARY=
====================================

1. Compiling

To compile the application, simply
run "make" from the program's
working directory in a terminal.
Program will compile with no issues.

If you wish to remove any additional
unnecessary files, type "make clean"
to remove the executable and any
.o files generated with the build
process.

2. Running

Simply type "./main < testfile.txt"
in a terminal to run the application.
The application will scan the text file
for words that it can pick out, then
display them to you, as well as how
often they occur in the file. Words
are sorted alphabetically, it is case
sensitive (That is, "Can" and "can"
will be detected as seperate words)
and will print them, capitals first.

Try editing the testfile.txt with
different words and see how many
times it can pick up your different
words!

In addition, the application supports
a maximum amount of 100 words, although
this can be changed by editing line 12
of includes.h to change the value of MAX.

3. Credit
- Franco Carlacci
	Initial program code

Written by Jordan Karpan (5041823)