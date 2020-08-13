##
# Pincenez
#
# @file
# @version 0.1

CXX=g++
CFLAGS=-I. -Wall
UNAME=$(shell uname)

SOURCES +=
SOURCES += src/rectangle.cpp src/point.cpp src/vector2.cpp src/game.cpp src/spritebatch.cpp src/color.cpp src/mtexture.cpp

EXE = libengine.so

INCLUDES = -Ilib/
LIBS =-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
OBJS = $(addprefix build/,$(addsuffix .o, $(basename $(notdir $(SOURCES)))))

all: $(EXE) compileDatabase

# Create objects with position independet code
build/%.o:src/%.cpp
	@echo Compiling $@
	@$(CXX) $(CFLAGS) -fPIC $(INCLUDES) -c -o $@  $(LIBS) $<

# Create Shared library
$(EXE): $(OBJS)
	@echo Linking
	@$(CXX) -shared $^ -o $@ $(INCLUDES) $(LIBS)

compile_commands.json:
	@ (echo "[";\
	make --always-make --dry-run | grep -v make | grep -wE 'clang|gcc|g++' | grep -w '\-c' \
	| sed "s,\(.* \)\([.0-9a-Z/]*\)$$,{\n\"directory\":\"${PWD}\"\,\n\"command\": \"\1\2\"\,\n\"file\": \"\2\"\n}\,,";\
	echo "]" )> compile_commands.json

.PHONY: install
install: /usr/lib/$(EXE)

/usr/lib/$(EXE): $(EXE)
	@echo Installing library in system folder
	@cp $(EXE) /usr/lib/

uninstall:
	@rm /usr/lib/$(EXE)

.PHONY: compileDatabase
compileDatabase: compile_commands.json

.PHONY: clean
clean:
	@rm build/*

# end
