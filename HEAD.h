//小下作成
//ヘッダファイル追加
#include <stdio.h>
#include <stdlib.h>
#include <EzGraph.h>
#include <string.h>
#include "define.h"//マクロの定義
#include "struct.h"//構造体の定義
#include "GV.h"//グローバル変数の定義

void EzDrawIntB(int x,int y,int num){
	char print_ch[64];
	sprintf(print_ch,"%d",num);
	EzDrawStringB(x,y,print_ch);
}
//EzGraphでは不便なのでちょっと拡張


//こっから画像
#include "./img/title_light.xpm"
#include "./img/Group_log.xpm"
#include "./img/Press_z_logo.xpm"
#include "./img/game_start.xpm"
#include "./img/game_end.xpm"
#include "./img/game_start_wait.xpm"
#include "./img/game_end_wait.xpm"
#include "./img/high_score.xpm"
#include "./img/high_score_wait.xpm"
#include "./img/blue_title.xpm"
#include "./img/boad.xpm"
#include "./img/kerokeroicon.xpm"

#include "./img/haruka.xpm"
#include "./img/teki.xpm"
#include "./img/hi_score.xpm"

#include "./img/block/S.xpm"
#include "./img/block/T.xpm"
#include "./img/block/I.xpm"
#include "./img/block/Z.xpm"
#include "./img/block/J.xpm"
#include "./img/block/L.xpm"
#include "./img/block/O.xpm"

#include "./img/enemy/ene_01.xpm"
#include "./img/enemy/ene_02.xpm"
#include "./img/enemy/ene_03.xpm"
#include "./img/enemy/ene_04.xpm"
#include "./img/enemy/ene_05.xpm"
#include "./img/enemy/ene_06.xpm"
#include "./img/enemy/ene_07.xpm"
#include "./img/enemy/ene_08.xpm"
#include "./img/enemy/ene_09.xpm"
#include "./img/enemy/ene_10.xpm"
#include "./img/enemy/ene_11.xpm"
#include "./img/enemy/ene_12.xpm"
#include "./img/enemy/ene_13.xpm"






//こっからｃファイル追加していく、コンパイルのコマンド長くなるのめんどかった
//ぶっちゃけexternがこれのせいで要らなくなったけどまぁいいや
//ほんとはファイルをまたぐ変数は減らした方がバグが減る（関数の返り値でやり取りさせて、必要ない値は他のファイルからは見えないように云々
#include "load_job.c"
#include "debug.c"//デバッグ用
#include "title.c"//タイトルより前のやつ
#include "explain.c"
#include "job_select.c"//ジョブ選択ステージ選択
#include "tetris3.c"//テトリス
#include "stage.c"//ステージ本体
#include "load_story.c"//ストーリー読み込み
#include "stage_ini.c"//ステージ開始前の初期化
#include "show_score.c"



