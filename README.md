# arduino-stm32-xdr-rpc

-- Code still in development / proof of concept --

XDR/RPC protocol for Arduino STM32Core based on the Sun Microsystems XDR/RPC Source Code (Sun RPC).

Tested with the Arduino 1.8.13 IDE, STMCore lib for a STM32F405 MCU as a proof of concept.

## Purpose

I did not find any clear implementation of XDR/RPC with Arduino, etc. (compile with an arm g++ compiler).
Mostly used with Ethernet applications in OS (e.g. NFS), I can see XDR of great interest as a data packing layer in order to unify transport communication (pack and stream) between devices but also to unify the storing of data (pack and stream) in small memory devices (e.g. parameters, data log) and keep fast performance (probably one of the fastest data packer).

The source codes are adapted from `portablexdr-4.9.1` (https://github.com/Alexpux/portablexdr) and `bsd-xdr-master` (https://github.com/woodfishman/bsd-xdr).
A `diff` can be used to observe the code differences.

## Feature

1. The library uses the functions `__builtin_bswap16`, `__builtin_bswap32` for very fast byteswap operations with Arm MCU.

## Examples of using cases

1. Transmit & receive information data such as integers, (size-variable) strings, arrays, floats, structures, enums in a binary format from one device to another device via USB, TCP, etc.
2. Store & load information data such as integers, (size-variable) strings, arrays, floats, structures, enums in a binary format into a memory such as Flash, EEprom, etc.
3. Protocols such as VXI11 designed for connecting instruments (such as oscilloscopes, multimeters, spectrum analyzers, etc.) to controllers (e.g., PCs) use the underlying XDR/RPC protocol.

## Why reuse the c-code originally described by Sun

1. Develop fast a working concept with all features developed by Sun (debug on compilation, not on algorithms).
2. More important, it allows to use the xdr/rpc generator `rpcgen` to create c-code files (a contrario of a custom lib) and to implement easily a Remote Procedure Call (RPC) protocol (Note that the code generated by `rpcgen` may require some little hand-made rewrites in order to pass a compilation, basically reorder the code).
3. The licenses seem (?) not very restrictive (even for business uses in a product).

## References

Python has it own implementation (`xdrlib`). This can be used to check/debug function outputs.

## Licenses

1. Except the `*.ino` files (MIT license), and despite the code modifications, the entire source code is not belong to me. Please refer to the license description for each file. 
2. For any infringments of copyright or misunderstanding of the licenses, please let me know in advance. My goal is to share the modifications of the library for an application with the Arduino software and an Arm MCU in consideration that the basic code, and the ideas are not my property.

## More information at

- https://en.wikipedia.org/wiki/External_Data_Representation
- https://datatracker.ietf.org/doc/html/rfc1014

## Future

1. Clean up a bit the source code
2. Create test functions
3. Create a python code to correct the generated code made by rpcgen in order to pass a compilation.
