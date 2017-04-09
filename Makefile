CC      = gcc
CFLAGS  = -O
LDFLAGS  = -O 


all: commandline

commandline:  commandline.o
	$(CC) -o $@ $^ $(LDFLAGS)

run: 
	./commandline

test: 
	./commandline < testfile

clean:
	rm commandline


.c.o:
	$(CC)  $(CFLAGS) -c $<

