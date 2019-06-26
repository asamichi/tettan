//小下作成
#define GLOBAL_INSTANCE
//#define debug_now 


#include "HEAD.h"
//ezcc main.c -lEzGraph



void timer_handler(void){
    EzQueryKeymap(keys);
  switch(state){
  case s_ini_title ://タイトルより前
	ini_title();
	break;
  case s_title://タイトル
		title_top();
	break;
  case s_menu_title://タイトルメニュー画面
	title_menu();
	break;
  case s_hi_score:
  	hiscore();
  	break;
  case s_ini_select_ch:
  	load_job();
  	ch = job[0];
  	ch_menu_select =1;
  	state = s_select_ch;
  case s_select_ch://ジョブ選択とか
	select_ch();
	break;
  case s_select_stage://ステージ選択画面（実装未定）
	strcpy(story_name,"./csv/debug.csv");
  	load_story(story_name);
  	con=0;
	state = s_ini_battle;
  	cnt =0;
  	ene_atk_cnt = cnt;
	break;
  case s_ini_battle:
  	ini_battle();
  	state = s_battle;
  	break;
  case s_battle://ゲーム本編
	battle_main();
	break;
  case s_battle_clear:
  	EzDrawStringB(100,100,"ステージクリア!!");
  	EzDrawStringB(100,200,"また別の組み合わせでも遊んだりしてね！");
  	EzDrawStringB(100,300,"Please_press_z");
  	clear=1;
  	break;
  case s_game_over:
  	EzDrawStringB(100,100,"ゲームオーバー");
  	EzDrawStringB(100,200,"Pleas_press_z");
  	clear=0;
  	break;
  case error_ene_max:
  	 EzDrawStringB(100,100,"敵登録数がオーバー");
  	break;
  case error_read_job:
  	EzDrawStringB(100,100,"ジョブファイルがありません");
  	break;
    case error_job_max:
  	 EzDrawStringB(100,100,"ジョブ登録数がオーバー");
  	break;
  case error_read_story:
  	 EzDrawStringB(100,100,"ストーリーファイルがありません");
  	break;
  case s_check_score:
  	show_score();
  	break;
  }
  
  //  EzPutB(0,0,title_pic);
  debug();
  cnt++;

  EzShowBuffer();

}


/* キーボードハンドラ（キーボードが押された時に呼び出される関数） */
void key_handler(int key){
	int i,j;
	DATA n ;
	

  switch(state)
	{
	case s_title:
			   if(key=='z'){
		 state=s_menu_title;
		 menu_select == 0;//めんどいのでここでタイトルメニューの初期化
	   }
		break;
	case s_menu_title://タイトルのメニュー画面
	  if(key==EZ_Up)
		if(menu_select != 0)
		  menu_select--;

	  if(key==EZ_Down)
		if(menu_select != MENU_MAX - 1)
		  menu_select++;

	  //こっちでstateもいじるンゴ
	  if(key == 'z'){
   		if(menu_select == 0){
		state=s_ini_select_ch;
		}
		if(menu_select == 2){
		  exit(1);
		}
	  	if(menu_select == 1)
	  	state = s_hi_score;
	  }
	  break;
	case s_hi_score:
		if(key=='x')
		state=s_menu_title;
		break;

	case s_select_ch://キャラ選択
		
	  if(menu_selected == 0){//ジョブとか特徴メニュー選択
		if(key==EZ_Up)
		  if(ch_menu_select != 0)
			ch_menu_select--;
		if(key==EZ_Down)
		  if(ch_menu_select != CH_MENU_MAX-1)
			ch_menu_select++;

		if(key == 'z'){
		  if(ch_menu_select == 0)
			state = s_select_stage;
		  if(ch_menu_select == 1)
			menu_selected = 1;
		  if(ch_menu_select == 2)
			menu_selected = 2;
			if(ch_menu_select == 3){
			menu_selected = 3;
				mag_select=0;
			}
			if(ch_menu_select == 4){
				mag_select=CH_MAG_NUM;
			menu_selected = 4;
		}
		}
		if(key == 'x')
			state = s_menu_title;//タイトルに戻る
	  }
		else
			if(menu_selected == 1){//ジョブ選択なう
		if(key==EZ_Up)
		  if(job_select != 0)
			job_select--;
		if(key==EZ_Down)
		  if(job_select != JOB_MAX-1)
			job_select++;
	  	
	  	if(key == 'z')
	  	ch = job[job_select];

		if(key == 'x'){
		  job_select = 0;
		  menu_selected = 0;//キャラ選択へ
		}
	  }
		else
		  if(menu_selected == 2){//特徴選択なう
		if(key==EZ_Up)
		  if(chara_select != 0)
			chara_select--;
		if(key==EZ_Down)
		  if(chara_select != CHARA_NUM-1)
			chara_select++;
		  	
		  	if(key == 'z'){
		  		ch_chara[chara_select_num] = chara_select;
		  		chara_select_num ++;
		  		if(chara_select == 0){//特に無いを選択したらキャラ作成へ戻る
		  			for(i=0;chara_select_num != CHARA_MAX;i++){
		  				ch_chara[chara_select_num] = 0;
		  				chara_select_num++;
		  			}
		  		}
		  		if(chara_select_num == CHARA_MAX){//特徴を５個選らんだら
		  			for(i=0;i<CHARA_MAX;i++){
		  				ch.chara[i] = ch_chara[i];
		  				for(j=0;j<JOB_MAX;j++){
		  					job[j].chara[i] = ch_chara[i];
		  				}		  
		  			}
		  			menu_selected = 0;//キャラ作成へ戻る
		  			}
		  		}
		  
		  	if(key == 'x'){
		  menu_selected = 0;//キャラ選択へ
		  chara_select = 0;
		}
		  }
		if(menu_selected == 3){//魔法選択なう
			if(key == EZ_Up)
			if(mag_select != 0)
			mag_select--;
			
			if(key == EZ_Down)
			if(mag_select != CH_MAG_NUM - 1)
				mag_select++;
				
				if(key == 'z')
				mag_selected[0] = mag_select;
			
		if(key == 'x'){
		  menu_selected = 0;//キャラ選択へ
		}
		}
		if(menu_selected ==4){//白魔法選択なう
			if(key == EZ_Up)
			if(mag_select != CH_MAG_NUM )
			mag_select--;
			
			if(key == EZ_Down)
			if(mag_select != CH_SPE_NUM -1)
			mag_select++;
			
			if(key=='z')
			mag_selected[1] = mag_select;
			if(key == 'x')
			menu_selected=0;
		}
		
		break;
	case s_game_over:
	case s_battle_clear:
		if(key == 'z')
		state = s_check_score;
		break;
	case s_battle:
		n = current;
 
   if(key=='x'){     //Zで回転
    n.form++;
  }
		
   if(key=='z'){     //Xで回転
    n.form+=blocks[n.type].form-1;
  }

		update_current(n);
		
		if(key == EZ_Up)
		while( !blockDown()){
		score ++;	
		}

		
		break;
	case s_check_score:
		if(key=='z'){
		state=s_title;
			hi_score[RANK_NUM + 1] = clear_score;
				arrange();
	put_score();
		}
		if(key=='x' && con != 3)
		{
			con++;
			ini_battle();
			enemy[enemy_num].hp=enemy[enemy_num].hp_max;
			state=s_battle;
			
		}
		
	}		
}



int main(){

  //ini
  EzOpenWindow(800,600);
  cnt=0;
  score=0;
  state=s_title;//(stateの初期化)
 logo_pic=EzReadXPM(Group_log_xpm);
	ini_title();
	  EzShowBuffer();

	
  title_pic=EzReadXPM(title_light_xpm);
  press_z_key_pic=EzReadXPM(Press_z_logo_xpm);
  game_start_pic=EzReadXPM(game_start_xpm);
  game_end_pic=EzReadXPM(game_end_xpm);
  game_start_wait_pic=EzReadXPM(game_start_wait_xpm);
  game_end_wait_pic=EzReadXPM(game_end_wait_xpm);
	high_score_pic=EzReadXPM(high_score_xpm);
	high_score_wait_pic=EzReadXPM(high_score_wait_xpm);
  blue_title_pic=EzReadXPM(blue_title_xpm);
  boad_pic=EzReadXPM(boad_xpm);
	hi_score_pic=EzReadXPM(hi_score_xpm);
	enemy_pic[0]=EzReadXPM(ene_01_xpm);
	enemy_pic[1]=EzReadXPM(ene_02_xpm);
	enemy_pic[2]=EzReadXPM(ene_03_xpm);
	enemy_pic[3]=EzReadXPM(ene_04_xpm);
	enemy_pic[4]=EzReadXPM(ene_05_xpm);
	enemy_pic[5]=EzReadXPM(ene_06_xpm);
	enemy_pic[6]=EzReadXPM(ene_07_xpm);
	enemy_pic[7]=EzReadXPM(ene_08_xpm);
	enemy_pic[8]=EzReadXPM(ene_09_xpm);
	enemy_pic[9]=EzReadXPM(ene_10_xpm);
	enemy_pic[10]=EzReadXPM(ene_11_xpm);
	enemy_pic[11]=EzReadXPM(ene_12_xpm);
	enemy_pic[12]=EzReadXPM(ene_13_xpm);

	load_score();

//	haruka_pic = EzReadXPM(haruka_xpm);
//	teki_pic = EzReadXPM(teki_xpm);
	


 

    /* キーイベントハンドラを登録する */
	// EzSetKeyHandler()関数を用いてkey_handler()関数を登録する
	EzSetKeyHandler(key_handler);


    /* タイマーイベントハンドラを登録する 
    EzSetTimerHandler()関数を用いて50ミリ秒毎に
    timer_handler()関数を呼び出してもらうように登録する */
	EzSetTimerHandler(timer_handler,17);//一秒に50回


    /* イベント待ち */
    EzEventLoop();

    /* 
     * 通常は、EzEventLoop()関数の中でイベントを待ち続けるので、
     * ここに到達することはない 
     */
    return 0;
}


