#include <stdio.h>

union {
	unsigned int bits32;
	unsigned char bytes[4];
} theValue;

int to_little(int bits32)
{
	unsigned char bytes[4];
	int ret;

	bytes[0] = (unsigned char)((bits32 >> 0) & 0xff);
	bytes[1] = (unsigned char)((bits32 >> 8) & 0xff);
	bytes[2] = (unsigned char)((bits32 >> 16) & 0xff);
	bytes[3] = (unsigned char)((bits32 >> 24) & 0xff);

	ret = ((int)bytes[0] << 0) |
		  ((int)bytes[1] << 8) |
		  ((int)bytes[2] << 16)|
		  ((int)bytes[3] << 24);

	return ret;
}

int to_big(int bits32)
{
	unsigned char bytes[4];
	int ret;

	bytes[0] = (unsigned char)((bits32 >> 0) & 0xff);
	bytes[1] = (unsigned char)((bits32 >> 8) & 0xff);
	bytes[2] = (unsigned char)((bits32 >> 16) & 0xff);
	bytes[3] = (unsigned char)((bits32 >> 24) & 0xff);

	ret = ((int)bytes[0] << 24) |
 		  ((int)bytes[1] << 16) |
 		  ((int)bytes[2] << 8)  |
		  ((int)bytes[3] << 0);

	return ret;
}


int main(int argc, char*argv[])
{
	theValue.bits32 = 1;

	if (theValue.bytes[0] == 0) {
		printf("Big-endian !\n");
	}
	else {
		printf("Little-endian !\n");
	}

	return 0;
}
