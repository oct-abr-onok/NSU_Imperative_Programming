gcc -c ./zlib/*.c ./zlib/minizip/unzip.c ./zlib/minizip/ioapi.c -D USE_CRYPT
ar rcs zlib.a *.o 
gcc test.c zlib.a -o checked_solution -I ./zlib/minizip