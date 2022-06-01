CC=g++
OBJS=HealthPoints.o HealthPointsExampleTest.o QueueExampleTests.o TestMain.o
EXEC=ex3_test
DEBUG_FLAG= -g
CPPFLAGS=--std=c++11 -Wall -pedantic-errors -Werror -DNDEBUG -g

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(CPPFLAGS) $(OBJS) -o $@

HealthPoints.o: HealthPoints.cpp HealthPoints.h
HealthPointsExampleTest.o: HealthPointsExampleTest.cpp HealthPoints.h
QueueExampleTests.o: QueueExampleTests.cpp Queue.h
TestMain.o: TestMain.cpp

clean:
	rm -f $(OBJS) $(EXEC)
