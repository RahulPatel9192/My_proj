app: main.o login.o traininfo.o edittraininfo.o reservation.o
	cc  -Wall main.o login.o traininfo.o edittraininfo.o reservation.o -lm -o app
main.o: main.c header_h.h
	cc -c main.c
login1.o: login.c header_h.h
	cc -c login.c
traininfo.o: traininfo.c header_h.h
	cc -c traininfo.c 
edittraininfo.o: edittraininfo.c header_h.h
	cc -c edittraininfo.c
reservation.o: reservation.c header_h.h
	cc -c reservation.c
