CXX=g++

STATIC=main disp prog util
OBJ_STATIC=$(patsubst %, %.o, $(STATIC))

LDFLAGS=-lGLEW -lGL -lSDL2

.PHONY: clean

all: make

%.o: %.cpp %.h
	$(CXX) -c $< -o $@ $(LDFLAGS)

main.o: main.cpp
	$(CXX) -c $< -o $@ $(LDFLAGS)

make: $(OBJ_STATIC) $(HDR)
	$(CXX) $^ $(LDFLAGS)

clean:
	rm *.o a.out
