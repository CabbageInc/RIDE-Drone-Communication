main: main.o TxHandler.o RxHandler.o
	gcc -o main main.o TxHandler.o RxHandler.o
main.o: main.c TxHandler.h RxHandler.h
	gcc -c -g main.c
TxHandler.o: TxHandler.c TxHandler.h
	gcc -c -g TxHandler.c
RxHandler.o: RxHandler.c RxHandler.h
	gcc -c -g RxHandler.c