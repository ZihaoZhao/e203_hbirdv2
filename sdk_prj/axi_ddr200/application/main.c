/*
 ============================================================================
 Name        : main.c
 Author      : zzh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello RISC-V World in C
 ============================================================================
 */

#include <stdio.h>

/*
 * Demonstrate how to print a greeting message on standard output
 * and exit.
 *
 * WARNING: This is a build-only project. Do not try to run it on a
 * physical board, since it lacks the device specific startup.
 *
 * If semihosting is not available, use `--specs=nosys.specs` during link.
 */

#define USER_DEF_GPIO_BASE 0xB0000000

int main(void)
{
  int i;
  while (1) {
	  unsigned int * pu32;
	  pu32 = (unsigned int *)USER_DEF_GPIO_BASE;
	  *pu32 = 0xffffffff;
	  printf("LED off\r\n");
	  for(i=0;i<500;i++);
	  *pu32 = 0xaaaaaaaa;
	  printf("LED on\r\n");
	  for(i=0;i<500;i++);
  }
  printf("Hello RISC-V World!" "\n");
  return 0;
}
