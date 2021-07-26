# UButtonTester
Hey! Its my first public homebrew application. God it took a while (get wut setup all that stuff) and no I have made 3ds/ds and wii homebrew apps (I dont want to make them public since I am very bad at homebrew coding)
# Compiling
u dont have to compile it but if u like wasting ur time here you go
so make a new folder in the root of the project called build (first download the project)
now go into the folder called build and now type this command: `cmake ..` oh and yeah if ur more smarter than me and have wut installed on windows u can do this on windows but I recommend linux (its easier)
u need cmake (not the from the android toolchain that will build for armgeabi or something like that)
now in the build folder type this command: `make` u will need make for this to work
BOOM compiled
# Running
so if u skipped compiling (or compiled already) now u gotta put the RPX file in ur sd card so go to sd:/wiiu/apps/ and sd is where ur sd card is so in the apps folder create a new folder called "UButtonTester" and copy the RPX file to the UButtonTester folder (and if u want to u can pull request and put a meta.xml file)