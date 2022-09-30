CXX=g++

EXEC=pkr

BUILDDIR=build

PREFIX=/usr/local

BINDIR=$(PREFIX)/bin

SRC=main.cpp disp.cpp prog.cpp mesh.cpp obj.cpp card.cpp util.cpp
OBJ=$(SRC:%.cpp=$(BUILDDIR)/%.o)

HDR=math.h

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

.PHONY: install
install:
	cp $(EXEC) $(BINDIR) ;
	mkdir -p $(PREFIX)/share/pkr ;
	cp -r res $(PREFIX)/share/pkr

.PHONY: uninstall
uninstall:
	rm $(BINDIR)/$(EXEC) ;
	rm -rf $(PREFIX)/share/pkr

.PHONY: clean
clean:
	rm $(BUILDDIR)/*.o $(EXEC)
