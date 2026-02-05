#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GRAY "\033[90m"
# define BOLD "\033[1m"
# define UNDER "\033[4m"
# define BLINK "\033[5m"
# define ERASE = "\033[2K\r"
# define RESET "\033[0m"
# define CASCADEPATH "/opt/homebrew/Cellar/opencv/4.13.0_3/share/opencv4/haarcascades/haarcascade_frontalface_default.xml"

using namespace cv;
