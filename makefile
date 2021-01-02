all: isort

txtfind: txtfind.c
	gcc -Wall -g txtfind.c -o txtfind

isort: isort.c
	gcc -Wall -g isort.c -o isort

.PHONY: clean all

clean:
	rm isort