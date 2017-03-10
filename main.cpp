#include <iostream>
#define tn typename
#define td typedef
#define tp template
#define sc static const
#define F struct
#define C char

tp <C ... c> F S {};
td S<'C','A','S','S','O','U','L','E','T'> Key;
tp<tn T> using V = tn T::v;
tp <tn T> F Op {};
tp <C x, C ... y> F Op<S<x, y...>> {sc C f = x; td S<y...> r; td S<y..., x> ro;};
tp <tn T, C x> F Ad {};
tp <C x, C ... y> F Ad<S<y...>, x> {td S<y..., x> v;};
tp <C x, tn T> F Cn {};
tp <C x, C ... y> F Cn<x, S<y...>> {td S<x, y...> v;};
tp <C a, C b> F Rg {td tn Cn<a, tn Rg<a+1, b>::v>::v v;};
tp <C x> F Rg<x,x> {td S<x> v;};
tp <tn A, tn B> F Ct;
tp <tn A, tn B> F Ct {
  td Op<B> b; 
  td tn Ct<tn Ad<A, b::f>::v, tn b::r>::v v;
};
tp <tn A> F Ct<A, S<>> {td A v;};
tp <tn A, tn B> using ct = tn Ct<A, B>::v;
tp <C x, C y> using rg = tn Rg<x, y>::v;
td ct<S<' ', ',', '.'>, ct<rg<'A', 'Z'>, rg<'0', '9'>>> CSet;
tp <tn T> F L {sc int v = 1 + L<tn Op<T>::r>::v;};
tp <> F L<S<>> {sc int v = 0;};
constexpr int mup(int x, int y) {return x<0? mup(x+y,y):x;}
tp <int n, tn T> F Nth {sc C v =  Nth<mup(n-1,L<T>::v), tn Op<T>::ro>::v;};
tp <tn T> F Nth<0, T> {sc C v = Op<T>::f;};
//tp <C c, tn T> F Find {};
//tp <C x, C y, C z...> F Find {};


int main() {
  Op<S<'a', 'b'>> x;
  std::cout << "Bra!" << std::endl;
  return 0;
}

static_assert(3 == L<S<'a', 'b', 'c'>>::v, "asdf");
static_assert('c' == Nth<2, S<'a', 'b', 'c', 'd'> >::v, "asdf");
static_assert(std::is_same<S<'a', 'b', 'c'>, typename Rg<'a', 'c'>::v>::value, "asdf");
static_assert(std::is_same<tn Ad<S<'a'>, 'b'>::v, S<'a', 'b'>>::value, "asdf");
static_assert(std::is_same<
              tn Ct<S<'a', 'b'>, S<'c', 'd'>>::v,
              S<'a', 'b', 'c', 'd'> >::value, "asdf");
static_assert(mup(2, 3) == 2, "asdf");
static_assert(mup(-1, 3) == 2, "asdf");
