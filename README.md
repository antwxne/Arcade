# Arcade

>Arcade is a gaming platform: a program that lets the user choose a game to play and keeps a register of
player scores.
To be able to deal with the elements of your gaming plate-
form at run-time, your graphics libraries and your games
must be implemented as dynamic libraries, loaded at run-
time.

We used the _SFML_, _SDL2_ and _ncurses_ graphical libraries.

<p align="center">
  <a href="https://www.sfml-dev.org/index.php">
    <img src=".github/readme_resources/Logos/logo_sfml.png" width="288px">
  </a>
</p>
<p align="center">
  <a href="https://github.com/SFML/CSFML/releases/tag/2.5">
    <img src="https://img.shields.io/github/v/release/SFML/SFML?label=SFML%20Version&style=for-the-badge">
  </a>
</p>

<h2>Previews</h2>
<details>
<summary>Pacman</summary>
    <details>
        <summary>SFML</summary>
        <img src="/.github/readme_resources/previews/pacman_sfml.png">
    </details>
    <details>
        <summary>SDL2</summary>
        <img src="/.github/readme_resources/previews/pacman_sdl.png">
    </details>
    <details>
        <summary>Ncurses</summary>
        <img src="/.github/readme_resources/previews/pacman_ncurses.png">
    </details>
</details>
<details>
    <summary>Nibbler</summary>
    <details>
        <summary>SFML</summary>
        <img src="/.github/readme_resources/previews/nibbler_sfml.png">
    </details>
    <details>
        <summary>SDL2</summary>
        <img src="/.github/readme_resources/previews/nibbler_sdl.png">
    </details>
    <details>
        <summary>Ncurses</summary>
        <img src="/.github/readme_resources/previews/nibbler_ncurses.png">
    </details>
</details>

## Requirements

### SFML >= 2.5

To install SFML please refer to the [installation guide](https://www.sfml-dev.org/download/sfml/2.5.1/index-fr.php)

### SDL2

To install SDL2 please refer to the [installation guide](https://www.libsdl.org/download-2.0.php)


### Ncurses

To install ncurses library please refer to the [installation guide](https://invisible-island.net/ncurses/)

## Build and run

Linux:

```sh
make
./arcade ./lib/(first graphical lib to be loaded).so
```

## Documentation

> Make sure that you have [_Doxygen_](https://www.doxygen.nl/download.html) installed

```shell
make doc
```

File are generated in _./Documentation_ folder.

> If you have _Firefox_ you can run:

```shell
make doc-firefox
```

It generate documentation and launch a html preview.

## Contributors

- Théo Campos [![github-link][github-logo]](https://github.com/theocampos)
- Clément Ruat  [![github-link][github-logo]](https://github.com/fantoruse)
- Antoine Desruet [![github-link][github-logo]](https://github.com/antwxne)

<!-- Markdown link & img definition's -->

[Github-logo]: https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white
