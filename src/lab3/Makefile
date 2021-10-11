all: v4l_example

v4l_example: GradientNonOptimized.c v4l_example.c
	${CC} $^ -o $@ -laa

clean:
	rm -f read_mouse VideoCapture v4l_example