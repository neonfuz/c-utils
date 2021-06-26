all: shufcase ytshuf

shufcase: shufcase.c
	$(CC) $(CFLAGS) -o $@ $?

ytshuf: ytshuf.c
	$(CC) $(CFLAGS) -o $@ $?

clean:
	rm -f shufcase ytshuf

.PHONY: all clean
