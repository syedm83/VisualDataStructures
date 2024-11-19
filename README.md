# Visual Data Structures

## Overview
VisualStack is a C++ application that provides a visual, interactive representation of a stack data structure. Using the SFML (Simple and Fast Multimedia Library), this project animates stack operations like pushing and popping elements, allowing users to observe how the stack behaves in real-time. With smooth animations and interactive controls, VisualStack helps users understand the Last-In-First-Out (LIFO) principle through visual feedback.

## Technologies Used

### C++

### SFML (Simple and Fast Multimedia Library)
The graphical user interface and animations are powered by **SFML**, a multimedia library used for creating 2D games and interactive applications. SFML provides a simple and easy-to-use interface to manage windows, graphics, and events.

- **Rendering**: SFML allows us to draw shapes, such as rectangles (used to represent data elements), and manage their appearance on the screen.
- **Animation**: SFML enables us to animate the transition of data elements as they are pushed to or popped from the data structures.
- **Event Handling**: SFML handles user inputs (such as keyboard presses) to interact with the program, making it possible to control data structure operations and visualizations interactively.



## Features
- Push Animation: Visualizes the stack's push operation by animating new elements being added to the stack, with random colors for each new element.
- Pop Animation: Animates the pop operation, showing the element being removed from the stack with a fade-out effect.
- Interactive Control: Allows users to push and pop elements interactively by pressing the P and O keys, respectively.
- Dynamic Visualization: Each element in the stack is represented by a colored bar, whose position and opacity change as operations are performed.
- Smooth Transitions: Animations feature smooth vertical movements and gradual fading to make the stack operations visually clear.

