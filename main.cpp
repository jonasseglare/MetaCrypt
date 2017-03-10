#include <iostream>

#define tn typename
#define td typedef
#define tp template

template <char ... c> struct String {};
template <typename T> struct Ops {};
template <char x, char ... y> struct Ops<String<x, y...>> {static const char first = x; typedef String<y...> rest; typedef String<y..., x> rotated;};
template <typename T, char x> struct Add {};
template <char x, char ... y> struct Add<String<y...>, x> {typedef String<y..., x> value;};
template <char x, typename T> struct Cons {};
template <char x, char ... y> struct Cons<x, String<y...>> {typedef String<x, y...> value;};
template <char a, char b> struct Range {typedef typename Cons<a, typename Range<a+1, b>::value>::value value;};
template <char x> struct Range<x,x> {typedef String<x> value;};
template <typename A, typename B> struct Cat;
template <typename A, typename B> struct Cat {
  td Ops<B> b; 
  td tn Cat<tn Add<A, b::first>::value, tn b::rest>::value value;
};
template <typename A> struct Cat<A, String<>> {td A value;};
template <typename A, typename B> using cat = tn Cat<A, B>::value;
template <char x, char y> using range = tn Range<x, y>::value;
typedef cat<String<' ', ',', '.'>, cat<range<'A', 'Z'>, range<'0', '9'>>> CharSet;
template <int n, typename T> struct Nth {static const char value =  Nth<n-1, tn Ops<T>::rotated>::value;};
template <typename T> struct Nth<0, T> {static const char value = Ops<T>::first;};
template <typename T> struct Length {static const int value = 1 + Length<tn Ops<T>::rest>::value;};
template <> struct Length<String<>> {static const int value = 0;};

int main() {
  Ops<String<'a', 'b'>> x;
  std::cout << "Bra!" << std::endl;
  return 0;
}

//static_assert(3 == Length<
static_assert('c' == Nth<2, String<'a', 'b', 'c', 'd'> >::value, "asdf");
static_assert(std::is_same<String<'a', 'b', 'c'>, typename Range<'a', 'c'>::value>::value, "asdf");
static_assert(std::is_same<tn Add<String<'a'>, 'b'>::value, String<'a', 'b'>>::value, "asdf");
static_assert(std::is_same<
              tn Cat<String<'a', 'b'>, String<'c', 'd'>>::value,
              String<'a', 'b', 'c', 'd'> >::value, "asdf");
