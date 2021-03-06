#pragma once
//STL
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <stdint.h>
#include <string>
#include <chrono>
#include <numeric>
#include <math.h>
#include <filesystem>
#include <queue>
#include <functional>
#include <vector>
#include <complex>
#include <tuple>
#include <thread>
#include <atomic>
#include <mutex>
#include <memory>
#include <unordered_map>
//OpenCV
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
//spdlog
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
//OpenGL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
//stb_image
#include <Vendor/stb_image/stb_image.h>
//glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/euler_angles.hpp>
//imgui
#include <Vendor/imgui/imgui.h>
#include <Vendor/imgui/imgui_impl_glfw.h>
#include <Vendor/imgui/imgui_impl_opengl3.h>
//custom
#include "Log/Logger.h"
#include "Utils/MathUtils.h"
#include "Utils/TimeUtils.h"
#include "Utils/ThreadUtils.h"

