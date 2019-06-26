//小下作成


void ini_battle(void){
	int i;
	
	cnt = 0;
	score = 0;

	ene_atk_cnt = 0;
	sub_score = 0;
	fall_block = 0;
	sub_fall_block = 0;
	deleted_line = 0;
	deleted_line_flag =0;
	clear=0;
	clear_score=0;
	enemy_cnt=0;

for(i=0;i<CH_SPE_NUM+1;i++){
	sub_deleted_line[i] = 0;
}
//ここまで値の初期化

	if(con == 0){
			non_bornus=0;
			enemy_num = 0;
//こっから特徴の分のステータスを補正
for(i=0;i<CHARA_MAX;i++){//キャラの特徴枠を探査
	switch (ch.chara[i]){//特徴名は原案で記入してある、後に変更の可能性あり
	case 0	://特に無し
		non_bornus++;
		break;
	case 1://体力に自信がある
		ch.hp_max += 10;
		break;
	case 2://力持ち
		ch.atk += 5;
		break;
	case 3://打たれ強い
		ch.def += 5;
		break;
	case 4://インテリ
		ch.inte += 5;
		break;
	case 5://折れない心
		ch.res += 5;
		break;
	}
}
	}
	ch.spe[0] = mag_selected[0];
	ch.spe[1] = mag_selected[1];
	ch.hp = ch.hp_max;//増えた分のＨＰちゃんと増やす
		
		
		
		
		
	
  CREATE();
	
	
}





