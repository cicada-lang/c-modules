# C Modules

Our C project template, to fight [blank page syndrome](https://hintjens.gitbooks.io/scalable-c/content/chapter2.html).

## Install

Dependencies:

- `libx11`:
  - debian: `sudo apt install libx11-dev`
  - ubuntu: `sudo apt install libx11-dev`

Compile:

```
git clone https://github.com/cicada-lang/c-modules
cd c-modules
make -j
make test
```

The compiled binary `./bin/app` is the command-line program.

## Development

```shell
make -j       # compile src/ files to lib/ and bin/
make run      # compile and run the command-line program
make test     # compile and run test
make clean    # clean up compiled files
```

Using [tsan (ThreadSanitizer)](https://github.com/google/sanitizers/wiki/threadsanitizercppmanual)
to test data race in parallel program:

```shell
LDFLAGS=-fsanitize=thread CFLAGS=-fsanitize=thread make -j
make self-test
```

## References

**Inspirations**:

- [uxn](https://100r.co/site/uxn.html)

**Books**:

- [scalable c](https://github.com/booksbyus/scalable-c)

## Contributions

To make a contribution, fork this project and create a pull request.

Please read the [STYLE-GUIDE.md](STYLE-GUIDE.md) before you change the code.

Remember to add yourself to [AUTHORS](AUTHORS).
Your line belongs to you, you can write a little
introduction to yourself but not too long.

## License

[GPLv3](LICENSE)
