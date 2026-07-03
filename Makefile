CC = gcc
CFLAGS = -g -Wall -std=c99 -fPIC
CCLINK = gcc
OBJS = main.o student.o stack.o
EXEC = prog.exe

# Target for the executable
$(EXEC): $(OBJS)
	$(CCLINK) $(OBJS) -o $(EXEC)

# Rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Shared Libraries
linked-list.o: linked-list.c linked-list.h
	$(CC) $(CFLAGS) -c linked-list.c -o linked-list.o

liblinked-list.so: linked-list.o
	$(CCLINK) -shared linked-list.o -o liblinked-list.so

grades.o: grades.c grades.h
	$(CC) $(CFLAGS) -c grades.c -o grades.o

libgrades.so: grades.o liblinked-list.so
	$(CCLINK) -shared -o libgrades.so grades.o -L. -llinked-list

clean:
	rm -f *.o *.so $(EXEC)
