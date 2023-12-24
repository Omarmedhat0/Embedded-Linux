# Embedded Linux Task 4

## Description 

Objective: You are tasked with developing a static library for the Microcontroller
Abstraction Layer (MCAL) of your AVR drivers. The library, named libmcal.a, is intended to
be used in AVR applications.

## Procedure

1.  We need to add AVR compiler to our environment PATH to execute AVR commands so :

   1.    Open an editor for ./bashrc

      ```bash
      nano ~/.bashrc
      ```

   2.  Add the PATH of AVR to environment PATH in .bashrc to load every time i open the terminal

      ```bash
      export PATH=$PATH:~/x-tools/avr/bin
      ```

   3. Apply the changes to my current session.

      ```bash
      source .bashrc 
      ```

   4. Confirm that the directory is now in my PATH

      ```bash
      echo $PATH
      ```

   5. Run avr-gcc as now we can run it from any place

      ```bash
      avr-gcc --version
      ```

2. The next step in SOURCE FILE directory which include :

   * LIB
   * MCAL
     * DIO
     * PORT
   * APP

   In DIO we will generate .o file including by common standard libraries and PORT libraries as DIO driver depends on PORT driver

   ```bash
   avr-gcc -c DIO.c -I ../PORT -I ../../LIB -o DIO.o
   ```

   Generate DIO_cfg.o for build it with Task1_main.c file

   ```bash
   avr-gcc -c DIO_cfg.c -I ../PORT -I ../../LIB -o DIO_cfg.o
   ```

   In PORT we will generate .o file by common standard libraries

   ```bash
   avr-gcc -c PORT.c  -I ../../LIB -o PORT.o
   ```
   Generate PORT_cfg.o for build it with Task1_main.c file
   ```bash
   avr-gcc -c PORT_cfg.c -I . -I ../../LIB -o PORT_cfg.o
   ```
   
3. In MCAL directory

   We will make a static library for MCAL drivers

   ```bash
   ar -rcs libmcal.a DIO/DIO.o PORT/PORT.o
   ```

4. In APP directory

   We will generate Task1_main.o to include the header library to symbol table

   ```bash
   avr-gcc -c Task1_main.c -I ../MCAL/DIO/ -I ../MCAL/PORT/ -I ../LIB/
   ```

5. Generate the executable

   ```bash
   avr-gcc -o Task1_main.elf Task1_main.o ../MCAL/DIO/DIO_cfg.o ../MCAL/PORT/PORT_cfg.o ../MCAL/libmcal.a 
   ```

   ​	
