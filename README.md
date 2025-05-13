# Pipex

Pipex is a project that replicates the behavior of the Unix shell pipe (`|`). It allows you to connect the output of one command to the input of another, simulating the functionality of pipes in a shell environment.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
  - [Mandatory Part](#mandatory-part)
  - [Bonus Part](#bonus-part)
- [Installation](#installation)
- [Examples](#examples)
  - [Mandatory Examples](#mandatory-examples)
  - [Bonus Examples](#bonus-examples)
- [Requirements](#requirements)
- [License](#license)

## Overview

The goal of this project is to deepen your understanding of process creation, file descriptors, and inter-process communication in Unix-like systems. Pipex is implemented in C and adheres to the principles of the Unix philosophy.

## Features

- Executes commands connected by a pipe.
- Handles input and output redirection.
- Mimics the behavior of the shell for simple pipelines.
- Bonus: Supports multiple commands and "here document" functionality.

## Usage

### Mandatory Part

```bash
./pipex file1 "cmd1" "cmd2" file2
```

- `file1`: Input file.
- `cmd1`: First command to execute.
- `cmd2`: Second command to execute.
- `file2`: Output file.

The program redirects the output of `cmd1` to the input of `cmd2`, with `file1` as the input and `file2` as the output.

### Bonus Part

#### Chained Commands
```bash
./pipex file1 "cmd1" "cmd2" "cmd3" file2
```

This extends the mandatory functionality to support an arbitrary number of commands connected by pipes.

#### Here Document
```bash
./pipex here_doc DELIMITER "cmd1" "cmd2" file2
```

This functionality allows input to be provided directly from the command line until a specified `DELIMITER` is encountered.

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/noreddine1/pipex.git
    ```
2. Navigate to the project directory:
    ```bash
    cd pipex
    ```
3. Build the project:
    ```bash
    make
    ```

## Examples

### Mandatory Examples

#### Example 1
```bash
./pipex infile "cat" "wc -l" outfile
```
- Reads from `infile`.
- Passes the output of `cat` to `wc -l`.
- Writes the result to `outfile`.

#### Example 2
```bash
./pipex input.txt "grep foo" "sort" output.txt
```
- Filters lines containing "foo" from `input.txt`.
- Sorts them.
- Writes the result to `output.txt`.

### Bonus Examples

#### Chained Commands
```bash
./pipex file1 "ls -l" "grep txt" "wc -l" file2
```
- Reads from `file1`.
- Executes `ls -l`, pipes the output to `grep txt`, and then to `wc -l`.
- Writes the result to `file2`.

#### Here Document
```bash
./pipex here_doc END "cat" "wc -w" output.txt
```
- Reads input from the command line until `END` is encountered.
- Pipes the input to `cat`, then to `wc -w`.
- Writes the result to `output.txt`.

## Requirements

- **Mandatory Part**:
  - Execute two commands connected by a pipe.
  - Handle input and output redirection.
- **Bonus Part**:
  - Support multiple commands connected by pipes.
  - Implement "here document" functionality.
- **General**:
  - Written in C.
  - Use only allowed functions as specified in the project guidelines.
  - Properly handle errors (e.g., invalid arguments, file access issues, command execution failures).
  - Ensure memory and resource management to avoid leaks or dangling file descriptors.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.