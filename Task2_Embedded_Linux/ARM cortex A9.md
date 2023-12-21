# ARM cortex A9

After Installing arm-cortexa9_neon-linux-musleabihf Compiler from crosstool ng we can notice that an x-tools file has been created in our Home directory it contains some files as below :

* x-tools
  * **arm-cortexa9_neon-linux-musleabihf**
    * **arm-cortexa9_neon-linux-musleabihf**
      * **sysroot**
        * *usr*
          * lib
          * usr
          * bin
        * *lib*
      * **bin**

------



## Sysroot 

In the context of ARM development, a sysroot refers to the system root directory that contains the essential files and libraries needed for cross-compiling and building software for a target ARM architecture. The sysroot provides a isolated environment that mirrors the target system's file structure and includes the necessary headers, libraries, and other resources It contains : 

### usr/lib

It contains important static and dynamic libraries that user will use it or add new libraries on it

### usr/bin

It contains binray files for applications that will be used on the target

### usr/include

It contains header files of the libraries that will be used 

### lib

It contains system libraries like spin

------



## bin

It contains all important Binutils  as , Binutils is a collection of binary utility tools that are essential for the development and manipulation of binary files, including executable programs and object files. These tools are crucial in the compilation, linking, and debugging stages of software development. 

Components of Binutils:

- ar
- as
- ld
- objcopy
- objdump
- strip
- nm
- ranlib
- readelf

------

