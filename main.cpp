#include "metacrypt.h"

// Put the data that you want to transform here.
td S<'R', 'E', '2'> Src; 

// This is the encryption/decryption key (symmetric)
td S<'K', 'A', 'T', 'T', 'S', 'K', 'I', 'T'> Key;

// Use Md::Decode to decode, and Md::Encode to encode
// Here we display the result
tp <tn T> F The_message_is; The_message_is<tn Tr<Md::Decode, Key, Src>::v> x;

int main() {
  return 0;
}
