In order to run our Huffman code:
$ gcc huffman.c -o huffman
$ ./huffman 
OR $ ./huffman text.txt 
Where text.txt is a file you want to encode and decode
Running our program will create 2 files: encodedOutput.txt and decodedOutput.txt 
These are the encoded and decoded files respectively.
Our LUT is based on book.txt. This does not contain all possibly characters so some characters will not be encoded. This LUT does contain all alphaetical letters and numbers so feel free to test with those or our given file: book.txt.