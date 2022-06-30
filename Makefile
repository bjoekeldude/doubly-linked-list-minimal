CC=gcc-10
CFLAGS=-Wall
RM=rm -rf


all: doub-LL.c
	$(CC) -o LinkedL.exe doub-LL.c 

debug: doub-LL.c
	mkdir debug
	$(CC) -g -o debug/LinkedL-debug doub-LL.c

clean:
	@echo "deleting debug and release...."
	@$(RM) -rf debug
	@$(RM) LinkedL doub-LL.o LinkedL-debug
