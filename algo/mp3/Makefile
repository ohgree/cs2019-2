# Flags: C11 standard
CFLAGS += -std=c11
# Libmath
LIBS += -lm

# making the executable from object file
mp3_20161603: mp3_20161603.o
	$(CC) $(CFLAGS) mp3_20161603.o -o mp3_20161603 $(LIBS)

# an object file is made from one source code
mp3_20161603.o: mp3_20161603.c
	$(CC) $(CFLAGS) -c mp3_20161603.c

clean:
	rm mp3_20161603 mp3_20161603.o
