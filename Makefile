CXX=g++

EXEC=pkr

BUILDDIR=build

PREFIX=/usr/local

DATAROOTDIR=$(PREFIX)/share
DATADIR=$(DATAROOTDIR)/pkr

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
	mkdir -p $(DATADIR) ;
	cp -r res $(DATADIR)

.PHONY: uninstall
uninstall:
	rm $(BINDIR)/$(EXEC) ;
	rm -rf $(DATADIR)

.PHONY: clean
clean:
	rm $(BUILDDIR)/*.o $(EXEC)
