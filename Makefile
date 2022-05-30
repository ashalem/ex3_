CC=g++
OBJS=HealthPoints.o Queue.o main.o
EXEC=mtmchkin3_test
DEBUG_FLAG= -g
CPPFLAGS=--std=c++11 -Wall -pedantic-errors -Werror -DNDEBUG -g

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(CPPFLAGS) $(OBJS) -o $@


HealthPoints.o: HealthPoints.cpp HealthPoints.h
Queue.o: Queue.cpp Queue.h 
#main.o: main.cpp Mtmchkin.h Card.h

tester : HealthPoints.o Queue.o
	$(CC) $(DEBUG_FLAG) $(CPPFLAGS) HealthPoints.o Queue.o -o $@

clean:
	rm -f $(OBJS) $(EXEC)
