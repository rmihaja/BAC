BAC - Book A Classroom
======

This is the source code of our data structure project for the 4th semester of CUPGE.
For more information and a user guide, head over to our [documentation](docs/README.md).

# Getting started

Before running the program, you must install all external dependencies needed by the project with :

```bash
make install
```

> **Note**
> This program will install [jansson](https://github.com/akheron/jansson) library to your system thus require super user authorization.

It is advised to check all the unit tests of model library in case something went wrong during the installation. To do so, type :

```bash
make tests
```

To start the project, just open your terminal and type :

```bash
make
```

This will automatically compile all the files needed by the program then executes it.

However if you want a more detailed step, this command first compile all the librairies with :

```bash
make init
```

Then compile and run the `app` program with :

```bash
make start
```

However, if you want a debug version of the program, type :

```bash
make debug
```

If you want to remove all the clutter the script did and start from fresh, type :

```bash
make prune
```

# Debugging

The model library have unit tests if you want to check in. To start one, type :

```bash
make test/model/{name-of-file-without-extension}
```

>Example : `make test/model/enseignant` to run enseignant.c unit tests

# About

© 2022 Mihaja RAZAFIMAHEFA & Ambre ROUZADE
