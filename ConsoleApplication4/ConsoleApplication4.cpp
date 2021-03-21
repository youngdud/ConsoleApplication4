#define _CRT_SECURE_NO_WARNINGS
#include<Bangtal.h>
#include<stdio.h>

SceneID scene1;
SceneID scene2;
ObjectID puzzle;
ObjectID startButton;
ObjectID restartButton;
ObjectID puzzleee;
TimerID timer1;

ObjectID puzzlee[10];
ObjectID right[7];


int X[9] = { 500, 350, 350, 650, 650, 500, 500, 350, 650 };
int fX[9] = { 350, 500, 650, 350, 500, 650, 350, 500, 650 };
int Y[9] = { 120, 120, 270, 120, 270, 270, 420, 420, 420 };
int fY[9] = { 120, 120, 120, 270, 270, 270, 420, 420, 420 };
int time = 0;
char buf[256];
ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);
	if (shown == true) {
		showObject(object);
	}
	return object;
}

TimerID createTimer2(Second second) {
	TimerID timer = createTimer(second);
	showTimer(timer);
	return timer;
}

void startGame3() {
	enterScene(scene2);
	hideObject(restartButton);
	setTimer(timer1, 1.0f);
	startTimer(timer1);
	for (int i = 1; i < 9; i++) {
		showObject(puzzlee[i]);
	}
}

void startGame2(int j) {
	int aX = X[8];
	X[8] = X[j];
	X[j] = aX;
	int aY = Y[8];
	Y[8] = Y[j];
	Y[j] = aY;
	locateObject(puzzlee[j + 1], scene2, X[j], Y[j]);
	locateObject(puzzlee[9], scene2, X[8], Y[8]);
	for (int i = 1; i < 9; i++) {
		showObject(puzzlee[i]);
	}
	if (X[0] == fX[0] && Y[0] == fY[0] && X[1] == fX[1] && Y[1] == fY[1] && X[2] == fX[2] && Y[2] == fY[2] && X[3] == fX[3] && Y[3] == fY[3] && X[4] == fX[4] && Y[4] == fY[4] && X[5] == fX[5] && Y[5] == fY[5] && X[6] == fX[6] && Y[6] == fY[6] && X[7] == fX[7] && Y[7] == fY[7]) {
		stopTimer(timer1);
		showMessage(buf);
		showObject(restartButton);
	}
}

void timerCallback(TimerID timer) {
	if (timer == timer1) {
		time = time + 1;
		setTimer(timer1, 1.0f);
		startTimer(timer1);
		sprintf(buf, "%d", time);
	}
}

void mouseCallback2(ObjectID object, int x, int y, MouseAction action) {
	if (object == startButton || object == restartButton) {
		startGame3();
	}
	for (int j = 0; j < 9; j++) {
		if (object == puzzlee[j + 1]) {
			if ((X[j] - 150 == X[8] && Y[j] == Y[8]) || (X[j] + 150 == X[8] && Y[j] == Y[8]) || (X[j] == X[8] && Y[j] - 150 == Y[8]) || (X[j] == X[8] && Y[j] + 150 == Y[8])) {
				startGame2(j);
			}
		}
	}

}



int main() {
	setMouseCallback(mouseCallback2);
	setTimerCallback(timerCallback);

	scene1 = createScene("퍼즐 게임", "C++back.png");
	scene2 = createScene("퍼즐 게임", "C++background.png");

	startButton = createObject("start.png", scene1, 590, 70, true);
	restartButton = createObject("restart.png", scene2, 590, 70, false);

	puzzlee[1] = createObject("C++_007.png", scene2, X[0], Y[0], false);
	puzzlee[2] = createObject("C++_008.png", scene2, X[1], Y[1], false);
	puzzlee[3] = createObject("C++_009.png", scene2, X[2], Y[2], false);
	puzzlee[4] = createObject("C++_004.png", scene2, X[3], Y[3], false);
	puzzlee[5] = createObject("C++_005.png", scene2, X[4], Y[4], false);
	puzzlee[6] = createObject("C++_006.png", scene2, X[5], Y[5], false);
	puzzlee[7] = createObject("C++_001.png", scene2, X[6], Y[6], false);
	puzzlee[8] = createObject("C++_002.png", scene2, X[7], Y[7], false);
	puzzlee[9] = createObject("C++_003.png", scene2, X[8], Y[8], false);
	timer1 = createTimer2(1.0f);

	showMessage("퍼즐을 맞추세요.");

	startGame(scene1);
}

