# Random Booklet and Answer Sheet Generator

## Overview
This project generates multiple randomly ordered booklets and their corresponding answer sheets from a single input exam sample file. The program provides flexibility in the number of booklets and the number of questions per booklet, ensuring randomization in both question selection and option order.

## Features
- Generates **m booklets**, each containing **n questions** (where n ≤ N, the total number of questions in the input file).
- Randomizes the order of the questions in each booklet.
- Randomizes the order of options for each question.
- Ensures each question appears only once per booklet.
- Produces **2 files per booklet**:
  - A **question file** containing the randomly ordered questions.
  - An **answer sheet** mapping the correct answers to their randomized options.

## Input Format
The program accepts an input text file (e.g., `sample.txt`) containing multiple-choice questions in the following format:
- Each question starts with a unique identifier (e.g., `Q1.`).
- Options are labeled as `A.`, `B.`, `C.`, and `D.`.
- The correct answer is explicitly indicated with the format `Answer: X`.
  
## Output
The program generates the following for each booklet:
1. **Question File (e.g., booklet_1_questions.txt)**  
   A randomized selection of n questions, each with its options shuffled.
   
2. **Answer Sheet (e.g., booklet_1_answers.txt)**  
   A corresponding answer sheet indicating the correct option for each question in the randomized order.

## Usage
1. Provide an input text file with the specified format (e.g., `input.txt`).
2. Specify:
   - The number of booklets (`m`).
   - The number of questions per booklet (`n`).
3. Run the program to generate the output files.

## Output Example
For `m = 2` booklets with `n = 5` questions, the program might generate:

1. **booklet_1_questions.txt**
2. **booklet_1_answers.txt**
3. Repeat for `booklet_2_questions.txt` and `booklet_2_answers.txt`.
