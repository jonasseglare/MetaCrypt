#include <iostream>

#define tn typename
#define td typedef
#define tp template
#define sc static const
#define F struct
#define C char
tp<tn T> using V = tn T::v;

tp <C ... c> F String {};
tp <tn T> F Ops {};
tp <C x, C ... y> F Ops<String<x, y...>> {sc C first = x; td String<y...> rest; td String<y..., x> rotated;};
tp <tn T, C x> F Add {};
tp <C x, C ... y> F Add<String<y...>, x> {td String<y..., x> v;};
tp <C x, tn T> F Cons {};
tp <C x, C ... y> F Cons<x, String<y...>> {td String<x, y...> v;};
tp <C a, C b> F Rg {td tn Cons<a, tn Rg<a+1, b>::v>::v v;};
tp <C x> F Rg<x,x> {td String<x> v;};
tp <tn A, tn B> F Cat;
tp <tn A, tn B> F Cat {
  td Ops<B> b; 
  td tn Cat<tn Add<A, b::first>::v, tn b::rest>::v v;
};
tp <tn A> F Cat<A, String<>> {td A v;};
tp <tn A, tn B> using cat = tn Cat<A, B>::v;
tp <C x, C y> using rg = tn Rg<x, y>::v;
td cat<String<' ', ',', '.'>, cat<rg<'A', 'Z'>, rg<'0', '9'>>> CSet;
tp <int n, tn T> F Nth {sc C v =  Nth<n-1, tn Ops<T>::rotated>::v;};
tp <tn T> F Nth<0, T> {sc C v = Ops<T>::first;};
tp <tn T> F L {sc int v = 1 + L<tn Ops<T>::rest>::v;};
tp <> F L<String<>> {sc int v = 0;};
//tp <C c, tn T> F Find {};
//tp <C x, C y, C z...> F Find {};


int main() {
  Ops<String<'a', 'b'>> x;
  std::cout << "Bra!" << std::endl;
  return 0;
}

static_assert(3 == L<String<'a', 'b', 'c'>>::v, "asdf");
static_assert('c' == Nth<2, String<'a', 'b', 'c', 'd'> >::v, "asdf");
static_assert(std::is_same<String<'a', 'b', 'c'>, typename Rg<'a', 'c'>::v>::value, "asdf");
static_assert(std::is_same<tn Add<String<'a'>, 'b'>::v, String<'a', 'b'>>::value, "asdf");
static_assert(std::is_same<
              tn Cat<String<'a', 'b'>, String<'c', 'd'>>::v,
              String<'a', 'b', 'c', 'd'> >::value, "asdf");
