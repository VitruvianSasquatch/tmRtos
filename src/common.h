#ifndef COMMON_H
#define COMMON_H


#include <stdint.h> //Int types
#include <limits.h> //Int constants
#include <stdbool.h> //Duh
#include <stdlib.h> //NULL etc
#include <string.h> //memcpy etc


#define IDIV(n, d) ((n) + (d)/2 + 1) / (d) /*Minimises overflow, handles signed values*/
#define	UDIV(n, d) ((n)<<1 + (d)) / ((d)<<1) /*Minimises error, only suitable for positives*/

typedef unsigned int uint; //Native databus size



#endif //COMMON_H