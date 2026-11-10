# LowFPSMode — ReShade add-on source

A small 64-bit ReShade add-on for Windows. Press **F8** to toggle Low FPS Mode.

## What it does

- When enabled, it disables ReShade's post-processing effects through the documented ReShade API.
- It remembers whether effects were enabled before the toggle and restores that state when disabled.
- It writes a short status message to the ReShade log.

This can reduce the GPU/CPU cost of ReShade effects. It does **not** change GTA V/FiveM graphics settings or guarantee an increase in game FPS.

## Important FiveM Pure Mode 1 limitation

This is a standard ReShade add-on. It does not patch game memory, modify game files, intercept game weather/fog values, read player/entity data, or bypass Pure Mode / anti-cheat checks. Pure Mode 1 may block ReShade or third-party add-ons entirely. If FiveM blocks it, do not try to bypass that restriction; remove the add-on and use in-game graphics settings instead.

Native GTA V fog removal and PvP/player-visibility assistance are deliberately not included. ReShade's supported post-processing API is not a legitimate route to changing native game fog or game-world state, and visibility advantages in multiplayer may violate server rules.

## Build (Windows 10/11)

Requirements:

- Visual Studio 2022 with **Desktop development with C++**
- CMake 3.20 or newer
- Git for Windows

Steps:

1. Extract this folder.
2. Run `build.bat`.
3. The script clones the official ReShade source headers into `external\reshade` and builds an x64 add-on.
4. Output: `build\Release\LowFPSMode.addon64`.

The project builds source only; it does not include ReShade binaries or redistribute the supplied `GBarrioKit.addon64` file.

## Install

Only use it in a game/environment where ReShade add-ons are permitted. Put the built file in the ReShade add-on search directory, restart the application, and check ReShade's add-on list/log to see whether it loaded. Press **F8** to toggle.

If the add-on is not listed or the game refuses to start, remove it. Pure Mode 1 compatibility is not guaranteed.
