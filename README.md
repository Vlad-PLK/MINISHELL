<a id="readme-top" name="readme-top"></a>

<!-- ------------------------------
* TITLE, DESCRIPTION & CONTACT
------------------------------ -->
<h1 align="center">📟 minishell</h1>

<table>
    <tr>
        <th align="left" width="3333px">Score</th>
        <th align="left" width="3333px">Duration</th>
        <th align="left" width="3333px">Peer(s)</th>
    </tr>
    <tr>
        <td>✅ <b>125</b> / 100</td>
        <td>🕓 8 week(s)</td>
        <td>👷🏻 Yes</td>
    </tr>
</table>

<br>

This team project is a program that reproduces the `bash` shell. It includes **prompt**, **persistent history**, several **builtins**, full support for **quotes** (double and single), **redirections and piping**, **shell variables** and **environment variables** and their expansion, **signal processing**, support for **logical operators**, **subshells** and **wildcards**.

<br>

<!-- ------------------------------
* TABLE OF CONTENTS
------------------------------ -->
## 📋 Table of contents

- [**👀 Overview**](#readme-overview)
- [**📦 Requirements**](#readme-requirements)
- [**💾 Installation**](#readme-installation)
- [**⚡️ Usage**](#readme-usage)
- [**🛠️ Makefile**](#readme-makefile)
- [**📄 License**](#readme-license)

<a id="readme-overview" name="readme-overview"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* OVERVIEW
------------------------------ -->
## 👀 Overview

### General

- Display a prompt while waiting for an input.
- Search order for binaries identical to `bash`.
- Executes the correct binaries.

### History

- Supports session history.
- Supports **persistent** history (file storage).

### Builtins

- Implements builtins `echo`, `cd`, `pwd`, `export`, `unset`, `env` and `exit`.

### Quotes

- Supports simple quotes `''` and  double quotes `""`.
- Supports **unclosed** double quotes.
- Supports **unclosed** simple quotes.

### Redirections

- Supports pipe `|` redirections.
- Supports `<`, `>` and `>>` file redirections.
- Supports heredoc `<<` redirections.
- Supports herestring `<<<` redirections.

### Variables

- Supports environment variables.
- Supports shell variables.
- Shell variables can be exported with `export`.
- Supports variable `$?`.

### Signals

- Supports signals `CTRL-C`, `CTRL-D` and `CTRL-\` in passive and interactive mode.

### Operators

- Supports logical operators `&&` and `||`.


### Subshell

- Supports the execution of **subshells** in parentheses `()`.

### Delimiters

- Supports token `;` as delimiter.
- Supports **incomplete lines** ending with `|`, `&&` or `||`.

### Wildcard

- Supports wildcard `*` in **the basename of any absolute or relative path**.

### Comments

- Supports inline comments with token `#`.

<a id="readme-requirements" name="readme-requirements"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* REQUIREMENTS
------------------------------ -->
## 📦 Requirements

```
sudo apt -y install clang-12 make libreadline-dev
```

<a id="readme-installation" name="readme-installation"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* INSTALLATION
------------------------------ -->
## 💾 Installation

**1. Get the project**

```
git clone https://github.com/Vlad-PLK/MINISHELL.git
```

<br>

**2. Build the project**

```
make -j$(nproc)
```

> **🔵 Info:** The `minishell` executable will be created in the project root directory.

<br>

**3. Run the project**

```
./minishell
```

<a id="readme-usage" name="readme-usage"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* USAGE
------------------------------ -->
## ⚡️ Usage

**Double quotes:**

```console
minishell$ echo "Like a shell: $SHELL"
Like a shell: 42-minishell/minishell
```

<br>

**Simple quotes:**

```console
minishell$ echo 'Like a shell: $SHELL'
Like a shell: $SHELL
```

<br>

**Unclosed quotes:**

```console
minishell$ echo "Hello 
> world!"
Hello 
world!
```

<br>

**Pipe redirection:**

```console
minishell$ echo "Hello world!" | cat --number
     1  Hello world!
```

<br>

**File redirection:**

```console
minishell$ echo "Hello world #1" > a.txt
minishell$ echo "Hello world #2" >> a.txt
minishell$ cat --number < a.txt
     1  Hello world #1
     2  Hello world #2
```

<br>

**Heredoc:**

```console
minishell$ cat << DEL
> Hello
> world!
> DEL
Hello 
world!
```

<br>

**Herestring:**

```console
minishell$ cat <<< "Hello world!\n"
Hello world!
```

<br>

**Environment variables:**

```console
minishell$ export A="Hello world!"; echo $A
Hello world!
```

<br>

**Shell variables:**

```console
minishell$ A="Hello world!"; echo $A
Hello world!
```

<br>

**Logical operators:**

```console
minishell$ echo "A" && echo "B" || echo "C" && echo "D"
A
B
D
```

<br>

**Subshell:**

```console
minishell$ echo "A" && echo "B" || (echo "C" && echo "D")
A
B
```

<br>

**Delimiters:**

```console
minishell$ echo Hello; echo world!
Hello
world!
```

<br>

**Incomplete lines:**

```console
minishell$ echo "Hello world!" |
> wc -w
2
```

```console
minishell$ echo -n "Hello " &&
> echo "world!"
Hello world!
```

```console
minishell$ echo "Hello " ||
> echo "world!"
Hello
```

<br>

**Wildcards:**

```console
minishell$ echo includes/m*.h
includes/minishell.h
```

<br>

**Comments:**

```console
minishell$ echo "Hello world!" # It's an inline comments!
Hello world!
```

<a id="readme-makefile" name="readme-makefile"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* MAKEFILE
------------------------------ -->
## 🛠️ Makefile

<table>
    <tr>
        <th align="left" width="500px">Rule</th>
        <th align="left" width="9500px">Action</th>
        </tr>
    <tr><td><code>all</code></td><td>Compile.</td></tr>
    <tr><td><code>clean</code></td><td>Delete all generated object files</td></tr>
    <tr><td><code>fclean</code></td><td>Apply <code>clean</code>, <code>lclean</code>and delete the executable.</td></tr>
    <tr><td><code>lclean</code></td><td>Apply <code>fclean</code> to all used libraries.</td></tr>
    <tr><td><code>re</code></td><td>Apply <code>fclean</code> and force recompile.</td></tr>
</table>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>
