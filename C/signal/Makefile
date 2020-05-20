TARGETS = my_signal
CFLAGS  = -m64 -g3 -std=c11

$(TARGETS) : $(wildcard *.c)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY : clean
clean:
	rm $(TARGETS)

