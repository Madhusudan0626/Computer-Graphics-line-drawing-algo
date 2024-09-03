# Computer Graphics Algorithms in C
Computer graphics is a field of computer science that focuses on the creation, manipulation, and representation of visual images and animations through computational techniques. It encompasses a variety of concepts including rendering, transformations, and algorithms for drawing geometric shapes. These techniques are widely used in applications ranging from video games and simulations to data visualization and graphical user interfaces.

This repository contains various computer graphics algorithms implemented in C. The code demonstrates essential graphics techniques and transformations using OpenGL.

## 📂 Repository Structure

- `algorithms/`: Contains C files implementing various graphics algorithms.
- `examples/`: Includes example programs showcasing the use of these algorithms.

## 🛠️ Compilation and Execution

To compile and run the OpenGL programs, use the following command:

```bash
gcc program_name.c -lglut -lGLU -lGL
```

Replace `program_name.c` with the name of your C file. 

## 📈 Algorithms Included

- **Line Drawing Algorithms**: DDA, Bresenham
- **2D and 3D Transformations**: Various transformation techniques

## 🚀 Usage

1. **Clone the repository:**

    ```
    git clone https://github.com/Madhusudan0626/computer-graphics-algos.git
    ```

2. **Navigate to the project directory:**

    ```
    cd 3d or cd My2dTransformation
    ```

3. **Compile and run an example program:**

    ```
    gcc example.c -lglut -lGLU -lGL
    ./a.out
    ```

4. **Fullscreen Mode**: Use `glutFullScreen()` to set the window to fullscreen mode.

5. **Setting the Orthographic Projection**: Use `glOrtho(param1, param2, param3, param4)` to define the viewing volume, e.g., 

    ```c
    glOrtho(1920, -1920, 1080, -1080);
    ```

## 🤝 Acknowledgments

- Special thanks to the open-source community for their valuable tools and libraries.

Feel free to contribute, open issues, or reach out with any questions or suggestions!

---
