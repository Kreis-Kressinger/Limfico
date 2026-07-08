# Limfico Guide
- Windows
- Linux
- (macOS: not tested)

### What is Limfico?:

Limfico is a small command line utility that can encrypt files using a key with a XOR algorithm. TThe key should be generated randomly and kept secret. Longer keys are generally provide more secure.
Limfico is lightweight and should run very quickly to encrypt/decrypt even large files.

### Installing Limfico:
prerequisites: gcc, make
1. Clone the repo using ssh or https: 
- https: `git clone https://github.com/Kreis-Kressinger/Limfico.git`  
- ssh: `git clone git@github.com:Kreis-Kressinger/Limfico.git`

2. simply run `make` in it's directory/folder
3. That's all!

*Optional:* Put Limfico in your PATH, so you can access it anywhere.

### Using Limfico:

You either use Limfico with its "menu" (if you can even call it that), or using the command line.

## Command line:

`.\Limfico.exe (flags)`

flag list:
- `-m (mode)` Mode can be either 1(encrypt) or 2(decrypt)
- `-i (name of the input file)`
- `-o (name of the output file)` If the output file doesn't exist, the program will create one for you
- `-k (name of the key file)`
- `-c` *(completely optional.)* Limfico will display all the parameters before beginning its processing. Using `-c` will skip this.

examples (on Windows):

`./Limfico.exe -m 1 -i secret.txt -o encrypted.txt -k key.bin` - encrypt `secret.txt` with `key.txt` into `encrypted.txt`  
`./Limfico.exe -m 2 -i encrypted.txt -o nolongersecret.txt -k key.bin` - decrypt `encrypted.txt` with `key.txt` into `nolongersecret.txt`  
`./Limfico.exe -m 1 -i secret.txt -o encrypted.txt -k key.bin -c` same as the 1st command, but skipping the confirmation step using `-c`

On Linux, you only need to change `.\Limfico.exe` to `.\Limfico`.

## Limfico Menu:

If you do not enter any flags, or only some, then Limfico will ask you for the parameters, so don't worry about forgetting a flag!
