#include <iostream>

template <char ... c> struct String {};
template <typename T> struct Ops {};
template <char x, char ... y> struct Ops<String<x, y...>> {static const char first = x; typedef String<y...> rest; typedef String<y..., x> rotated;};
template <typename T, char x> struct Add {};
template <char x, char ... y> struct Add<String<y...>, x> {typedef String<y..., x> value;};
template <char x, typename T> struct Cons {};
template <char x, char ... y> struct Cons<x, String<y...>> {typedef String<x, y...> value;};
template <char a, char b> struct Range {typedef typename Cons<a, typename Range<a+1, b>::value>::value value;};
template <char x> struct Range<x,x> {typedef String<x> value;};

int main() {
  Ops<String<'a', 'b'>> x;
  std::cout << "Bra!" << std::endl;
  return 0;
}

static_assert(std::is_same<String<'a', 'b', 'c'>, typename Range<'a', 'c'>::value>::value, "asdf");
