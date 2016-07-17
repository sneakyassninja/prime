LIBINC = $(patsubst lib/%.h,.lib/%.h,$(shell find lib -type f -name *.h))
LIBSRC = $(patsubst lib/%.c,.lib/%.c,$(shell find lib -type f -name *.c))

TSTINC = $(patsubst tst/%.h,.tst/%.h,$(shell find tst -type f -name *.h))
TSTSRC = $(patsubst tst/%.c,.tst/%.c,$(shell find tst -type f -name *.c))

CFLAGS = -std=c11 -D _BSD_SOURCE \
	-Werror -Wall -Wextra -Wpedantic \
	-fdiagnostics-color=auto

.PHONY: all
all: test

.PHONY: test
test: .bin/test
	$<

.PHONY: clean
clean:
	rm -rf .bin .lib .tst

.PHONY: embrace
embrace:
	$(MAKE) -C ext/embrace install

.bin:
	mkdir $@

.lib:
	mkdir $@

.tst:
	mkdir $@

.lib/%.h: lib/%.h | .lib
	cp $< $@

.lib/%.c: lib/%.c | .lib
	embrace $< > $@

.tst/%.h: tst/%.h | .tst
	cp $< $@

.tst/%.c: tst/%.c | .tst
	embrace $< > $@

.bin/test: $(TSTSRC) $(LIBSRC) $(TSTINC) $(LIBINC) | .bin
	$(CC) $(CFLAGS) -lcmocka -llmdb -o $@ $(TSTSRC) $(LIBSRC)
