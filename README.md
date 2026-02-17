# Vet-Cstem

A veterinary management system built in **pure C**, focused on:

-   Layered architecture
-   Database persistence
-   Manual memory management
-   Protection against classic C errors

------------------------------------------------------------------------

## About the Project

**Vet-Cstem** is a terminal-based veterinary management system that
allows:

-   Animal registration
-   Updating animal information
-   Listing registered records

The project was designed as an advanced C learning exercise, covering:

-   Direct use of the MySQL C API (`libmysqlclient`)
-   Pointer manipulation
-   Dynamic memory allocation
-   Modular architecture (`.h` / `.c`)
-   Structured error handling

------------------------------------------------------------------------

## Data Persistence (MySQL)

One of the main highlights of this project is that data is **not stored
only in memory**.

The system connects directly to MySQL using the native C API, providing:

-   Permanent data storage
-   `SELECT` queries
-   `INSERT` operations
-   `UPDATE` operations
-   Database-layer error handling

This makes the project a real system with robust persistence.

------------------------------------------------------------------------

## Secure Input --- Custom `<input.h>` Library

The project includes a custom-built library:

    <input.h>

This library was created to solve one of C's most dangerous problems:

> Buffer overflow during user input

It provides safe functions for:

-   Controlled string reading
-   Explicit size limitation
-   Safe integer conversion
-   Input validation

This avoids unsafe standard functions such as:

    gets()
    scanf("%s")

The approach significantly increases system security and robustness.

------------------------------------------------------------------------
### Layers

-   `main.c` → Interface and system flow
-   `persistence.*` → Database access layer
-   `input.*` → Custom secure input library

------------------------------------------------------------------------

## Compilation

Linux example using GCC:
    gcc main.c persistence.c input.c -o vet-cstem -lmysqlclient -I/usr/include/mysql

Or just use the makefile LOL
------------------------------------------------------------------------

## Running the Application

    ./main

------------------------------------------------------------------------

## Concepts Applied

-   Pointers and dynamic allocation
-   Error handling via return codes
-   Safe string manipulation
-   Database integration
-   Debugging with `gdb` and `valgrind`

------------------------------------------------------------------------

## Project Purpose

Vet-Cstem was developed as a deep dive into the C language, going beyond
basics:

-   No frameworks
-   No automatic abstractions
-   Full control over memory
-   Direct database integration

It is designed for developers who want to truly understand low-level
programming and how real systems work behind modern abstractions.

------------------------------------------------------------------------

## Author

Developed as part of advanced studies in C programming, system
architecture, and database integration.
