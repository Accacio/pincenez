##
# Pincenez
#
# @file
# @version 0.1

CXX=g++
CFLAGS=-I.
UNAME=$(shell uname)

SOURCES +=
SOURCES += pcn/rectangle.cpp src/point.cpp src/vector2.cpp src/game.cpp src/spritebatch.cpp src/color.cpp src/mtexture.cpp

EXE = engine

INCLUDES = -Ilib/
LIBS =`sdl2-config --libs` -lSDL2_image -lSDL2_ttf -lSDL2_mixer
OBJS = $(addprefix build/,$(addsuffix .o, $(basename $(notdir $(SOURCES)))))

all: build/Content $(EXE) compileDatabase

build/%.o:pcn/%.cpp
	@echo Compiling $@
	@$(CXX) $(INCLUDES) -fpic -c -o $@ $<

build/Content:
	@echo Linking Content folder
	@ln -s ../Content build/Content

$(EXE): $(OBJS)
	@echo Linking
	@$(CXX) -shared -o build/lib$@.so $^ $(LIBS) $(INCLUDES)

compile_commands.json:
	@ (echo "[";\
	make --always-make --dry-run | grep -v make | grep -wE 'clang|gcc|g++' | grep -w '\-c' \
	| sed "s,\(.* \)\([.0-9a-Z/]*\)$$,{\n\"directory\":\"${PWD}\"\,\n\"command\": \"\1\2\"\,\n\"file\": \"\2\"\n}\,,";\
	echo "]" )> compile_commands.json

example:
	@$(CXX) src/sandbox.cpp -o build/$@ $(LIBS) $(INCLUDES) -l$(EXE) -Lbuild/

.PHONY: install
install:
	@cp build/lib$(EXE).so /usr/lib
uninstall:
	@rm /usr/lib/lib$(EXE).so

.PHONY: compileDatabase
compileDatabase: compile_commands.json

.PHONY: clean
clean:
	@rm build/*

# end
