#makefile

PROGRAM = main.exe
SRC = main.c lrndata.c wdata.c lrnproc.c rnd.c ae1.c
OBJS = $(SRC:%.c=%.o)
CC = gcc

$(PROGRAM): $(OBJS)
	$(CC) -o $(PROGRAM) $(OBJS)

.c.o:
	$(CC) -c $<

clean:
	rm -f $(PROGRAM) $(OBJS)

