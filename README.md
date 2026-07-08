# Limfico Guide


### What is Limfico?:
*NOTE: that Limfico is NOT supposed to be taken seriously as a cryptographically secure encryption, and should not be used to encrypt ANY confidential data.*


Limfico is a small command line utility that can encrypt files using a key with a XOR algorithm. The key should be generated randomly and kept secret. Longer keys are generally more secure.
Limfico is lightweight and should run very quickly to encrypt/decrypt even large files.

### Installing Limfico:
supported platforms:
- Windows
- Linux
- (macOS: likely, but not tested)

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

- Windows: `.\Limfico.exe (flags)`
- Linux/Mac: `./Limfico (flags)`

flag list:
- `-m (mode)` Mode can be either 1(encrypt) or 2(decrypt)
- `-i (name of the input file)`
- `-o (name of the output file)` If the output file doesn't exist, the program will create one for you
- `-k (name of the key file)`
- `-c` *(completely optional.)* Limfico will skip the confirmation step.

examples (on Windows):

`.\Limfico.exe -m 1 -i secret.txt -o encrypted.txt -k key.bin`: This encrypts `secret.txt` with `key.txt` into `encrypted.txt`.
`.\Limfico.exe -m 2 -i encrypted.txt -o nolongersecret.txt -k key.bin`: This decrypts `encrypted.txt` with `key.txt` into `nolongersecret.txt`.
`.\Limfico.exe -m 1 -i secret.txt -o encrypted.txt -k key.bin -c`: Same as the 1st command, but skipping the confirmation step using `-c`.

On Linux, you only need to change `.\Limfico.exe` to `./Limfico`.

## Limfico Menu:

If you do not enter any flags, or only some, then Limfico will ask you for the missing parameters, so don't worry about forgetting a flag!
