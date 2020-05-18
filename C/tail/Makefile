TARGETS = my_tail
CFLAGS  = -std=c11

$(TARGETS) : $(wildcard *.c)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY : clean
clean:
	rm $(TARGETS)

