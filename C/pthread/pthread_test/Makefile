TARGETS = pthread
CFLAGS  = -Werror -m64 -g3 -std=c99

$(TARGETS) : $(wildcard *.c)
	$(CC) $(CFLAGS) $^ -o $@ -lpthread

.PHONY : clean
clean:
	rm pthread

