# ft_printf

ft_printf is a project developed for 42 Heilbroon School.

## Keywords
C programming - variadic functions - printf - stdio.h - stdarg.h

## Subject
Re-implement the printf function from the `stdio` C library. The function handles the basic funcionalities and conversion specifiers.

## Brief Explanation
The goal of the project is re-create the standard printf function, to understand how internally works and use it in the future projects of 42 Heilbronn school.

An important part of the project is to understand how [variadic functions](https://en.cppreference.com/w/c/variadic) work. To implement the function is therefore necessary to include `stdarg` library, using its types and macros.

## How to Use
1. Clone the repository inside your project:
```
git clone git@github.com:NicoCastelnuovo/ft_printf.git ft_printf
```

2. Navigate to the `ft_printf` directory and `make` the library:
```
cd ft_printf
make
```

3. Include the header inside your .c file:
```
#include "ft_printf.h"
```

4. Compile your executable:
```
cc <your_main.c> ./ft_printf/libftprintf.a -I ./ft_printf/include/ -o <custom_name>
```
5. Enjoy!

**NOTE**

ft_printf is part of `mylib`, a personal collection of libraries and functions used in the 42 Heilbronn projects. [Check it out!](https://github.com/NicoCastelnuovo/mylib)
