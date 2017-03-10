#include <iostream>
#include <iomanip>
#include "metacrypt.h"

/////////////////////////////////////////
// Helpers
template <int i, typename s>
struct MakeTable {
  static void disp() {
  }
};

template <int i, char x, char ... y>
struct MakeTable<i, S<x, y...>> {
  static void disp() {
    std::cout << std::setw(3) << i << ": '" << x << "'" << std::endl;
    MakeTable<i+1, S<y...>>::disp();
  }
};

template <int i> 
struct MakeTable<i, S<>> {
  static void disp() {
    std::cout << "Count: " << i << std::endl;
  }
};

td S<'H', 'E', 'J'> Src;
td S<'R', 'E', '2'> Dst;
td S<'K', 'A', 'T', 'T', 'S', 'K', 'I', 'T'> Key;
static_assert(std::is_same<tn Tr<Md::Encode, Key, Src>::v, Dst>::value, "asdf");
static_assert(std::is_same<tn Tr<Md::Decode, Key, Dst>::v, Src>::value, "asdf");

tp <tn T> F The_message_is;
The_message_is<tn Tr<Md::Decode, Key, Dst>::v> x;

int main() {
  MakeTable<0, CSet>::disp();
  std::cout << "Bra!" << std::endl;
  return 0;
}



/*

  0: 'A'
  1: 'B'
  2: 'C'
  3: 'D'
  4: 'E'
  5: 'F'
  6: 'G'
  7: 'H'
  8: 'I'
  9: 'J'
 10: 'K'
 11: 'L'
 12: 'M'
 13: 'N'
 14: 'O'
 15: 'P'
 16: 'Q'
 17: 'R'
 18: 'S'
 19: 'T'
 20: 'U'
 21: 'V'
 22: 'W'
 23: 'X'
 24: 'Y'
 25: 'Z'
 26: '0'
 27: '1'
 28: '2'
 29: '3'
 30: '4'
 31: '5'
 32: '6'
 33: '7'
 34: '8'
 35: '9'
 36: ' '
 37: ','
 38: '.'
 39: '?'
 Count: 40

*/

static_assert('D' == Cd<Md::Encode, 'B', 'C'>::v, "asdf");
static_assert('C' == Cd<Md::Decode, 'B', 'D'>::v, "asdf");
static_assert(3 == L<S<'a', 'b', 'c'>>::v, "asdf");
static_assert('c' == Nth<2, S<'a', 'b', 'c', 'd'> >::v, "asdf");
static_assert('c' == Nth<-2, S<'a', 'b', 'c', 'd'> >::v, "asdf");
static_assert(std::is_same<S<'a', 'b', 'c'>, typename Rg<'a', 'c'>::v>::value, "asdf");
static_assert(std::is_same<tn Ad<S<'a'>, 'b'>::v, S<'a', 'b'>>::value, "asdf");
static_assert(std::is_same<
              tn Ct<S<'a', 'b'>, S<'c', 'd'>>::v,
              S<'a', 'b', 'c', 'd'> >::value, "asdf");
static_assert(mup(2, 3) == 2, "asdf");
static_assert(mup(-1, 3) == 2, "asdf");
static_assert(3 == Fd<'D', S<'A','B','C','D'>>::v, "asdf");
