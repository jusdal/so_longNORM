# so_long

[![C](https://img.shields.io/badge/language-C-blue)](https://github.com/jusdal/so_longNORM)
[![42 Network](https://img.shields.io/badge/school-42%20Network-black)](https://42.fr)

A 2D tile-based game built from scratch in C using the MiniLibX graphics library. The player navigates a map, collects all items, and reaches the exit — with move count displayed on screen.

## Gameplay

- Move with **W / A / S / D** or arrow keys
- Collect all collectibles before the exit opens
- Move counter updates in the terminal with each step
- Game ends when the player reaches the exit after collecting everything

## Technical implementation

**Map parsing** — Maps are loaded from `.ber` files. The parser reads each line using a custom `get_next_line` implementation, validates dimensions, checks for required elements (player `P`, exit `E`, collectibles `C`, walls `1`, empty space `0`), and rejects malformed maps with a clean error message.

**Flood fill validation** — Before the game starts, a flood fill algorithm runs on a copy of the map to verify that all collectibles and the exit are actually reachable from the player's starting position. Invalid maps (unreachable items, no enclosed border) are rejected before the window opens.

**Rendering** — MiniLibX handles the window and event loop. Sprites are loaded as XPM images and rendered tile-by-tile each frame. The render pipeline redraws only what changes to avoid unnecessary overhead.

**Key handling** — Keyboard input is captured via MiniLibX hooks. Movement logic checks the target tile before updating the player's position — walls block movement, collectibles increment the counter, the exit triggers the win condition.

**Memory management** — All map data, sprite images, and game state are allocated on the heap and fully freed on both normal exit and error paths.

## Map format

Maps are plain text `.ber` files using these characters:

| Character | Meaning |
|---|---|
| `1` | Wall |
| `0` | Empty space |
| `P` | Player start (exactly 1) |
| `E` | Exit (exactly 1) |
| `C` | Collectible (at least 1) |

Maps must be rectangular and fully enclosed by walls.

## Build & usage

```bash
make
./so_long maps/map1.ber
```

Requires MiniLibX. On macOS, the included `mlx/` directory contains the library — `make` links it automatically.

## Project context

Built as part of the 42 Network common core. No game engine, no external graphics libraries beyond MiniLibX — all game logic, map parsing, validation, and rendering implemented from scratch in C with strict norm compliance.
