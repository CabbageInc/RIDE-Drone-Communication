main: main.o TxPacket.o
	gcc -o main main.o TxPacket.o
main.o: main.c TxPacket.h
	gcc -c -g main.c
TxPacket.o: TxPacket.c TxPacket.h
	gcc -c -g TxPacket.c