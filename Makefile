CC      = gcc
CFLAGS  = -O
LDFLAGS  = -O 


all: shell1

commandline:  shell1.o
	$(CC) -o $@ $^ $(LDFLAGS)

run: 
	./shell

test: 
	./shell < testfile

clean:
	rm shell


.c.o:
	$(CC)  $(CFLAGS) -c $<

