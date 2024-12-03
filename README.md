# 🕹️ so_long

so_long is a 2D game developed as part of the 42 curriculum. The project involves creating a simple graphical game using the MiniLibX library, where the player collects items and reaches the exit while navigating through a map. This repository includes the mandatory part of the project and can optionally include bonus features.

---

## 🎮 Gameplay

- The player starts on the map and must collect all collectibles (`C`) before reaching the exit (`E`).
- The player navigates using the arrow keys or `W`, `A`, `S`, `D`.
- The game ends when the player reaches the exit after collecting all the collectibles.

---

## 📋 Features

### **Mandatory**
- Display the game map as a grid of sprites.
- Handle player movement and ensure valid gameplay rules.
- Close the game properly when:
  - The user presses the `ESC` key.
  - The user clicks the close button on the window frame.

### **Bonus Features**
- Display movement count directly on the screen.
- Add animations for sprites.
- Introduce enemy patrols that cause the player to lose upon collision.

---

## 🚀 Getting Started

### Prerequisites
- macOS or Linux (MiniLibX is not natively supported on Windows).
- [MiniLibX](https://github.com/42Paris/minilibx-linux) installed.
- X11 libraries (Linux) or XQuartz (macOS).

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your_username/so_long.git
   cd so_long
2. Compile the project:
```bash
make
```
3. Run the game:

```bash
./so_long <map_file>
```
## 🗺️ Map Requirements
The map must be rectangular.
It must contain:
At least one player starting position (P).
At least one exit (E).
At least one collectible (C).
Walls (1) surrounding the entire map.
Other tiles should be empty space (0).
Example map:
Copiar código
111111
1P0C01
100001
1C0E01
111111
📂 File Structure
makefile
Copiar código
so_long/
├── assets/               # Sprites for the game
├── include/              # Header files
├── src/                  # Source code
│   ├── main.c            # Entry point
│   ├── map.c             # Map parsing and validation
│   ├── game.c            # Core game logic
│   ├── render.c          # Rendering logic
│   ├── events.c          # Event handling
├── Makefile              # Build instructions
└── README.md             # Project documentation
🛠️ Built With
MiniLibX - Graphics library.
C programming language.
📖 Future Improvements
Enhanced animations for more immersive gameplay.
Complex enemy AI for challenging levels.
Dynamic map resizing during gameplay.
✨ Acknowledgments
This project is part of the 42 Network curriculum. Special thanks to the 42 community for guidance and support!

📜 License
This project is licensed under the MIT License. See the LICENSE file for details.
