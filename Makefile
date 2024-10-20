all:
	gcc corethread.c -g -o segv.out
clean:
	rm segv.out ./core-*
