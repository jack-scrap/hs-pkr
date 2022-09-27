CXX=g++

SRC=main.cpp disp.cpp prog.cpp util.cpp
OBJ=$(SRC:%.cpp=%.o)

LDFLAGS=-lGLEW -lGL -lSDL2

.PHONY: all
all: pkr

%.o: %.cpp %.h
	$(CXX) -c $< -o $@ $(LDFLAGS)

main.o: main.cpp
	$(CXX) -c $< -o $@ $(LDFLAGS)

pkr: $(OBJ) $(HDR)
	$(CXX) $(OBJ) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm *.o pkr
