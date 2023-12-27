#!/bin/bash

# Compile the main.cpp file with OpenCV libraries
g++ -std=c++11 -I/opt/homebrew/Cellar/opencv/4.8.1_5/include/opencv4 -L/opt/homebrew/Cellar/opencv/4.8.1_5/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_videoio -o ascii_video_player main.cpp

# Run the compiled program
./ascii_video_player
