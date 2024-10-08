# miniRT
<body>
    <h2>External functions</h2>
    <table>
        <tr>
            <th>Functions</th>
            <th>#include</th>
            <th>Prototype</th>
            <th>Description</th>
        </tr>
        <tr>
            <td>open</td>
            <td>&lt;fcntl.h&gt;</td>
            <td>int open(const char *path, int oflag, ...);</td>
            <td>Open or create a file for reading or writing.</td>
        </tr>
        <tr>
            <td>close</td>
            <td>&lt;unistd.h&gt;</td>
            <td>int close(int fildes);</td>
            <td>Delete a descriptor from the per-process object reference table.</td>
        </tr>
        <tr>
            <td>read</td>
            <td>&lt;sys/types.h&gt; <br /> &lt;sys/uio.h&gt; <br /> &lt;unistd.h&gt;</td>
            <td>ssize_t read(int fildes, void *buf, size_t nbyte);</td>
            <td>Read nbyte bytes of data from the object referenced by the descriptor fildes into the buffer pointed to by buf.</td>
        </tr>
        <tr>
            <td>write</td>
            <td>&lt;unistd.h&gt;</td>
            <td>ssize_t write(int fildes, const void *buf, size_t nbyte);</td>
            <td>Write nbyte of data to the object referenced by the descriptor fildes from the buffer pointed to by buf.</td>
        </tr>
        <tr>
            <td>printf</td>
            <td>&lt;stdio.h&gt;</td>
            <td>int printf(const char * restrict format, ...);</td>
            <td>Produces output.</td>
        </tr>
        <tr>
            <td>malloc</td>
            <td>&lt;stdlib.h&gt;</td>
            <td>void *malloc(size_t size);</td>
            <td>Allocate memory.</td>
        </tr>
        <tr>
            <td>free</td>
            <td>&lt;stdlib.h&gt;</td>
            <td>void free(void *ptr);</td>
            <td>Deallocates the memory allocation pointed to by ptr.</td>
        </tr>
        <tr>
            <td>perror</td>
            <td>&lt;stdio.h&gt;</td>
            <td>void perror(const char *s);</td>
            <td>Writes the error message corresponding to the current value of errno.</td>
        </tr>
        <tr>
            <td>strerror</td>
            <td>&lt;stdio.h&gt;</td>
            <td>char * strerror(int errnum);</td>
            <td>Returns a pointer to the error message string corresponding to the error number errnum.</td>
        </tr>
        <tr>
            <td>exit</td>
            <td>&lt;stdlib.h&gt;</td>
            <td>void exit(int status);</td>
            <td>Terminate a process.</td>
        </tr>
    </table>
    <p>Also:</p>
    <ul>
        <li>Use <a href="https://github.com/Hikabu/libft">libft functions</a> - a set of useful functions.</li>
        <li>All functions from the math library. Check with:</li>
    </ul>
    <pre>
        man 3 math
    </pre>
    <ul>
        <li>All functions from the MinilibX. Check:</li>
    </ul>
    <pre>
        man /usr/share/man/man3/mlx.1
    </pre>
    <h2>Vector and Matrix Functions</h2>
## Vector and Matrices Functions

Header: "vector.h" <br />
Folder: vector

* Structure with coordinates t_vector, defining a vector  $(x, y, z)$, where the data type of each coordinate is float.

* Creation of a t_vector variable from three passed float numbers <br />
`void	new_vector(t_coord *result, float x, float y, float z)` <br />

* Definition of the vector $\overrightarrow{AB}$ from two points $A(x_1, y_1, z_1)$ and $B(x_2, y_2, z_2)$ <br />
$\overrightarrow{AB}= (x_2-x_1, y_2-y_1, z_2-z_1)$ <br />
`void	new_vector_by_two_points(t_coord *result, t_coord *a, t_coord *b)` <br />

* Calculation of the length of the vector $\overrightarrow{AB}=(x, y, z)$ <br />
$|\overrightarrow{AB}|=\sqrt{x^2+y^2+z^2}$ <br />
`float	vector_length(t_coord *vector)`  <br />
From two points: <br />
$|\overrightarrow{AB}|=\sqrt{(x_2-x_1)^2+(y_2-y_1)^2+(z_2-z_1)^2}$  <br />

* Scalar multiplication of a vector by a number <br />
$\lambda\overrightarrow{a}=(\lambda a_x, \lambda a_y, \lambda a_z)$ <br />
`void	scalar_multiplication(t_coord *vector, float lambda)` <br />

* Sum/Difference of two vectors <br />
$\overrightarrow{a}\pm\overrightarrow{b}=(a_x\pm b_x, a_y \pm b_y, a_z \pm b_z)$ <br />
`void	vector_addition(t_coord *result, t_coord *a, t_coord *b)` <br />
`void	vector_subtraction(t_coord *result, t_coord *a, t_coord *b)`

* Finding the unit vector (vector of unit length)  <br />
$\overrightarrow{e}_{\overrightarrow{a}}=\frac{\overrightarrow{a}}{|\overrightarrow{a}|}$  <br />
`void	normalizing_vector(t_coord *result, t_coord *vector)`

* Scalar multiplication of vectors
$\overrightarrow{a}\cdot\overrightarrow{b}=a_x b_x + a_y b_y + a_z b_z$

* Calculation of the angle between vectors
$\cos{\phi}=\frac{\overrightarrow{a}\cdot\overrightarrow{b}}{|\overrightarrow{a}||\overrightarrow{b}|}$

Additional functions for visualization:
- [X] Output to stdout of vector vector, optionally with the vector name name <br />
`void	print_vector(char *name, t_coord *vector);`

## Ray-Object Intersection Formulas

### Ray and Plane Intersection
$\begin{equation*}
 \begin{cases}
   x=a+td \quad \text{(ray)}
   \\
   (x,n)=r \quad \text{(plane)}
 \end{cases}
\end{equation*}$

where
* $a$ - point of the camera
* $d$ - ray vector
* $n$ - normal vector to the plane
* $r$ - point of the plane

From this, the solution of the equation is:
$t=\frac{((r - a), n)}{(d,n)}$

Conditions:
* If $(d,n)=0$, the ray is parallel to the plane, meaning it does not intersect it.
* If $(t>0)$, the ray intersects the plane in the direction of projection.

The normal that will be used for further calculations of the reflected ray must form an obtuse angle with the direction vector d.

