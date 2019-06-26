//小下作成

int hi_score[RANK_NUM+1];
/*
typedef struct{
	int score;
	char name[64];
}rank_t;

rank_t hi_score[RANK_NUM];
*/
void load_score(void)
{
FILE *fp;


	int i=0;
	char st[64];
	fp = fopen("./sav/save.txt","r");
/*	while(fscanf(fp,"%s%d",hi_score[i].name,&hi_score[i].score) == 2)
	i++;
	
	fclose(fp);
	
	printf("load\n");*/
	for(i=0;i<RANK_NUM;i++){	
	fgets(st,64,fp);
	hi_score[i]=atoi(st);
}

}

void put_score(void){
	FILE *fp;
	int i;
	fp = fopen("./sav/save.txt","w");
	for(i=0;i<RANK_NUM;i++){
	//	fprintf(fp,"%s %d/n",hi_score[i].name,hi_score[i].score);
		fprintf(fp,"%d\n",hi_score[i]);
	}
	fclose(fp);

}

		
		
		

void hiscore(void){
	EzPutB(0,0,hi_score_pic);
	int i;
	int x,y,sx,sy;
	x=250;y=300;sx=100;sy=30;
	EzSetFontSize(40);
	EzDrawStringB(245,250,"ハイスコアランキング");
	for(i=0;i<RANK_NUM;i++){
		if(i==1){
		EzSetFontSize(20);
			y-=30;
		}
		EzDrawIntB(x-10,y+(i*sy),i+1);
		EzDrawStringB(x+20,y+(i*sy),"位");
		//EzDrawStringB(x+sx,y+(i*sy),hi_score[i].name);
		EzDrawIntB(x+(sx),y+(i*sy),hi_score[i]);
		if(i==0)
		y+=30;
		}
	
	EzDrawStringB(600,570,"x:タイトルに戻る");	
}


int arrange(void) //数値を小さい順に並び替える
{
	int check2;
	int i,a;
	do 
	{
	
		check2=0;//フラグ初期化
		
	for(i=0 ; i<RANK_NUM+1 ;i++) //繰り返す宣言
	{
		if(hi_score[i]<hi_score[i+1])//もし並びがきれいじゃないなら実行
		{
			a=hi_score[i+1];
			hi_score[i+1]=hi_score[i];
			hi_score[i]=a;			//数値の入れ替え
			
			check2=1;//変更したフラグを立てる
		}
		
		}
	}while(check2==1);
		
	return(0);
}


void ini_title(void)
{
  EzSetColorByName("White");//裏描写、白指定
  EzFillBoxB(0,0,800,600);//タイトルの背景用の長方形
  EzPutB(0,0,logo_pic);
	mag_selected[0]=0;
	mag_selected[1]=6;
}


void title_top(void)
{

  EzPutB(0,0,title_pic);//タイトル背景
  if(cnt>press_tmp+20)//press z keyの点滅用
	 {
	   press_tmp=cnt;
	   if(press_flag==1)
		 press_flag=0;
	   else
		 press_flag=1;
	 }

	   if(press_flag==1)
		 EzPutB(0,0,press_z_key_pic);//ここまでpress z key




}

void title_menu(void){
 EzPutB(0,0,title_pic);//タイトル背景

 //長押し判定作りたいけど時間の都合で仕方なく妥協
 //時間合ったらキーハンドラーじゃなくする予定
 //menu_selectはキーハンドラーでいじってる
 if(menu_select == 0)
	 EzPutB(0,0,game_start_pic);
   else
	 EzPutB(0,0,game_start_wait_pic);

   if(menu_select == 2)
   EzPutB(0,0,game_end_pic);
   else
	 EzPutB(0,0,game_end_wait_pic);
	
	if(menu_select== 1)
	EzPutB(0,0,high_score_pic);
	else 
	EzPutB(0,0,high_score_wait_pic);
	EzSetFontSize(20);


}
