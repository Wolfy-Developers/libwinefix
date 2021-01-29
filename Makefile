all: libwinefix.c
	gcc -fPIC -shared -o libwinefix.so libwinefix.c -ldl
