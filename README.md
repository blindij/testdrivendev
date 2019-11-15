# TDDbyexample

[![Build Status](https://travis-ci.com/blindij/TestDrivenDevbyExample.svg?branch=master)](https://travis-ci.com/blindij/TestDrivenDevbyExample)

A C++ project using CMake

## Building From Source

First make sure that you have a C++ compiler and CMake installed. Clone the repo and install with CMake:

```bash
git clone --recursive https://github.com/blindij/TestDrivenDevbyExample.git
cd TestDrivenDevbyExample
mkdir build
cd build
cmake ..
make
```

To build the documentation, you can invoke the `docs` make target:

```bash
make docs
```

## Running unit tests

One can run unit tests by building with the `TESTS` variable

```bash
mkdir build
cd build
cmake -DTESTS=TRUE ..
make
make test
```

## Our to-do-list
  * USD5 + 10 CHF = USD10 if rate is 2:1
  * __USD 5 * 2 = USD 10_
  * Make "amount" private
  * Dollar side-effects?
  * Money rounding?
