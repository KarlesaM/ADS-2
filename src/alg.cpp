// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t a) {
double k = value;
  if (a == 0) {
    return 1;}
  if (a == 1) {
    return value;}
  k *= pown(value, a - 1);
  return k;
}

uint64_t fact(uint16_t a) {
if (a == 0) {
    return 1;
  }
  return a * fact(a - 1);
}

double calcItem(double x, uint16_t a) {
double k = pown(x, a) / fact(a);
  return k;
}

double expn(double x, uint16_t count) {
double exp1 = 1;
  int z = 1;
  while (count > z-1) {
    exp1 += calcItem(x, z);
    z++;
  }
  return exp1;
}

double sinn(double x, uint16_t count) {
double sin0 = 0;
  for (uint16_t i = 1; i <= count; i++) {
    sin0 += pown(-1, i - 1) * calcItem(x, (2 * i - 1));
  }
  return sin0;
}

double cosn(double x, uint16_t count) {
double cos0 = 0;
  for (uint16_t i = 1; i <= count; i++) {
    cos0 += pown(-1, i - 1) * calcItem(x, (2 * i - 2));
  }
  return cos0;
}
