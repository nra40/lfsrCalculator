/* Andrea McCool
** A program to determine and write some information about the state loops
** created by XORing various bits such as you would when creating a linear
** feedback shift register (LFSR)
** Takes an integer input that is 'n', that is, the number of bits of the 
** register in question. Prints the number of possible sets of loops, then
** prints the sizes of the possible loops.
*/

#include <stdio.h>
#include <stdlib.h>

// iterative multiplication, hi include, lo exclude
// multiplies hi * hi - 1 * hi - 2... hi - n whereuntil hi - (n + 1) = lo.
// alternatively, hi!/lo!
int itMult(int hi, int lo)
{
    int res = 1;
    int i = hi;

    for(; i > lo; i--)
    {
        res = res * i;
    }
 
    return res;
}

// mChooseK
// m! / k!
int mChooseK(int m, int k)
{
  return itMult(m, k);
}

int main(int argc, char * argv[])
{
  if(argc != 2)
    {
      return EXIT_FAILURE;
    }

  int n;
  int combos;
  int loopSets;

  sscanf(argv[1], "%d", &n);

  combos = 1 << n;

  loopSets = 0;
  int i = n;
  
  for(; i >= 2; i--)
    {
      loopSets += mChooseK(n, i);
    }

  printf("n: %d\n", n);
  printf("combinations: %d\n", combos);
  printf("loop sets: %d\n", loopSets);

  // Need to actually create the loop sets. 
  // Problem: There are a lot of them, and how to make sure I find them all
  // and also do not repeat the same loops? Or start the loop with something
  // from it's middle and thus double count one (which could prevent another
  // loop from being counted when it should be)
  // could have a bit array rep. all of the combos, check them off when they
  // are found in the loop set. Causes a slight problem in that wow time gets
  // pretty damn big. (worst is loopSets * combos, which is 
  // E_2_n (n choose k) * 2^n which is basically n!*exp(n) so... REALLY BAD

  return EXIT_SUCCESS;
}
