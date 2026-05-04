# tcp_client.c

> Create socket

## Overview

- **File:** `16-network-programming/tcp_client.c`
- **Language:** C source
- **Module:** `16-network-programming`
- **Lines:** 71
- **Libraries:** `stdio.h`, `stdlib.h`, `string.h`, `unistd.h`, `arpa/inet.h`

## Concepts

- Standard I/O: `printf`, `scanf` for console input/output
- Standard library: memory allocation (`malloc`/`free`), conversions (`atoi`), exit codes
- String manipulation: `strlen`, `strcpy`, `strcmp`, `strcat`
- Structures: defining structs, member access (`.`/`->`), nested structs
- Memory layout analysis using `sizeof` operator

## Compilation

```bash
cd 16-network-programming
gcc tcp_client.c -o tcp_client -std=c11 -Wall -Wextra
./tcp_client
```
