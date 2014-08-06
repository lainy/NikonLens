NikonLens for Arduino
=====================
Unfinished library for controlling Nikon F-mount lenses from an Arduino.  
Publishing this as a starting point for others, as I have been busy elsewhere. Please feel free to contribute!

Based on work by myself and the developers at [Nikon Hacker].

Project status:  
![Procrastination!](https://i.imgur.com/3naiPgj.gif "Procrastination!")  
Happy to accept pull requests, unsure when I'll have time for hacking on it myself.

---

Warning
-------
**As with anything that talks to hardware, please consider that this has the potential to destroy your equipment.**

Lenses can be *very expensive*. Applying the wrong voltages, incorrect wiring, or possibly even sending the wrong command at the wrong time could ***brick your lens***.

**Bottom line:** *Do not attempt to use this library with real lenses unless you understand the risks.*

---

Basic Usage
-----------
At the moment the library creates an instance of `tNikonLens` in the `lain` namespace. First you need to initialize the interface:
```cpp
using namespace lain;
/* See documentation for wiring information. */
NikonLens.begin(HandshakePin_In, HandshakePin_Out);
```
Then you can send commands. Start by initializing the lens:
```cpp
u8 fromLens[7];
u8 toLens[] = { 0x02, 0x1b };

/* Init lens with default parameters used by D5100 */
tNikonLens::tResultCode result =
    NikonLens.sendCommand(0x40, 7, fromLens, sizeof(toLens), toLens);
// Check result, check data from lens...

/* Confirm actual lens parameters */
result = NikonLens.sendCommand(0x41, 2, fromLens);
// Check result, verify parameters from lens...
```
Details about the commands used can be found on the [Nikon Hacker Wiki] under [Lens Serial Interface].

TODO
----
 - Implement functions for sending known commands, like:  
   `AutoFocus(u8 param1_unknown, tDirection dir, u16 steps)`
 - Toss some example code in the repo.
 - Better documentation on the lens commands here and at [Nikon Hacker Wiki].
 - ... I'm sure there's more, I'll update this as things come up.

License
-------
MIT

[Nikon Hacker]:https://nikonhacker.com/
[Nikon Hacker Wiki]:https://nikonhacker.com/wiki/Main_Page
[Lens Serial Interface]:https://nikonhacker.com/wiki/Lens_Serial_Interface
