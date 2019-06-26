// 山下大志　が作成//

void explain(void){

  char inf[5][100] = {"賢い人が多いのだが度重な","る徹夜により体が弱く耐久性もない。","知識はあるので魔法に対する","ステータスは高い。麻雀牌を","投げつける攻撃は意外と強い。"};

  char phy[5][100] = {"物理を学んだ結果物理攻撃を","極めるに至ったが、その過程で","魔法が弱くなってしまった。","現実の事象には滅法強いが、","魔法に対する耐性は弱い。"};

  char mac[5][100] = {"機械で攻撃をするのが得意。","機械に頼りきりなので、自身の","耐久性はあまり高くない","魔法に関しては攻守共に","ごくごく普通"};
 
  char ply[5][100] = {"しっかり睡眠をとるので体力は","理系大学生と比べて高く","夢の世界で魔法も学んだ。","徹夜カラオケ・飲み会の達人。","従って全体的に耐久性が低い。"};

  char med[5][100] = {"人体の構造を理解していて、","物理攻撃に無駄が無さすぎ。","多忙な毎日で体力と耐久性は","とてつもなく低い。","知識は圧倒的で、魔法に特化。"};
 
  char piro[5][100] = {"全てを悟った猛者","良い意味では言ってない。","入院経験があり、体は弱い。","知識もやる気も微妙。","大学の意味とは何ぞや"};
  
  EzSetFontSize(23);

  int i, j;

  for(i = 0; i < 5; i++)
	{
	  for(j = 0; j < 1; j++)
		{
		  if (job_select == 0)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&inf[i][j]);

		  else if (job_select == 1)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&phy[i][j]);

		  else if (job_select == 2)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&mac[i][j]);

		  else if (job_select == 3)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&ply[i][j]);

		  else if (job_select == 4)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&med[i][j]);

		  else if (job_select == 5)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&piro[i][j]);


		  }
		}	  
	
  EzSetFontSize(20);
}

void ch_explain(void){

  char non[4][100] = {"これと言って目立った","長所・短所はない。"};

  char hpm[4][100] = {"常日頃から健康的な生活を","送っている。HPが10+"};

  char pwm[4][100] = {"体を鍛えて力がついた。","(どうやって鍛えたのかは","敢えて伏せておく)","atkが5+"};

  char dfm[4][100] = {"屈強な精神の持ち主は","外部からの攻撃にも強い。","defが5+"};

  char gen[4][100] = {"優秀な頭の持ち主。","魔法を使うには医学以上の","知識が必要だったりする。","intが5+"};

  char gme[5][100] = {"屈強な精神を別方面に昇華","させてしまったという猛者。","方法は不明だが、精神論","だけで魔法攻撃を弱める","resが5+"};

  EzSetFontSize(23);

  int i, j;

  for(i = 0; i < 4; i++)
	{
	  for(j = 0; j < 1; j++)
		{
		  if (chara_select == 0)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&non[i][j]);

		  else if (chara_select == 1)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&hpm[i][j]);

		  else if (chara_select == 2)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&pwm[i][j]);

		  else if (chara_select == 3)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&dfm[i][j]);

		  else if (chara_select == 4)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&gen[i][j]);

		  else if (chara_select == 5)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&gme[i][j]);

		}
	}
  EzSetFontSize(20);
}

void mag_explain(void){

  char fai[2][100] = {"圧倒的知識量に敗北。","魔法を使うことが出来ない。"};

  char fir[2][100] = {"ファイヤーーーー","ーーーーーー！"};

  char ice[2][100] = {"アイスストーーー","ーーーーーム！"};

  char bra[2][100] = {"ブレイン！","ダムドーーーーーー！"};

  char zyg[2][100] = {"ZYU★GE★MU！！！！"};

  char bay[2][100] = {"ばよえーーーーー","ーーーーーん！"};

  EzSetFontSize(23);

  int i, j;

  for(i = 0; i < 2; i++)
	{
	  for(j = 0; j < 1; j++)
		{
		  if (mag_select == 0)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&fai[i][j]);

		  else if (mag_select == 1)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&fir[i][j]);

		  else if (mag_select == 2)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&ice[i][j]);

		  else if (mag_select == 3)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&bra[i][j]);

		  else if (mag_select == 4)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&zyg[i][j]);

		  else if (mag_select == 5)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&bay[i][j]);
		}
	}
  EzSetFontSize(20);
}

void heal_explain(void){

  char noh[2][100] = {"回復してる暇があったら","攻撃しろ攻撃！(大激怒)"};
 
  char stp[2][100] = {"stap細胞は……","ありまあぁす！！！"};

  char hel[2][100] = {"盗人ではありません。","回復です。"};

  char cae[2][100] = {"某えふえふっぽいアレ。","えふえふが好きな貴方に。"};
  char hoi[2][100] = {"某でぃーきゅーっぽいアレ。","でぃーきゅーが好きな貴方に。"};

  char rec[2][100] = {"某えぐぜっぽいアレ。","えぐぜが好きな貴方に。"};


  EzSetFontSize(23);

  int i, j;

  for(i = 0; i < 2; i++)
	{
	  for(j = 0; j < 1; j++)
		{
		  if (mag_select == 6)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&noh[i][j]);

		  else if (mag_select == 7)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&hoi[i][j]);

		  else if (mag_select == 8)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&cae[i][j]);

		  else if (mag_select == 9)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&hel[i][j]);

		  else if (mag_select == 10)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&rec[i][j]);

		  else if (mag_select == 11)
			EzDrawStringB(30 + 30 * j,360 + 35 * i,&stp[i][j]);

		}
	}
  EzSetFontSize(20);
}

void set_explain(void){

  char set[8][100] = {"よくぞ参られた、勇者三重大学生殿。","貴殿の学部と特徴,魔法を","選択してくだされ。","決定はｚ,一つ前に戻るときはｘを","入力して欲しい。","準備ができたら一番上の","「さぁ、単位を求めて出発だ」を","選んで決定を押してくれ。"};

  EzSetFontSize(23);

  int i, j;

  for(i = 0; i < 8; i++)
	{
	  for (j = 0; j < 1; j++)
		{
		  EzDrawStringB(19 + 30 * j,320 + 35 * i,&set[i][j]);
		}
	}

  EzSetFontSize(20);
}
