SOURCE := $(wildcard src/Hello/*.cc)
SOURCE += $(wildcard app/*.cc)

INCLUDE := src

all:
	mkdir bin
	cc -std=c++14 $(SOURCE) -lstdc++ -I $(INCLUDE) -o bin/hello
