# :page_facing_up: Get_next_line 

<div align=center>

  ![badge](https://raw.githubusercontent.com/angelamcosta/angelamcosta/main/42_badges/get_next_linee.png)

  [![anlima's 42 get_next_line Score](https://badge42.vercel.app/api/v2/cl9oe5ogt00110fm6h34z9iu9/project/2860461)](https://github.com/JaeSeoKim/badge42)
</div>

<div align=center>
  <img alt="GitHub Language Count" src="https://img.shields.io/github/languages/count/angelamcosta/get_next_line" /> <img alt="GitHub Top Language" src="https://img.shields.io/github/languages/top/angelamcosta/get_next_line" /> <img alt="GitHub Contributors" src="https://img.shields.io/github/contributors/angelamcosta/get_next_line" /> <img alt="GitHub Last Commit" src="https://img.shields.io/github/last-commit/angelamcosta/get_next_line" />  <img alt="Github License" src="https://img.shields.io/github/license/angelamcosta/get_next_line" /> <img alt="wakatime" src="https://wakatime.com/badge/user/0c29d5b3-c30b-4e1a-ad07-2da3bd4f7e05/project/154bda21-dcba-4f9b-903a-09cebb8771dd.svg" />
</div>

`get_next_line` is a function that reads a line from a file descriptor and returns it as a string. It allows reading text from the file descriptor one line at a time until the end of the file. The function is designed to mimic the behavior of the standard `getline()` function and provides a convenient way to read input from files or other sources.

The subject of the project can be found in this [link](https://raw.githubusercontent.com/angelamcosta/get_next_line/main/en.subject.pdf) and the wiki explaining my solution to this project can be found [here](https://github.com/angelamcosta/get_next_line/wiki).

## ⚙️ Features
- Read a line from a file descriptor
- Returns the line as a string
- Supports reading from multiple file descriptors

## 🚀 Usage
To use the `get_next_line` function in your project, follow these steps:

1. Copy the following files into your project directory:
   - `get_next_line.c`
   - `get_next_line_utils.c`
   - `get_next_line.h`

2. Include the `get_next_line.h` header file in your source code:
   ```c
   #include "get_next_line.h"
   ```

3. Call the `get_next_line` function to read lines from a file descriptor.

## 🎉 Bonus (Optional)
The bonus part of the project aims to enhance the functionality of `get_next_line`. To complete the bonus part, make sure the mandatory part is perfect and then implement the following:

- Use a single static variable to succeed `get_next_line`.
- Manage multiple file descriptors, allowing reading from different file descriptors without losing the reading thread.

## 📗 External Functions
- `read`: Used to read data from the file descriptor.
- `malloc`: Used to allocate memory dynamically.
- `free`: Used to free allocated memory.

## 🚫 Restrictions
- The use of the `libft` library is not allowed for this project.
- The `lseek` function is not allowed. File reading must be done only once.
- `get_next_line` may have undefined behavior when reading from a binary file.

## 🗄️ Resources
For more information on `get_next_line` and related concepts, you can refer to the following resources:

- [Wikipedia - Static Variable](https://en.wikipedia.org/wiki/Static_variable)
- `man` pages:
  - `man 3 read`
  - `man 3 malloc`
  - `man 3 free`

**Note:** The `BUFFER_SIZE` macro can be modified to adjust the buffer size used for reading. However, during evaluation, the value will be modified to test different buffer sizes.
