#include <iostream>
#include <iomanip>

#define tn typename
#define td typedef
#define tp template
#define sc static const
#define F struct
#define Q char
enum class Md {Encode,Decode};
tp <Q ... c> F S {};
tp <tn T> F Op {};
tp <Q x, Q ... y> F Op<S<x, y...>> {sc Q f = x; td S<y...> r; td S<y..., x> ro;};
tp <tn T, Q x> F Ad {};
tp <Q x, Q ... y> F Ad<S<y...>, x> {td S<y..., x> v;};
tp <Q x, tn T> F Cn {};
tp <Q x, Q ... y> F Cn<x, S<y...>> {td S<x, y...> v;};
tp <Q a, Q b> F Rg {td tn Cn<a, tn Rg<a+1, b>::v>::v v;};
tp <Q x> F Rg<x,x> {td S<x> v;};
tp <tn A, tn B> F Ct;
tp <tn A, tn B> F Ct {
  td Op<B> b; 
  td tn Ct<tn Ad<A, b::f>::v, tn b::r>::v v;
};
tp <tn A> F Ct<A, S<>> {td A v;};
tp <tn A, tn B> using ct = tn Ct<A, B>::v;
tp <Q x, Q y> using rg = tn Rg<x, y>::v;
td ct<ct<rg<'A', 'Z'>, rg<'0', '9'>>, S<' ', ',', '.'>> CSet;
tp <tn T> F L {sc int v = 1 + L<tn Op<T>::r>::v;};
tp <> F L<S<>> {sc int v = 0;};
constexpr int mup(int x, int y) {return x<0? mup(x+y,y):x;}
tp <int n, tn T> F Nth {sc Q v =  Nth<mup(n-1,L<T>::v), tn Op<T>::ro>::v;};
tp <tn T> F Nth<0, T> {sc Q v = Op<T>::f;};
tp <Q x, tn T> F Fd {};
tp <Q x, Q y, Q ... z> F Fd<x, S<y, z...>> {sc int v = 1+Fd<x, S<z...>>::v;};
tp <Q x, Q ... y> F Fd<x,S<x,y...>> {sc int v = 0;};
tp <Q x> F Ind {sc int v = Fd<x, CSet>::v;};
constexpr int sg(Md m) {return m==Md::Encode? 1 : -1;}
tp <Md m, Q x, Q y> F Cd {sc Q v = Nth<sg(m)*Ind<x>::v + Ind<y>::v, CSet>::v;};
tp <Md m, tn K, tn X> F Tr;
tp <Md m, tn K, tn X> F Tr {
  td Op<K> k; 
  td Op<X> x; 
  td tn Cn<Cd<m, k::f, x::f>::v, tn Tr<m, tn k::ro, tn x::r>::v>::v v;
};
tp <Md m, tn K> F Tr<m,K,S<>> {td S<> v;};


td S<'J','E','1','P','0','B','X','Q','1','J','E','1'> Coded;

td S<'C','A','S','S','O','U','L','E','T'> Key; // /* Hint: fill in name of favourite dish (French cuisine) during meetings. */

tp <tn T> F The_message_is;
The_message_is<tn Tr<Md::Decode, Key, Coded>::v> x;

// int main() {
//   return 0;
// }

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
 Count: 39

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
