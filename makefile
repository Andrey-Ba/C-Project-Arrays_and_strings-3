all: isort



isort: PartA.c
	gcc -Wall -g PartA.c -o isort

.PHONY: clean all

clean:
	rm isort