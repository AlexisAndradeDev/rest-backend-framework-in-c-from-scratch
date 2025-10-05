/* webdev.h */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdbool.h>

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;

#define $c (char *)
#define $8 (int8 *)
#define $16 (int16)
#define $32 (int32)
#define $64 (int64)
#define $i (int)

/*
// Example of how to use the macros and types
// Macros are used for type casting
int8 *p = $8 "./myfile.txt";
int16 x = $16 open($c p, O_RDONLY);

if (x > 0) {}
else {

}
*/

int32 setup_server(int8 *ip_address, int16 port);
int main(int argc, char **argv);
