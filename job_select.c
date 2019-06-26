//小下作成




void graph_job(void){


	EzDrawStringB(380,105,"キャラクターを作成してください");

	EzDrawStringB(380,140,"学部：");
	EzDrawStringB(440,140,ch.name);
	
	int i;
	
	int set_x,set_y;
	set_x = 380; set_y = 200;
	int sub_x,sub_y;
	sub_x = 100; sub_y = 50;
	
	EzDrawStringB(set_x,set_y,"最大ＨＰ："); EzDrawIntB(set_x + sub_x,set_y,ch.hp_max);
	
	EzDrawStringB(set_x,set_y + sub_y,"atk");   EzDrawIntB(set_x + sub_x,set_y + sub_y,ch.atk);
	EzDrawStringB(set_x + ( 2 * sub_x),set_y + sub_y,"def"); EzDrawIntB(set_x + ( 3 * sub_x),set_y + sub_y,ch.def);
	
	EzDrawStringB(set_x,set_y + (2 * sub_y),"int");  EzDrawIntB(set_x + sub_x,set_y + ( 2 * sub_y),ch.inte);
	EzDrawStringB(set_x + ( 2 * sub_x),set_y + ( 2 * sub_y),"res"); EzDrawIntB(set_x + ( 3 * sub_x),set_y + ( 2 * sub_y),ch.res);
	
	if(menu_selected != 2)//特徴選択中は選択してる最中の組み合わせを出す
	for (i=0;i<CHARA_MAX;i++){
		EzDrawStringB(set_x,set_y + ( (3 + i) * sub_y),chara[ch.chara[i]]);
			EzSetFontSize(15);
		EzDrawStringB(set_x + sub_x ,set_y + (3+i) * sub_y,chara_ac[ch.chara[i]]);
			EzSetFontSize(20);
	}
	//魔法選択中は選択してる最中の内容をだす
	EzDrawStringB(550,350,mag[mag_selected[0]]);
	EzDrawStringB(550,380,mag_ac[mag_selected[0]]);
	
	EzDrawStringB(550,420,mag[mag_selected[1]]);
	EzDrawStringB(550,450,mag_ac[mag_selected[1]]);
	

	
}



void select_job(void){
	
	int set_x,set_y;//文字列の表示の座標を指定
	set_x = 200; set_y = 170;
	/////あとでfor文にできそうなので覚えてて時間に余裕があったらやる
	int i;
	
	for(i=0;i<JOB_MAX;i++){
		if(job_select == i)
		EzSetFontSize(30);
		else
		EzSetFontSize(20);
		EzDrawStringB(set_x,set_y + (30*i),job[i].name);
	}
	/*
  if(job_select == 0)
	EzSetFontSize(30);
  else
	EzSetFontSize(20);

  EzDrawStringB(set_x,set_y,job[0].name);


  if(job_select == 1)
	EzSetFontSize(30);
  else
	EzSetFontSize(20);

  EzDrawStringB(set_x,set_y + 30,job[1].name);
*/
	EzSetFontSize(20);

	explain();

}

void select_chara(void){
/*
  if(chara_select == 0)
	EzSetFontSize(30);
  else
	EzSetFontSize(20);
  EzDrawStringB(500,100,"かってきまま");

  if(chara_select == 1)
	EzSetFontSize(30);
  else
	EzSetFontSize(20);
  EzDrawStringB(500,130,"じゆうほんぽう");
*/	
	
	int i;
	int set_x,set_y;//文字列の表示の座標を指定
	set_x = 250; set_y = 170;
	int sub_x,sub_y;
	sub_x = 0; sub_y = 30;
	

	for (i = 0;i < CHARA_NUM;i++){
		if(chara_select == i)
		EzSetFontSize(30);
		else
		EzSetFontSize(20);
		EzDrawStringB(set_x + ( i * sub_x ), set_y + ( i * sub_y ),chara[i]);
	}

	EzSetFontSize(20);
	//一時的に特徴を格納するだけ
		for (i=0;i<CHARA_MAX;i++){
		EzDrawStringB(380,200 + ( (3 + i) * 50),chara[ch_chara[i]]);
				EzSetFontSize(15);
		EzDrawStringB(480,200 + (3+i) * 50,chara_ac[ch_chara[i]]);
				EzSetFontSize(20);
	}

		ch_explain();
}



void select_mag(void){
	int i;
	int set_x,set_y;//文字列の表示の座標を指定
	set_x = 250; set_y = 170;
	int sub_x,sub_y;
	sub_x = 0; sub_y = 30;
	

	for (i = 0;i < CH_MAG_NUM;i++){//一覧表示
		if(mag_select == i)
		EzSetFontSize(30);
		else
		EzSetFontSize(20);
		EzDrawStringB(set_x + ( i * sub_x ), set_y + ( i * sub_y ),mag[i]);
	}

	EzSetFontSize(20);
	/*
	EzDrawStringB(550,350,mag[ch.spe[0]]);
	EzDrawStringB(550,380,mag_ac[ch.spe[0]]);
	*/
	/*
		for (i=0;i<CH_MAG_MAX;i++){
		EzDrawStringB(380,200 + ( (3 + i) * 50),chara[ch_chara[i]]);
				EzSetFontSize(15);
		EzDrawStringB(480,200 + (3+i) * 50,chara_ac[ch_chara[i]]);
				EzSetFontSize(20);
	}
	*/
	mag_explain();	

}
void select_heal(void){
	int i;
	int set_x,set_y;//文字列の表示の座標を指定
	set_x = 250; set_y = 170;
	int sub_x,sub_y;
	sub_x = 0; sub_y = 30;
	

	for (i = CH_MAG_NUM;i < CH_SPE_NUM;i++){//一覧表示
		if(mag_select == i)
		EzSetFontSize(30);
		else
		EzSetFontSize(20);
		EzDrawStringB(set_x + ( (i-CH_MAG_NUM) * sub_x ), set_y + ( (i-CH_MAG_NUM) * sub_y ),mag[i]);
	}

	EzSetFontSize(20);

	heal_explain();
}

void select_ch(void){

 EzSetFont("IPA Pゴシック");
EzPutB(0,0,blue_title_pic);//タイトル背景を少し青くしたの
	int i;
	int set_x,set_y;
	set_x = 50; set_y = 80;
	int sub_x,sub_y;
	sub_x = 0;
	sub_y = 35;
	char menu_ch[5][64] = {
		"さぁ、単位を求めて出発だ",
		"学部を変える",
		"アピールポイント",
		"黒魔法を覚える",
		"白魔法を覚える"
	};
	
		if(ch_menu_select == 0)
		EzSetFontSize(30);
		else
		EzSetFontSize(20);
	EzDrawStringB(set_x,set_y - 30,menu_ch[0]);
	
	for(i=1;i<CH_MENU_MAX;i++){
		if(ch_menu_select == i)
		EzSetFontSize(30);
		else
		EzSetFontSize(20);
			 EzDrawStringB(set_x,set_y + (i*sub_y),menu_ch[i]);
	}

 /*
if(ch_menu_select == 0)
EzSetFontSize(30);
 else
   EzSetFontSize(20);
 EzDrawStringB(set_x ,set_y - 30,"さぁ、単位を求めて出発だ");

 if(ch_menu_select == 1)
   EzSetFontSize(30);
 else
   EzSetFontSize(20);
 EzDrawStringB(set_x,set_y + sub_y,"学部を変える");

 if(ch_menu_select == 2)
   EzSetFontSize(30);
 else
   EzSetFontSize(20);
 EzDrawStringB(set_x,set_y + ( 2 * sub_y),"アピールポイント");
*/

   EzSetFontSize(20);

   if(menu_selected == 0){
 // メニュー初期画面
	 set_explain();
   }

   if(menu_selected == 1){
 //  EzDrawStringB(200,200,"ジョブ選択中");
   select_job();
   }

   if(menu_selected == 2){
   //EzDrawStringB(200,200,"特徴選択中");
   select_chara();
   }
	else{//特徴選択に入る前の初期化をここで
	chara_select_num = 0;
		for (i=0;i<CHARA_MAX;i++)
		ch_chara[i]=0;
	}
	if(menu_selected == 3){
		//EzDrawStringB(魔法くろの選択中)
		select_mag();
	}
	if(menu_selected == 4){
	select_heal();
}
	EzDrawStringB(600,550,"z:決定");
	EzDrawStringB(600,570,"x:キャンセル");	
	graph_job();

}
