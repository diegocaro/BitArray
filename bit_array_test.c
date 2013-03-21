/*
 * commit 640451233b7958e5ae85572ea570a86a15934915
 * Author: Diego Caro <diegocaro@gmail.com>
 * Date:   Mon May 21 20:28:13 2012 -0400
 * https://github.com/diegocaro/BitArray/
 */

/*
 bit_array_test.c
 project: bit array C library
 url: https://github.com/noporpoise/BitArray/
 Adapted from: http://stackoverflow.com/a/2633584/431087
 author: Isaac Turner <turner.isaac@gmail.com>

 Copyright (c) 2011, Isaac Turner
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdlib.h>
#include <stdio.h>
#include "bit_array.h"

void test_resize(char *a, char *b, char *c) {
	int sa,sb,sc;
	char *d;
	
	sa = strlen(a);
	sb = strlen(b);
	sc = strlen(c);
	
	
	if (sc != (sa + sb)) {
		printf("Error, size doesnt match!!!\n");
		return;
	}
	
	d = malloc(sc+1);
	memcpy(d, a, sa);
	memcpy(&d[sa], b, sb);
	
	if (strcmp(c,d) != 0) {
		printf("Error, there are bad bits!!!\n");
	}
	free(d);
}

int main(int argc, char* argv[])
{
  printf("Oh hi!\n");
  printf("  Example operations on bit_array C library:\n");

  BIT_ARRAY* bitarr;
  char* str;
  
  // construct bit array
  bitarr = bit_array_create(100);
  
  int step = 0;

  str = bit_array_to_string(bitarr);
  printf("%i) Create bit array 100 bits long\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_set_bit(bitarr, 2);
  str = bit_array_to_string(bitarr);
  printf("%i) set bit 2\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_set_bit(bitarr, 5);
  str = bit_array_to_string(bitarr);
  printf("%i) set bit 5\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_set_bit(bitarr, 99);
  str = bit_array_to_string(bitarr);
  printf("%i) set bit 99\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_set_bit(bitarr, 0);
  str = bit_array_to_string(bitarr);
  printf("%i) set bit 0\n", step);
  printf("'%s'\n", str);
  free(str);
  
  /* Test clone */
  BIT_ARRAY* clone = bit_array_clone(bitarr);
  str = bit_array_to_string(clone);
  printf("%i.1) clone\n", step);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_clear_bit(clone, 0);
  str = bit_array_to_string(clone);
  printf("%i.2) clear bit 0\n", step);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_set_bit(clone, 21);
  str = bit_array_to_string(clone);
  printf("%i.3) set bit 21\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_free(clone);
  /* End of clone */
  
  bit_array_fill_zeros(bitarr);
  str = bit_array_to_string(bitarr);
  printf("%i) fill with zeros\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_fill_ones(bitarr);
  str = bit_array_to_string(bitarr);
  printf("%i) fill with ones\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_clear_bit(bitarr, 1);
  str = bit_array_to_string(bitarr);
  printf("%i) clear bit 1\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_clear_bit(bitarr, 98);
  str = bit_array_to_string(bitarr);
  printf("%i) clear bit 98\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_clear_bit(bitarr, 99);
  str = bit_array_to_string(bitarr);
  printf("%i) clear bit 99\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_resize(bitarr, 40);
  str = bit_array_to_string(bitarr);
  printf("%i) resize to 40 bits\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_resize(bitarr, 100);
  str = bit_array_to_string(bitarr);
  printf("%i) resize to 100 bits\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_fill_ones(bitarr);
  str = bit_array_to_string(bitarr);
  printf("%i) fill with ones\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_resize(bitarr, 64);
  str = bit_array_to_string(bitarr);
  printf("%i) resize to 64 bits\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  bit_array_resize(bitarr, 128);
  str = bit_array_to_string(bitarr);
  printf("%i) resize to 128 bits\n", step++);
  printf("'%s'\n", str);
  free(str);
  
  FILE* f;
  char filename[] = "/tmp/bitarrtest.bits";
  f = fopen(filename, "w");
  bit_array_save(bitarr, f);
  fclose(f);

  printf("Saving bitarray in %s\n", filename);
  str = bit_array_to_string(bitarr);
  printf("'%s'\n", str);
  free(str);

  // Deconstruct bit array
  bit_array_free(bitarr);
  
  f = fopen(filename, "r");
  bitarr = bit_array_load(f);
  fclose(f);

  printf("Loading bitarray in %s\n", filename);
  str = bit_array_to_string(bitarr);
  printf("'%s'\n", str);
  free(str);


  // concat two bit arrays
  //////////////////////////
  a = bit_array_create(33);
  b = bit_array_create(66);
	
  bit_array_set_bit(a, 0);
  //	bit_array_set_bit(a, 3);
  //	bit_array_set_bit(a, 4);
  bit_array_set_bit(a, 32);

  bit_array_set_bit(b, 0);
  bit_array_set_bit(b, 1);
  bit_array_set_bit(b, 2);
  bit_array_set_bit(b, 3);
  bit_array_set_bit(b, 4);
  bit_array_set_bit(b, 65);

  sa = bit_array_to_string(a);
  sb = bit_array_to_string(b);

  bit_array_concat(a, b);

  sc = bit_array_to_string(a);

	printf("should be: '%s%s'\n", sa, sb);	
	printf("concat   : '%s'\n", sc);

  test_resize(sa, sb, sc);

  free(sa);
  free(sb);
  free(sc);

  printf(" THE END.\n");
  
  return EXIT_SUCCESS;
}
