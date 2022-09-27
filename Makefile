CXX=g++

EXEC=pkr

BUILDDIR=build

SRC=main.cpp disp.cpp prog.cpp util.cpp
OBJ=$(SRC:%.cpp=$(BUILDDIR)/%.o)

LDFLAGS=-lGLEW -lGL -lSDL2

.PHONY: all
all: mk_build $(EXEC)

$(BUILDDIR)/%.o: %.cpp %.h
	$(CXX) -c $< -o $@

$(BUILDDIR)/main.o: main.cpp
	$(CXX) -c $< -o $@

$(EXEC): $(OBJ) $(HDR)
	$(CXX) $(OBJ) $(LDFLAGS) -o $@

.PHONY: mk_build
mk_build:
	mkdir -p $(BUILDDIR)

.PHONY: clean
clean:
	rm $(BUILDDIR)/*.o $(EXEC)
