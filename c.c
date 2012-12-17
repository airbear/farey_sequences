#include <stdio.h>

struct x {
	int i;
	int j;
};

int main(void) {
	struct x y;
	struct x z;
	y.i = 1;
	y.j = 2;
	z = y;
	printf("%d %d\n", z.i, z.j);
	
}
