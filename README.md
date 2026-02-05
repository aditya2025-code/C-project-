# C Programming Projects Collection

A collection of console-based C programming projects demonstrating fundamental programming concepts, data structures, and problem-solving skills.

## 📋 Table of Contents

- [Projects Overview](#projects-overview)
- [Technologies Used](#technologies-used)
- [Getting Started](#getting-started)
- [Project Details](#project-details)
- [What I Learned](#what-i-learned)
- [Future Improvements](#future-improvements)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## 🚀 Projects Overview

This repository contains five C programming projects, each focusing on different aspects of programming:

| Project | Description | Key Concepts |
|---------|-------------|--------------|
| **Canteen Billing System** | A billing management system for canteen operations | File handling, structs, menu-driven interface |
| **Student Management System** | Manage student records with CRUD operations | Data structures, file I/O, record management |
| **Tic-Tac-Toe** | Classic two-player game implementation | 2D arrays, game logic, input validation |
| **Number Guessing Game** | Interactive number guessing game with hints | Random numbers, loops, conditional logic |
| **Find Day From Date** | Calculate day of the week for any given date | Date algorithms, mathematical computations |

## 🛠️ Technologies Used

- **Language**: C
- **Compiler**: GCC (GNU Compiler Collection)
- **Platform**: Cross-platform (Windows/Linux/macOS)
- **Key Concepts**: 
  - Data structures (arrays, structures)
  - File handling
  - Pointers and memory management
  - Control structures
  - Function modularization

## 📦 Getting Started

### Prerequisites

- GCC compiler installed on your system
  - **Windows**: Install MinGW or use WSL
  - **Linux**: Usually pre-installed, or use `sudo apt-get install gcc`
  - **macOS**: Install Xcode Command Line Tools

### Installation & Running

1. Clone the repository:
```bash
git clone https://github.com/aditya2025-code/C-project-.git
cd C-project-
```

2. Navigate to any project folder:
```bash
cd "Canteen Billing System"
```

3. Compile the C file:
```bash
gcc main.c -o output
```

4. Run the executable:
```bash
# On Linux/macOS
./output

# On Windows
output.exe
```

## 📚 Project Details

### 1. Canteen Billing System

**Purpose**: Automate billing operations for a canteen or cafeteria.

**Features**:
- Add items to the menu
- Generate bills for customers
- Calculate totals with taxes
- Save and retrieve billing records
- Display menu items

**Technical Highlights**:
- Uses structures to store item details
- File handling for persistent data storage
- Menu-driven interface for easy navigation

**Usage**:
```bash
cd "Canteen Billing System"
gcc canteen.c -o canteen
./canteen
```

---

### 2. Student Management System

**Purpose**: Manage student records efficiently with complete CRUD functionality.

**Features**:
- Add new student records
- Display all student information
- Search for specific students
- Update existing records
- Delete student records
- Save data to file

**Technical Highlights**:
- Struct-based student records
- File operations for data persistence
- Search algorithms
- Data validation

**Usage**:
```bash
cd "Student Management System"
gcc student_mgmt.c -o student
./student
```

---

### 3. Tic-Tac-Toe

**Purpose**: Classic two-player Tic-Tac-Toe game implementation.

**Features**:
- Two-player gameplay
- Input validation
- Win detection algorithm
- Draw detection
- Clean console-based UI

**Technical Highlights**:
- 2D array for game board
- Game state management
- Win condition checking logic
- Player turn alternation

**Usage**:
```bash
cd "Tic-Tac-Toe"
gcc tictactoe.c -o tictactoe
./tictactoe
```

---

### 4. Number Guessing Game

**Purpose**: Interactive game where players guess a randomly generated number.

**Features**:
- Random number generation
- Hint system (higher/lower)
- Attempt counter
- Difficulty levels (optional)
- Play again option

**Technical Highlights**:
- Random number generation using `rand()`
- Loop structures for game flow
- Conditional logic for hints

**Usage**:
```bash
cd "Number Guessing Game"
gcc number_game.c -o game
./game
```

---

### 5. Find Day From Date

**Purpose**: Calculate the day of the week for any given date.

**Features**:
- Input any date (DD/MM/YYYY)
- Calculate day of the week
- Validate date inputs
- Handle leap years

**Technical Highlights**:
- Zeller's Congruence or similar algorithm
- Date validation logic
- Leap year calculation
- Mathematical computations

**Usage**:
```bash
cd "Find Day From Date"
gcc find_day.c -o findday
./findday
```

## 💡 What I Learned

Through developing these projects, I gained hands-on experience with:

- **Core C Programming**: Variables, data types, operators, control structures
- **Functions**: Creating modular, reusable code
- **Data Structures**: Arrays, structures, and their applications
- **File Handling**: Reading from and writing to files for data persistence
- **Memory Management**: Understanding pointers and dynamic memory
- **Algorithm Design**: Implementing game logic, search algorithms, and mathematical computations
- **User Input Validation**: Creating robust programs that handle edge cases
- **Problem-Solving**: Breaking down complex problems into manageable components

## 🔮 Future Improvements

Potential enhancements for these projects:

- [ ] Add a database integration (SQLite) instead of file handling
- [ ] Implement a graphical user interface using GTK or Qt
- [ ] Add unit tests for critical functions
- [ ] Create a single-player Tic-Tac-Toe with AI opponent
- [ ] Add difficulty levels to the Number Guessing Game
- [ ] Implement data encryption for sensitive information
- [ ] Add comprehensive error handling and logging
- [ ] Create detailed documentation for each function

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/aditya2025-code/C-project-/issues).

To contribute:
1. Fork the repository
2. Create a new branch (`git checkout -b feature/improvement`)
3. Commit your changes (`git commit -am 'Add new feature'`)
4. Push to the branch (`git push origin feature/improvement`)
5. Create a Pull Request

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

## 📧 Contact

**Aditya** - [@aditya2025-code](https://github.com/aditya2025-code)

Project Link: [https://github.com/aditya2025-code/C-project-](https://github.com/aditya2025-code/C-project-)

---

⭐ If you found this repository helpful, please consider giving it a star!

**Happy Coding!** 🚀
