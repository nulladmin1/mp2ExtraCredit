# MP2 Extra Credit (C++)

## Run

### Nix

```bash
nix run
```

### CMake

- Make a temporary `build/` directory

  ```bash
  mkdir build/
  ```

- Go into the temporary directory

  ```bash
  cd build/
  ```
- Make the `Makefile` and other stuff needed for `make` using `CMake`

  ```bash
  cmake ..
  ```

- Run `make` to build the project

  ```bash
  make
  ```
- Run the `mp2ec` program

  ```bash
  ./src/mp2ec
  ```