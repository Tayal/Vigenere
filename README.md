# Vigenere
A simple Vigenere en/de-ciphering script

-Move the encipher and decipher files to /usr/bin.

-Now type the commands in terminal
`*To encipher - 'encipher *filename*'
  *To decipher - 'decipher *filename*'

for file in x/*;
do t=$(basename $file .md);
encipher $file $t;
done
