
all: read_mouse VideoCapture v4l_example

read_mouse: read_mouse.c
	${CC} $^ -o $@

VideoCapture: VideoCapture.c
	${CC} $^ -o $@

v4l_example: v4l_example.c
	${CC} $^ -o $@

clean:
	rm -f read_mouse VideoCapture v4l_example