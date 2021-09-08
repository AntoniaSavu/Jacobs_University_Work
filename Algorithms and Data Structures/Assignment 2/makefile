all: p1 p2 p3 p4 p5 p6
CC=g++

CFLAGS=-g -Wall

p1: a2p1.cpp
	$(CC) $(CFLAGS) -o p1.o a2p1.cpp


p2: a2p2.cpp
	$(CC) $(CFLAGS) -o p2.o a2p2.cpp

p3: WindGauge.o testWindGauge.o
	$(CC) -o p3 WindGauge.o testWindGauge.o

WindGauge.o: WindGauge.cpp
	$(CC) $(CFLAGS) WindGauge.cpp

testWindGauge.o: testWindGauge.cpp
	$(CC) $(CFLAGS) testWindGauge.cpp


p4: a2p4.cpp
	$(CC) $(CFLAGS) -o p4.o a2p4.cpp

p5: a2p5.cpp
	$(CC) $(CFLAGS) -o p5.o a2p5.cpp

p6: a2p6.cpp
	$(CC) $(CFLAGS) -o p6.o a2p6.cpp


clean:
	$(RM) p1.o p2.o p3.o p4.o p5.o p6.o

	
	