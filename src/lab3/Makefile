all: v4l_example

v4l_example: GradientNonOptimized.c FindCenter.c render_sdl2.c v4l_example.c
	${CC} -I/usr/include/SDL2/ $^ -o $@ -laa -lm -lSDL2 -lGL

clean:
	rm -f read_mouse VideoCapture v4l_example