#ifndef OPENCV_PROJECT_GAME_HPP
#define OPENCV_PROJECT_GAME_HPP

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <unistd.h>
#include <iostream>
#include <cmath>
#include <ctime>
#include <map>
#include "Weapon.hpp"
#include "Enemy.hpp"

class Game {
public:
	Game();
	void Run();
	~Game();

private:
//	void CallBackFunc(int event, int x, int y, int flags, void* userdata);
	int KeyCodes(int key);
	cv::VideoCapture cap_;
	cv::Mat frame_;
	int num_frames_ = 0;
	double speed_;
	int x_, y_;
	int hp_	;
	std::map<std::string, cv::Mat> images_;
	time_t enemyBurn_;
	bool isGameEnded_ = false;
	std::vector<Enemy> enemies_;
};


#endif //OPENCV_PROJECT_GAME_HPP
