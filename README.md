gitch  ![logo](https://lh4.googleusercontent.com/-AqAkPLBtXM4/UW3oygVWHLI/AAAAAAAACF0/27mJnkGMiUQ/s77/passing.png)
=====

Personalize the way you operate Git from the command line.

gitch is currently in development and although it is useable it does not work in a friendly way (yet).

##How To Use

Invoke gitch.exe from the command line. (Note: One can rename gitch.exe to anything that floats their boat)

For ease of use it is recommended that a user puts gitch.exe into their system path variable, so that one can access it without specifying the absolute path.

###Core Commands

####gitch init

Supply the argument "init" to initialize an empty configuration file. (Note: This file is hidden)

####gitch list

Displays all custom gitch commands the user has created. 

####gitch replace

Allows the user to create a new custom command for gitch. (NOTE: THIS FEATURE IS NOT FULLY DEVELOPED)

###What the heck are custom commands?

Custom commands are commands supplied by the user. This allows the user to do something like:

```git pull github master```

with the shorthand:

```gitch yank```

###So how do I make my own custom command?

Simple. Take a look at the command line stuff below:



```C:\testingground>gitch replace

Enter the shorthand for the command:
connect

Enter the commands for git which will be represented by this shorthand:
git remote add origin https://github.com/user/repo.git

Setting up gitch command for: remote add origin https://github.com/user/repo.git


C:\testingground>gitch connect```


