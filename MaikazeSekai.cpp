/*
the main Running Activities
MaikazeSekai
*/

#include "SDL.h"
#include <iostream>

#include "header\Bg.h"
#include "header\Bgm.h"?
#include "header\Chara.h"
#include "header\Item.h"
#include "header\Npc.h"
#include "header\Se.h"
#include "header\Ui.h"
#include "header\Voice.h"

using namespace std;

int main(int argc, char * argv[])
{
	BgmMgr m_bgm;
	m_bgm.PlayBGM("z:\\2.mp3", -1);
	getchar();
	return 0;
}