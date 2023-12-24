# Embedded Linux Task 4

## Description 

Objective: You are tasked with developing a static library for the Microcontroller
Abstraction Layer (MCAL) of your AVR drivers. The library, named libmcal.a, is intended to
be used in AVR applications.

## Procedure

1. We need to add AVR compiler to our environment PATH to execute AVR commands so :

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

5. Generate the executable by linking configuration files and static library of MCAL

   ```bash
   avr-gcc -mmcu=atmega32 -o Task1_main.elf Task1_main.o ../MCAL/DIO/DIO_cfg.o ../MCAL/PORT/PORT_cfg.o ../MCAL/libmcal.a 
   ```

   for    ``` -mmcu=atmega32 ``` flag that specify that the which the elf work on is atmega 32 
   
   
   
   ## Advantages of Static Libraries in AVR Applications
   
   ### 1. Resource Efficiency
   
   **Static Linking:** When using a static library, the linker includes only the necessary functions and data directly into the executable during the linking phase. This results in a smaller and more efficient binary since it only contains the code that is essential for the application.
   
   ### 2. Predictable Memory Usage
   
   **Memory Constraints:** AVR microcontrollers often have limited resources, including flash memory and RAM. With static libraries, the memory usage is more predictable, as the linker resolves symbols at compile-time, enabling a clearer understanding of the memory footprint of the application.
   
   ### 3. Reduced Run-Time Overhead
   
   **No Dynamic Loading:** Dynamic libraries incur run-time overhead due to dynamic loading and linking. In embedded systems where real-time performance is critical, avoiding this overhead is beneficial. Static libraries eliminate the need for dynamic loading, resulting in faster startup times.
   
   ### 4. Deterministic Behavior
   
   **Compile-Time Binding:** Static libraries provide compile-time binding of functions, ensuring that the application's behavior is determined at compile-time rather than run-time. This deterministic behavior is desirable in embedded systems where consistency and reliability are crucial.
