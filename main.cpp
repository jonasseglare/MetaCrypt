#include "metacrypt.h"

td S<'R', 'E', '2'> Src;
td S<'K', 'A', 'T', 'T', 'S', 'K', 'I', 'T'> Key;

tp <tn T> F The_message_is; The_message_is<tn Tr<Md::Decode, Key, Src>::v> x;

int main() {
  return 0;
}
