/*
the main Running Activities
MaikazeSekai
*/

#include "SDL.h"
#include <iostream>

#include "header\[Core]Sound.h"
#include "header\Bg.h"
#include "header\Chara.h"
#include "header\Item.h"
#include "header\Npc.h"
#include "header\Se.h"
#include "header\Ui.h"
#include "header\Voice.h"

using namespace std;

int main(int argc, char * argv[])
{
	int i;
	SoundSys snd;
	snd.Load(BGM, "z:/1.ogg");
	cin >> i;
	cin >> i;
	//snd.Pause();
	cin >> i;
	//snd.Resume();
	cin >> i;
	return 0;
}