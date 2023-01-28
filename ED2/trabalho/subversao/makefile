all: compila_trabalho

compila_trabalho: main.o tad.o simplesmente_encadeada.o duplamente_encadeada.o funcoes_auxiliares.o
	gcc main.o simplesmente_encadeada.o tad.o duplamente_encadeada.o funcoes_auxiliares.o -o trabalho_compilado
main.o:
	gcc -c main.c
tad.o:
	gcc -c tad.c
simplesmente_encadeada.o:
	gcc -c simplesmente_encadeada.c
duplamente_encadeada:
	gcc -c duplamente_encadeada.c
funcoes_auxiliares.o:
	gcc -c funcoes_auxiliares.c
clean:
	rm main.o tad.o simplesmente_encadeada.o duplamente_encadeada.o funcoes_auxiliares.o  trabalho_compilado
