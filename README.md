## About it

Like https://syrinscape.com/ but free and offline.

This is an Open RPG Sound Library for RPG players. This repo is for version control only. Feel free to contribute, fork this project and use it however you want. But keep in mind that this is under the GNU GPL 3 license!

The idea of this project is to create a tool to RPG masters to control the soundtrack of their adventures in an easy way.

If you're not a developer and you want to use this program that's still under development send me an email and I'll help you to get a running version of this in your computer! :)

## How to run it

Currently the only way to run it is if you have a Qt environment in your computer. You can get Qt [here](https://www.qt.io/download). Just choose an Open Source license and you're good to go. Install it.

Download this repository either by cloning it or just downloading the zip [here](https://github.com/marimeireles/openrpgsl/archive/master.zip).

Open your terminal go to the directory you just downloaded and tipe `qmake -project`. Let it run. Type `qmake openrpgsl.pro`. Type `make`.

Okay! Now you should have a compiled version of openrpgsl! :)

You'll need to find the path of the executable. In MacOS you can find it under `./bin/openrpgsl.app/Contents/MacOS/openrpgsl`. Don't forget to add the "." dot in the beggining, just like the example.

## Kool features

* You can save the current status of your library and load it later.

## Gallery

openrpgsl first screen:

![rpgsl-example-initial](/images/rpgsl-example-initial.jpeg)

openrpgsl being used as a sound manager system for a medieval adventure:

![rpgsl-example](/images/rpgsl-example.png)
