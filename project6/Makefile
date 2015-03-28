CFLAGS=-Wall -O9
LDFLAGS=
LDLIBS= -lc -lopencv_core -lopencv_highgui -lopencv_imgproc

all: solve_image 

clean:
	rm *.o

OBJS=image_to_array.o

%.o: %.cpp
	g++ -g -c $(CFLAGS) $<

make_steg: $(OBJS) make_steg.o 
	g++ $(LDFLAGS) -o make_steg $(OBJS) make_steg.o $(LDLIBS)

solve_image: $(OBJS) solve_image.o
	g++ $(LDFLAGS) -o solve_image $(OBJS) solve_image.o $(LDLIBS)

