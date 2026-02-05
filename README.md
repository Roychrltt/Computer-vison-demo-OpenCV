# Computer Vision Demo - OpenCV C++

A simple but comprehensive computer vision program demonstrating key CV techniques using OpenCV and C++.

## Features

- **Real-time Face Detection** using Haar Cascade classifiers
- **Edge Detection** using the Canny algorithm
- **Image Filtering** (Gaussian blur, grayscale conversion)
- **Interactive Controls** to toggle different features
- **Webcam Integration** for real-time processing

## Requirements

- C++ compiler (g++ or clang)
- Make (usually pre-installed on macOS/Linux)
- OpenCV (version 4.x recommended)

## Installation

### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install libopencv-dev opencv-data
```

### macOS
```bash
brew install opencv
```

**Note**: Homebrew's OpenCV installation includes all necessary components including Haar Cascade files.

### Windows
Download and install:
- Visual Studio with C++ support or MinGW
- OpenCV from opencv.org
- Make sure to add OpenCV to your system PATH

## Compilation

### Using Makefile (Recommended)
```bash
make
./detector
```

### Clean and rebuild
```bash
make clean
make
```

### Using g++ directly
```bash
g++ face_and_edge_detector.cpp -o face_detector \
    `pkg-config --cflags --libs opencv4`
./face_detector
```

**Note**: The Makefile is pre-configured for both macOS (Homebrew) and Linux systems. It will automatically detect the correct OpenCV paths.

## Usage

Once the program is running, you'll see a live feed from your webcam with the following keyboard controls:

| Key | Function |
|-----|----------|
| `q` | Quit the application |
| `f` | Toggle face detection on/off |
| `e` | Toggle edge detection on/off |
| `g` | Toggle grayscale mode on/off |
| `b` | Toggle Gaussian blur on/off |

## How It Works

### Face Detection
Uses Haar Cascade classifiers, a machine learning-based approach where a cascade function is trained from positive and negative images. The algorithm detects faces in real-time and draws bounding boxes around them.

### Edge Detection
Implements the Canny edge detection algorithm, which uses a multi-stage process to detect a wide range of edges in images.

### Image Filtering
- **Grayscale**: Converts color images to grayscale for simplified processing
- **Gaussian Blur**: Reduces noise and detail using a Gaussian function

## Technical Details

- **Language**: C++11
- **Framework**: OpenCV 4.x
- **Computer Vision Techniques**:
  - Haar Cascade Classification
  - Canny Edge Detection
  - Gaussian Blur
  - Color Space Conversion (BGR ↔ Gray)

## Project Structure

```
.
├── srcs/
│   └── main.cpp                   # Main program source code
├── include/
│   └── faceDetector.hpp          # Header files
├── Makefile                       # Build configuration
└── README.md                      # This file
```

## Troubleshooting

### Haar Cascade file not found
If you get an error about the Haar Cascade file, find it on your system:

**macOS (Homebrew):**
```bash
find /opt/homebrew -name "haarcascade_frontalface_default.xml"
```

Common locations:
- macOS (Homebrew): `/opt/homebrew/opt/opencv/share/opencv4/haarcascades/`
- Ubuntu/Linux: `/usr/share/opencv4/haarcascades/`
- Windows: `C:/opencv/build/etc/haarcascades/`

**If not found, download manually:**
```bash
mkdir -p ~/haarcascades
curl -o ~/haarcascades/haarcascade_frontalface_default.xml \
  https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_default.xml
```

Then update the path in your code to point to the downloaded file.

### Webcam not detected
Make sure:
- Your webcam is connected and not being used by another application
- You have camera permissions enabled
- Try changing the camera index from `0` to `1` or `2`

## Skills Demonstrated

This project showcases:
- ✅ C++ programming proficiency
- ✅ OpenCV library usage
- ✅ Real-time image processing
- ✅ Object detection algorithms
- ✅ User interface and interaction handling
- ✅ Makefile build system knowledge
- ✅ Code documentation and structure

## License

MIT
