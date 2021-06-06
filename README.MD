Teensyduino project for using an OEM NES controller as a USB gamepad.

Internally NES controllers are essentially just a shift register(typically a 4021 or 74LS165) which presents the data from each button over a serial protocol(latch, data, and clock). So all we need to do is grab whatever the shift register is outputting and use it to prepare a USB packet.

If you just want an up and running USB NES controller, you can break out each pin from the male connector:
![](https://i.imgur.com/0zBLXNm.png)

all you need to do is hook up CLK, LATCH, and DATA to a teensy & you're ready to go. You can also salvage a female receptacle from an NES or source one elsewhere.

Alternatively, for a more permanent solution, you can desolder the cable entirely & run the wires to a Teensy mounted internally.
![](https://i.imgur.com/WsZt2VL.jpg)

Once you've chosen one of these methods, all you need to do is upload the code to a Teensy set to Joystick mode. The device should show up as either "NES Controller" or the vendor ID associated with your Teensy.
![](https://i.imgur.com/wvDfpoQ.png)

You can easily test the gamepad with either joy.cpl(Windows) or https://apps.nektro.net/gamepad/ although it's not guaranteed web-browser based testers will yield accurate results due to differences in how each browser implements gamepads.

This can also be used as a library for handling NES controllers although I haven't tested it with PAL controllers.