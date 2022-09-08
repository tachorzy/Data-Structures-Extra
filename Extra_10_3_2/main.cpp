#include <iostream>
#include "Hash.h"

int main() {
  Hash hash(10);

  hash.dynamicmapping(89396696, "VALLENTUNA");
  hash.linearprobe(70507604, "HUVUDSPELARE");
  hash.dynamicmapping(30428982, "NORRÅKER");
  hash.dynamicmapping(20281631, "RISATORP");

  hash.dynamicmapping(60307441, "HOLMSBU");//collision
  hash.linearprobe(40466006, "TVÄRSÄKER");//collsion
  hash.quadprobe(29155402, "LILLÅNGEN");//collision
  hash.doublehash(40496471, "NYSJÖN");//collision

  hash.search(1, "VALLENTUNA");
  hash.search(1, "HOLMSBU");
  hash.search(1, "NYSJÖN");
  hash.search(1, "RISATORP");
  hash.search(1, "TVÄRSÄKER");

}