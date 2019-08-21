CC = g++

all: longest_repeat_str

OBJECTS = longest_repeat_str.o

%.o:%.cpp
	$(CC) -c $^ -o $@

longest_repeat_str: $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm *.o
	rm longest_repeat_str

.PHONY: all
.PHONY: clean
