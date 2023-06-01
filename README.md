# Simple Shell

This is a simple implementation of a Unix shell in C. It provides basic shell functionality such as executing commands, handling signals, and running pipelines.

## Installation
To compile the shell, run the following command in your terminal:
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
This will compile all the source files and generate an executable file named `hsh`.

## Usage
To start the shell, run the following command:
`./hsh`

You will then be presented with a prompt (`#cisfun$ `), indicating that the shell is ready to accept your commands. You can then enter commands just as you would in a regular terminal.

Here are some examples of commands you can run:
- $ ls
- $ pwd
- $ echo "Hello, world!"
- $ cd /path/to/directory
- $ exit

## Features
Here are some features of the shell:

* Built-in commands: cd, env, exit
* Signal handling: handles SIGINT (Ctrl-C) and SIGQUIT (Ctrl-) signals
* Pipes: allows for running commands in pipelines, e.g. `ls | wc -l`
