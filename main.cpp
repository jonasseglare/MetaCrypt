#include "metacrypt.h"

td S<'R', 'E', '2'> Src; // <-- Put the data that you want to transform here.
td S<'K', 'A', 'T', 'T', 'S', 'K', 'I', 'T'> Key;

// Use Md::Decode to decode, and Md::Encode to encode
tp <tn T> F The_message_is; The_message_is<tn Tr<Md::Decode, Key, Src>::v> x;

int main() {
  return 0;
}
