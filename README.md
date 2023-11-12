# Creating Simple Shell using C Language.

## This simple shell has bash-like features.
1. work in 3 modes interactively, cmd with args or pipe.
2. handel command line arguments.
3. handle EOF/Ctrl + D.
4. search for programs in the PATH env.
5. implement the built-in exit command.
### **Examples**
`./my_shell ls -l -a`

`echo "ls -la" | ./my_shell`

```./my_shell```

#### To compile the code yourself:

```
{
    gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o my_shell -g
}
```