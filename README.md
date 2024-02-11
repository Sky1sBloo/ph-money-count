# ph-money-count
Generates a report that tells the count of each denomination.

# Usage
```
--help
```
 For list of commands
```
--denomination [amount]
```
to get the count of each denomination.
```
--test
```
To run unit tests

# Build
## Using cmake
1. Generate cmake files
```
cmake ./
```

2. Build make files
```
make
```

## Using gcc
1. Compile all source files
```
gcc main.c ph-input.c ph-denomination.c test.c
```
2. Run application
```
./a.out
```
