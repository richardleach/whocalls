# What

___whocalls___ is a simple Windows DLL that logs some info whenever it gets loaded.

# Why

For use in identifying and demonstrating DLL planting opportunities.

(I can never find other people's implementations when I need them.)

# How

1. Customise the output filename in the source code.

2. Compile to PE format.

  e.g. Using MinGW on Kali:

  `x86_64-w64-mingw32-gcc -shared -s -o whocalls.dll whocalls.c`

3. Customise the DLL name and drop it somewhere.
3. Periodically review the log file.

# Where

That's up to you.

