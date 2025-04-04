cc = cc
ldflags = \
	-static \
	-L/usr/local/lib \
	-lm \
	-lX11 \
	-lxcb \
	-lXau \
	-lXdmcp \
	-pthread \
	$(LDFLAGS)
cflags = \
	-g \
	-O3 \
	-std=c11 \
	-I/usr/local/include \
	-Wall \
	-Wwrite-strings \
	-Wextra \
	-Werror \
	-Wpedantic \
	-D_POSIX_C_SOURCE=200809L \
	-D_TIME_BITS=64 \
	-D_FILE_OFFSET_BITS=64 \
	 $(CFLAGS)
src = $(shell find src -name '*.c')
headers = $(shell find src -name '*.h')
lib = $(patsubst src/%,lib/%,$(patsubst %.c,%.o,$(src)))
app = app
bin = bin/$(app)

.PHONY: all run self-test run-examples test clean

all: bin/$(app)

run: bin/$(app)
	./bin/$(app)

test: self-test

self-test: bin/$(app)
	./bin/$(app) self-test

bin/$(app): $(lib) lib/$(app).o
	mkdir -p $(dir $@); $(cc) $^ $(ldflags) -o $@

lib/%.o: src/%.c $(headers)
	mkdir -p $(dir $@); $(cc) -c $(cflags) $< -o $@

clean:
	rm -rf lib bin
