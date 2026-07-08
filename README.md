# Limfico Guide
prerequisites: gcc, make

### Installing Limfico:

1. Clone the repo using ssh or https: 

- https: `git clone https://github.com/Kreis-Kressinger/Limfico.git`  
- ssh: `git clone git@github.com:Kreis-Kressinger/Limfico.git`

2. simply run `make`
3. That's all!

### Using Limfico:

You either use Limfico with it's "menu" (if you can even call it that), or using the command line.

## Command line:

`.\Limfico.exe (flags)`

flag list:
- `-m (mode)` Mode can be either 1(encrypt) or 2(decrypt)
- `-i (name of the input file)`
- `-o (name of the output file)` If the output file doesn't exist, the program will create one for you
- `-k (name of the key file)`
- `-c` *(completely optional.)* Limfico will display all the parameters before beginning it's processing. Using `-c` will skip this.

## Limfico Menu:

If you do not enter any flags, or only some, then Limfico will ask you for the parameters, so don't worry about forgetting a flag!
