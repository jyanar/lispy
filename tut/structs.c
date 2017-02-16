#include <stdio.h>

typedef struct {
  float x;
  float y;
} point;

int main(int argc, char** argv) {

  point p;
  p.x = 1.0;
  p.y = 1.0;

  printf("%f\n", p.x);
  printf("%f\n", p.y);

  return 0;
}

