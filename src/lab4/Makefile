

CFLAGS = -fdump-tree-original -fdump-tree-optimized

all: ackermann

ackermann: ackermann.o
	${CC} $^ -o $@ 

clean:
	rm -rf *.o