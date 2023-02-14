
# DWM
dwm is a dynamic window manager for X. It manages windows in tiled, monocle and floating layouts. All of the layouts can be applied dynamically, optimising the environment for the application in use and the task performed.

# Preview
<img src="https://github.com/motolla/dwm-rose/blob/main/assets/dwm-preview1.png">
<img src="https://github.com/motolla/dwm-rose/blob/main/assets/dwm-preview2.png">
<img src="https://github.com/motolla/dwm-rose/blob/main/assets/dwm-preview3.png"><br>

# Keybind
```
# Spawn Terminal (st)
Alt + Enter

# Close and Kill
Alt + q

# Quit DWM
Alt + Shift + q
```

# Requirements
+ Void
```
xbps-install libXft-devel libX11-devel libXinerama-devel
```
# Font

+ [Iosevka-Mayukai-Sonata](https://github.com/Iosevka-Mayukai/Iosevka-Mayukai)

+ Symbols Nerd Font

# Installation
+ Clone Repo
use this command if you want the autostart working
```
git clone https://github.com/motolla/dwm-rose.git $HOME/dot/dwm
```
or u can edit this [line](https://github.com/motolla/dwm-rose/blob/17aee8f7d94dd8e0b0ecd1b9ed730a830600a8bb/dwm.c#L1525) to directory you cloned the repo
+ Build & Install
```
./dwmclean
```

# Patch Applied
+ autostart
+ actualfullscreen
+ alwayscenter
+ barpadding
+ colorfull tag
+ movestack
+ notitle
+ statuspadding
+ vanity gaps
