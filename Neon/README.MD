# NEON DOCUMENTATION

## WHAT IS NEON AND WHY NEON ?
**1st. Neon is a very fast and easy to use  Mason to file rift parser that uses `C++` for super fast parsing of mason format. It also supports both Android and Windows**
**2nd. Not only that but also allows input in any type of format that (other than object name and identifier those are always the first 2 in the input)**

*SYNTAX EXAMPLE*
```
#THIS IS A COMMENT AND IS IGNORED WHEN PARSING
platformwood0 plat#1 x100 y50 z0 r0 s1
#ANY FORMAT WORKS!
platformwood0 plat#2 y100 r0 s1 z0 x500

#First Two tokens will always be object name or identifier!
#x30 y20 platformwood0 z0 r0 s1
#THIS IS INCORRECT! , x30 and y20 will be use for the object name and identifier !
```
## INSTALLATION
**Using Neon is pretty straightforward**
**1st. Download the latest release of Neon**
**2nd. Depending on your `OS` lets walk through the process of using NEON**

## USING NEON
### Android:
1st. Download/Install a CPP compiler / APPLICATION, I recommend
`Coding C++` app.
2nd. Open the the `Neon.cpp` located in the`build` folder.
3rd. Create a `.txt` in the same folder and run the `Neon.cpp` file it will ask to `Enter the filename` and enter whatever is your .txt file name.
Done! Now lets learn the Mason script!

### Windows :
1st. Create a `.txt` in the `build` folder and run the `Neon.exe` file it will ask to `Enter the filename` and enter whatever is your .txt file name.
Done! Now lets learn the Mason script!

## MASON SCRIPT
**As you read the format for the obj data can be in any order**
**The script is pretty straightforward**
##### USE '#' for comments these are ignored by the lexer
```
# THIS IS A COMMENT
```

##### Creating a platform
```
platformwood0 plat#1 x100 y50 z0 r0 s1
```
**Here `platformwood0` is the Object Name for the wooden platform and `plat#1` is its identifier , `x100,y50,z0`is the position data of the object and `r` is for the rotation and `s` is for the scale
### Here  is a more different example
```
platformwood0 platform11 z0 y500 r90 s2 x1250
```
### Well congrats you can now use Neon with its fullest potential!!! 