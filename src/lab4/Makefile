

CFLAGS = -O3
#CFLAGS += -fdump-passes #show active optimization passes

all: ackermann test_gradient



ackermann: CFLAGS += -fdump-tree-original \
          			 -fdump-tree-optimized \
          			 -fopt-info-inline-optimized-missed=inline.txt

        #   -fopt-info-missed=missed.all 

ackermann: ackermann.o
	${LINK.c} $^ -o $@ 



DUMP_TREES = original cfg ssa optimized
DUMP_RTL = final
# DUMP_TREES = all
# DUMP_RTL = final

ackermann_function.o: \
CFLAGS = $(foreach t,${DUMP_TREES},-fdump-tree-$t -fdump-tree-$t-graph ) \
         $(foreach t,${DUMP_RTL},-fdump-rtl-$t )

.SUFFIXES: .dot .png 
.dot.png:
	dot -Tpng $< -o $@


GRAPH_FILES = $(patsubst %.dot,%.png,$(wildcard *.dot))

graphs: ${GRAPH_FILES}
	


test_gradient: gradient.o test_gradient.o
	${LINK.c} $^ -o $@



clean:
	rm -rf *.o ackermann.c.* inline.txt ackermann_function.c.* 
