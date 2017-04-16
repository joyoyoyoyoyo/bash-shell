CC      = gcc
CFLAGS  = -O
LDFLAGS  = -O 


all: shell

commandline:  shell.o
	$(CC) -o $@ $^ $(LDFLAGS)

run: 
	./shell

test: 
	./shell < testfile

clean:
	rm shell


.c.o:
	$(CC)  $(CFLAGS) -c $<

