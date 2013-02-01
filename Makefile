objects = basics ex1 ex1-4

.PHONY: all
all: $(objects)

# Compilation
$(objects): %: %.c
	gcc -Wall -o $@ $<

# Assembly
.PHONY: %.s
%.s: %.c
	gcc -Wall -S -fverbose-asm -c -o- $<

.PHONY: asm
asm: $(addsuffix .s,$(objects))

# Clean up
.PHONY: clean
clean:
	-rm $(objects)
