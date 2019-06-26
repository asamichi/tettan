//小下作成


void show_score(void){

	int x,y,sx,sy;
	int i;
	int tmp;
	int flag;
	flag=0;
	tmp=0;
	x=110;y=150;
	sx=300;sy=35;
	EzDrawStringB(x,y,"倒した敵の数");
	EzDrawIntB(x+sx,y,enemy_num);
	tmp++;
	
	EzDrawStringB(x,y+sy,"消したラインの数");
	EzDrawIntB(x+sx,y+sy,deleted_line);
	tmp++;
	
	
	EzDrawStringB(x,y+(tmp*sy),"スコア");
	EzDrawIntB(x+sx,y+(tmp*sy),score);
	tmp++;
	
	EzDrawStringB(300,y+(tmp*sy),"トータルスコア");
	tmp++;
char st[256];
	//スコア＋（消したライン＊３００）＋倒した敵の数＊１０００＋クリアボーナス
	EzDrawStringB(x-80,y+(tmp*sy),"スコア+(消したライン*３０)+(倒した敵の数*1000)");
	tmp++;

	clear_score=score+(deleted_line*30) + (enemy_cnt*1000);
	
	if(clear==1){
		EzDrawStringB(x,y+(tmp*sy),"クリアボーナス 10000");
		clear_score+=10000;
		tmp++;
	}

	if(non_bornus!=0){
		clear_score+= 1000 * non_bornus;
		EzDrawStringB(x,y+(tmp*sy),"特徴なしボーナス 特徴無し*1000");
		tmp++;
	}
	
	if(ch.spe[0]==0){
		if(clear==1){
			EzDrawStringB(x,y+(tmp*sy),"攻撃魔法なしクリアボーナス 10000");
			clear_score+=10000;
		}
		else{
		EzDrawStringB(x,y+(tmp*sy),"攻撃魔法なしボーナス 5000");
			clear_score+=5000;
		}
		tmp++;
	}
	
	if(ch.spe[1]==6){
	clear_score+=8000;
		EzDrawStringB(x,y+(tmp*sy),"回復魔法なしボーナス 8000");
		tmp++;
	}

	EzSetFontSize(30);
	EzDrawIntB(350,y+(tmp*sy),clear_score);
	tmp++;
	EzSetFontSize(20);
	
	EzDrawStringB(500,520,"ｚ：タイトルに戻る");
	EzDrawStringB(500,550,"ｘ：コンティニュー（スコアは０に）");
	EzDrawStringB(500,580,"コンティニューは３回まで");
	
}
