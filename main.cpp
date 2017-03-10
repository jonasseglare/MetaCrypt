#include <iostream>

#define tn typename
#define td typedef
#define tp template
#define sc static const
#define F struct
#define C char
tp<tn T> using V = tn T::v;

tp <C ... c> F S {};
tp <tn T> F Ops {};
tp <C x, C ... y> F Ops<S<x, y...>> {sc C f = x; td S<y...> r; td S<y..., x> ro;};
tp <tn T, C x> F Add {};
tp <C x, C ... y> F Add<S<y...>, x> {td S<y..., x> v;};
tp <C x, tn T> F Cons {};
tp <C x, C ... y> F Cons<x, S<y...>> {td S<x, y...> v;};
tp <C a, C b> F Rg {td tn Cons<a, tn Rg<a+1, b>::v>::v v;};
tp <C x> F Rg<x,x> {td S<x> v;};
tp <tn A, tn B> F Ct;
tp <tn A, tn B> F Ct {
  td Ops<B> b; 
  td tn Ct<tn Add<A, b::f>::v, tn b::r>::v v;
};
tp <tn A> F Ct<A, S<>> {td A v;};
tp <tn A, tn B> using cat = tn Ct<A, B>::v;
tp <C x, C y> using rg = tn Rg<x, y>::v;
td cat<S<' ', ',', '.'>, cat<rg<'A', 'Z'>, rg<'0', '9'>>> CSet;
tp <int n, tn T> F Nth {sc C v =  Nth<n-1, tn Ops<T>::ro>::v;};
tp <tn T> F Nth<0, T> {sc C v = Ops<T>::f;};
tp <tn T> F L {sc int v = 1 + L<tn Ops<T>::r>::v;};
tp <> F L<S<>> {sc int v = 0;};
//tp <C c, tn T> F Find {};
//tp <C x, C y, C z...> F Find {};


int main() {
  Ops<S<'a', 'b'>> x;
  std::cout << "Bra!" << std::endl;
  return 0;
}

static_assert(3 == L<S<'a', 'b', 'c'>>::v, "asdf");
static_assert('c' == Nth<2, S<'a', 'b', 'c', 'd'> >::v, "asdf");
static_assert(std::is_same<S<'a', 'b', 'c'>, typename Rg<'a', 'c'>::v>::value, "asdf");
static_assert(std::is_same<tn Add<S<'a'>, 'b'>::v, S<'a', 'b'>>::value, "asdf");
static_assert(std::is_same<
              tn Ct<S<'a', 'b'>, S<'c', 'd'>>::v,
              S<'a', 'b', 'c', 'd'> >::value, "asdf");
