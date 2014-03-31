OBJS = triangle.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

triangle : $(OBJS)
	    $(CC) $(LFLAGS) $(OBJS) -o triangle

triangle.o : triangle.h triangle.cpp 
	    $(CC) $(CFLAGS) triangle.cpp

clean:
	    \rm *.o *~ triangle
