# Pipex

Pipex is a project that replicates the behavior of the Unix shell pipe (`|`). It allows you to connect the output of one command to the input of another, simulating the functionality of pipes in a shell environment.

## Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Usage](#usage)
- [Installation](#installation)
- [Examples](#examples)
- [License](#license)

## Overview

The goal of this project is to deepen your understanding of process creation, file descriptors, and inter-process communication in Unix-like systems. Pipex is implemented in C and adheres to the principles of the Unix philosophy.

## Features

- Executes two commands connected by a pipe.
- Handles input and output redirection.
- Mimics the behavior of the shell for simple pipelines.

## Usage

```bash
./pipex file1 "cmd1" "cmd2" file2
```

- `file1`: Input file.
- `cmd1`: First command to execute.
- `cmd2`: Second command to execute.
- `file2`: Output file.

The program redirects the output of `cmd1` to the input of `cmd2`, with `file1` as the input and `file2` as the output.

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

### Example 1
```bash
./pipex infile "cat" "wc -l" outfile
```
This command reads from `infile`, passes the output of `cat` to `wc -l`, and writes the result to `outfile`.

### Example 2
```bash
./pipex input.txt "grep foo" "sort" output.txt
```
This command filters lines containing "foo" from `input.txt`, sorts them, and writes the result to `output.txt`.

<!-- ## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details. -->