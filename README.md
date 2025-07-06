# Libasm

A small 64-bit assembly project to reimplement standard C functions using NASM, focusing on learning low-level programming, syscall behavior, and proper errno handling.

## Implemented Functions

| Function      | Description                                 |
|---------------|---------------------------------------------|
| `ft_strlen`   | Returns the length of a string              |
| `ft_strcpy`   | Copies a string into a destination buffer   |
| `ft_strcmp`   | Compares two strings                        |
| `ft_write`    | Writes data to a file descriptor            |
| `ft_read`     | Reads data from a file descriptor           |
| `ft_strdup`   | Duplicates a string using malloc            |

All functions aim to replicate the behavior of the standard C functions.

## Project Structure

```
.
├── srcs/
│   ├── ft_strlen.s
│   ├── ft_strcpy.s
│   ├── ft_strcmp.s
│   ├── ft_write.s
│   ├── ft_read.s
│   └── ft_strdup.s
├── test/
│   ├── main.c
│   └── libasm.h
├── Makefile
├── README.md
```

## Compile and run tests

To compile the library:

```bash
make
```

To run the tests:

```bash
make run
```
