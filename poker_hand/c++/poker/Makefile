.PHONY: build tags

all: build tags test

build:
	cmake --build build --target all

rebuild: destroy init all

test:
	build/tests/poker_tests

tags:
	ctags -R . src tests

clean:
	cmake --build build --target clean

destroy:
	rm -rf build

init:
	mkdir -p build
	(cd build; cmake ..)
