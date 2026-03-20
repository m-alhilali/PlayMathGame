# 🧮 Math Quiz Game (C++)

An interactive command-line Educational Game built with **C++**. This project challenges users with various mathematical operations across different difficulty levels, providing real-time feedback and a final performance summary.

## 🚀 Features
* **Customizable Quizzes:** Choose the number of questions you want to solve (up to 10 per session).
* **Difficulty Levels:** Supports four difficulty settings:
  * 🟢 **Easy:** Numbers from 1 to 10.
  * 🟡 **Medium:** Numbers from 10 to 50.
  * 🔴 **Hard:** Numbers from 50 to 100.
  * 🌪️ **Mix:** Randomly alternates between levels.
* **Operation Types:** Practice specific operations or mix them up:
  * Addition (`+`), Subtraction (`-`), Multiplication (`*`), Division (`/`), or **Mix**.
* **Visual Feedback:** 
  * Background turns **Green** for correct answers.
  * Background turns **Red** for wrong answers.
* **Final Report:** Detailed summary showing total questions, success/fail status, and the number of right vs. wrong answers.

## 🛠️ Technical Highlights
* **Data Structures:** Used `struct` to manage complex data for both individual questions and the overall quiz state.
* **Modular Logic:** Cleanly separated into functions for question generation, calculation, and UI updates.
* **Randomization:** Utilizes `srand` and `rand` for dynamic and unpredictable question generation.

## 📂 How to Run
1. Ensure you have a C++ compiler installed (like GCC or MSVC).
2. Download the `Math_Quiz.cpp` file.
3. Compile and run using your IDE (Visual Studio, Code::Blocks) or via terminal:
   ```bash
   g++ Math_Quiz.cpp -o MathQuiz
   ./MathQuiz
