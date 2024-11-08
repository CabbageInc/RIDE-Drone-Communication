main: main.o TxHandler.o RxHandler.o Constants.o
	gcc -o main main.o TxHandler.o RxHandler.o Constants.o
main.o: main.c TxHandler.h RxHandler.h Constants.h
	gcc -c -g main.c
TxHandler.o: TxHandler.c TxHandler.h Constants.h
	gcc -c -g TxHandler.c
RxHandler.o: RxHandler.c RxHandler.h Constants.h
	gcc -c -g RxHandler.c
Constants.o: Constants.c Constants.h
	gcc -c -g Constants.c