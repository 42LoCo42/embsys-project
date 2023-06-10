CC := armcl

BASEDIR := $(dir $(lastword $(MAKEFILE_LIST)))
SUPPORT := $(BASEDIR)/support
SOURCES := $(shell find $(SRCDIR) $(SUPPORT) -name '*.c' -or -name '*.asm')

CFLAGS := \
	-me -mv 7M4 \
	-D __MSP432P401R__ \
	--code_state=16 \
	--float_support=FPv4SPD16 \
	-I $(SUPPORT) \
	-I $(ARM_CGT)/include \
	$(shell find $(SRCDIR) -type d -exec echo -I {} \;) \

LDFLAGS := \
	-i $(ARM_CGT)/lib \
	$(SUPPORT)/msp432p401r.cmd \

.PHONY: run
run: $(TARGET)
	$(BASEDIR)/run $<

.PHONY: clean
clean:
	rm -f *.obj

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $^ -z $(LDFLAGS) -o $@
	armstrip -p $@
	make clean
