1. memcpy

void memorycpy(void*dest, const void*src, size_t size) {
	assert(dest && src);
	while (size--) {
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
}

2. memmove

void memorymove(void*dest, const void*src, size_t size) {
	assert(dest && src);
	if (dest < src)
		while (size--) {
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	else
		while (size--)
			*((char*)dest + size) = *((char*)src + size);
}

