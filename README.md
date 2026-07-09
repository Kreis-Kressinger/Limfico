# Limfico/Limkey Guide


### What is Limfico/Limkey?:
*NOTE: that Limfico/Limkey is NOT supposed to be taken seriously as a cryptographically secure encryption, and should not be used to encrypt ANY confidential data.*


Limfico is a small command line utility that can encrypt files using a key with a XOR algorithm. The key should be generated randomly (using Limkey for example) and kept secret. Longer keys are generally more secure.
Limfico is lightweight and should run very quickly to encrypt/decrypt even large files.

Limfico also comes bundled together with Limkey, a command line utility that can generate keys for Limfico.

### Installing Limfico and Limkey:
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

*Optional:* Put Limfico/Limkey in your PATH, so you can access it anywhere.

If you only want to compile Limfico or Limkey without the other, then you can by entering `make Limfico` and `make Limkey`

## Using Limfico:
Type the command:
- Windows: `.\Limfico.exe (flags...)`
- Linux/Mac: `./Limfico (flags...)`

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


On Linux, you only need to change `.\Limfico.exe` to `./Limfico` for it to function the same way.
And if you put Limfico in your PATH, then you are able to call it anywhere with just the command: `Limfico (flags)` and it will work in the current directory you are in!

## Using Limkey

Type the command:
- Windows: `.\Limkey.exe {key length}`
- Linux/Mac: `./Limkey {key length}`

Limkey will then generate a key with your given key length. The key is named key(random letters).txt.

Limkey supports the maximum key length of *18,446,744,073,709,551,615*.
If you don't give it a key length, it will just close itself.

Again, if you put Limkey in your PATH, then you are able to call it from anywhere just like: `Limkey (key length)` and it will store the key in the directory you are currently in.


