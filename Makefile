objects = basics ex1 ex1-4

.PHONY: all
all: $(objects)

# Compilation
$(objects): %: %.c
	gcc -Wall -o $@ $<

# Clean up
.PHONY: clean
clean:
	-rm $(objects)
