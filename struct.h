//コシタ作成
#include "define.h"//マクロの定義ファイル

typedef struct{
//フラグ、見た目、出現するカウンタ、状態（カウンタいらないかも)
int flag,lookknd,encnt,state;
//最大HP,HP,攻撃力、防御力、魔力、魔法防御、命中力、スピード、攻撃間隔のフレーム、特技番号の配列、
 int hp_max,hp,atk,def,inte,res,hit,spd,atk_num,spe[SPE_MAX];
}enemy_t;

typedef struct{
//最大HP、HP,最大MP,mp,攻撃力、防御力、魔力、魔法防御、命中力、スピード,特技、特徴
  int hp_max,hp,mp_max,mp,atk,def,inte,res,hit,spd,spe[CH_MAG_MAX],chara[CHARA_MAX];
	int  job_name;//職業名
	char name[64];//職業名のままにするかもしらん
	//判別に使おうかと思って名前intとchar両方作ったけどいらんかったかもしらん
	int mag;//０は未所持
}ch_t;
//hit,spdは実装未定、特技も実装未定、特徴はつける予定

