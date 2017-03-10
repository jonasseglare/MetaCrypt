#include <iostream>

template <char ... c> struct String {};
template <typename T> struct Ops {};
template <char x, char ... y> struct Ops<String<x, y...>> {static const char first = x; typedef String<y...> rest; typedef String<y..., x> rotated;};
template <typename T, char x> struct Add {};
template <char x, char ... y> struct Add<String<y...>, x> {typedef String<y..., x> value;};
template <char x, typename T> struct Cons {};
template <char x, char ... y> struct Cons<x, String<y...>> {typedef String<x, y...> value;};


int main() {
  Ops<String<'a', 'b'>> x;
  std::cout << "Bra!" << std::endl;
  return 0;
}
