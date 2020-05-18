TARGETS = my_klib
CFLAGS  = -Werror -m64 -g3 -std=c11

$(TARGETS) : $(wildcard *.c)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY : clean
clean:
	rm $(TARGETS)

