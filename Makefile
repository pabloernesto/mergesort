# CONFIGURATION PARAMETERS

CFLAGS = -std=c99 -Wall -g
CFLAGS += -Isrc

# Use LDFLAGS for options that include libraries
# LDFLAGS = -lGL -lglut -lpng -lz -lm



# FOLDER CRAWLING

# find all sources and derive all object files for compilation
src = $(wildcard src/*.c src/**/*.c)
obj = $(src:.c=.o)
head = $(wildcard src/*.h src/**/*.h)

# find and derive main and non-main files separately, for target likediting
src-main = $(wildcard src/main/*.c)
obj-main = $(src-main:.c=.o)
targets = $(notdir $(src-main:.c=))

src-nmain = $(filter-out $(src-main),$(src))
obj-nmain = $(filter-out $(obj-main),$(obj))



# COMPILATION RULES

.PHONY: all
all: $(targets)

# static pattern rule: specifies pattern-matching only for $(targets)
$(targets) : % : $(obj-nmain) src/main/%.o
	$(CC) -o $@ $^ $(LDFLAGS)

# rule with independent target: add .h files as dependencies .o files
# ie: force recompilation when interfaces change
$(obj) : $(head)

.PHONY: clean
clean:
	rm -f $(obj) $(targets)
