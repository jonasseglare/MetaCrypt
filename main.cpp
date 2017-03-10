#include <iostream>

#define tn typename
#define td typedef
#define tp template
#define sc static const
#define F struct
tp<tn T> using V = tn T::v;

template <char ... c> struct String {};
template <typename T> struct Ops {};
template <char x, char ... y> struct Ops<String<x, y...>> {static const char first = x; typedef String<y...> rest; typedef String<y..., x> rotated;};
template <typename T, char x> struct Add {};
template <char x, char ... y> struct Add<String<y...>, x> {typedef String<y..., x> v;};
template <char x, typename T> struct Cons {};
template <char x, char ... y> struct Cons<x, String<y...>> {typedef String<x, y...> v;};
template <char a, char b> struct Range {typedef typename Cons<a, typename Range<a+1, b>::v>::v v;};
template <char x> struct Range<x,x> {typedef String<x> v;};
template <typename A, typename B> struct Cat;
template <typename A, typename B> struct Cat {
  td Ops<B> b; 
  td tn Cat<tn Add<A, b::first>::v, tn b::rest>::v v;
};
template <typename A> struct Cat<A, String<>> {td A v;};
template <typename A, typename B> using cat = tn Cat<A, B>::v;
template <char x, char y> using range = tn Range<x, y>::v;
typedef cat<String<' ', ',', '.'>, cat<range<'A', 'Z'>, range<'0', '9'>>> CharSet;
template <int n, typename T> struct Nth {static const char v =  Nth<n-1, tn Ops<T>::rotated>::v;};
template <typename T> struct Nth<0, T> {static const char v = Ops<T>::first;};
template <typename T> struct Length {static const int v = 1 + Length<tn Ops<T>::rest>::v;};
template <> struct Length<String<>> {static const int v = 0;};
//template <char c, typename T> struct Find {};
//template <char x, char y, char z...> struct Find {};


int main() {
  Ops<String<'a', 'b'>> x;
  std::cout << "Bra!" << std::endl;
  return 0;
}

//static_assert(3 == Length<
static_assert('c' == Nth<2, String<'a', 'b', 'c', 'd'> >::v, "asdf");
static_assert(std::is_same<String<'a', 'b', 'c'>, typename Range<'a', 'c'>::v>::value, "asdf");
static_assert(std::is_same<tn Add<String<'a'>, 'b'>::v, String<'a', 'b'>>::value, "asdf");
static_assert(std::is_same<
              tn Cat<String<'a', 'b'>, String<'c', 'd'>>::v,
              String<'a', 'b', 'c', 'd'> >::value, "asdf");
