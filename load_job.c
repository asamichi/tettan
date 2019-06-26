/* 作成者：山下大志 を　小下が改変した物 */






void load_job(void){
	
    int n, num, i;
   char fname[256] = { "./csv/job.csv" };
    int input[64];
    char inputc[64];
	FILE *fp;
    char str;
	
	//文字列のｃｓｖからの読み込みが表示がうまくいかんしバグつぶす時間惜しいので初期化でやっつける
	strcpy(job[0].name,"情報工学科");
	strcpy(job[1].name,"物理工学科");
	strcpy(job[2].name,"機械工学科");
	strcpy(job[3].name,"人文学部");
	strcpy(job[4].name,"医学部");
	strcpy(job[5].name,"１２年目");


 
    fp = fopen(fname, "r");//ファイル読み込み
    if (fp == NULL){
       // printf("read error\n"); printfは使えない
    	state = error_read_job;
        return;
    }
	

    for (i = 0; i<2; i++)//最初の2行読み飛ばす
	  while ((str = fgetc(fp)) != '\n');
     n = 0, num = 0;
    while (1){
        for (i = 0; i<64; i++){
            inputc[i] = input[i] = fgetc(fp);//1文字取得する
			/*          if (inputc[i] == '/'){//スラッシュがあれば
			  while (fgets(fname,sizeof(fname), fp) != '\n');//改行までループ
                i = -1;//カウンタを最初に戻して
				}*/
            if (input[i] == ',' || input[i] == '\n'){//カンマか改行なら
                inputc[i] = '\0';//そこまでを文字列とし
                break;
            }
            if (input[i] == EOF){//ファイルの終わりなら
            //	enemy_max = n;//敵が何体いるのか保持するように（小下）
              return ;
            }
        }
    //	printf("%s\n",inputc);

switch (num){

 case 0:  job[n].hp_max = atoi(inputc); break;
 case 1:  job[n].hp = atoi(inputc); break;
 case 2:  job[n].mp_max = atoi(inputc); break;
 case 3:  job[n].mp = atoi(inputc); break;
 case 4:  job[n].atk = atoi(inputc); break;
 case 5:  job[n].def = atoi(inputc); break;
 case 6:  job[n].inte = atoi(inputc); break;
 case 7:  job[n].res = atoi(inputc); break;
 case 8:  job[n].hit = atoi(inputc); break;
 case 9: job[n].job_name = atoi(inputc); break;
 }
num++;
if (num == 10){
 // printf("%d\n",n);
  num = 0;
  n++;
 
 }
    	//配列がそこまであるかチェックを追加（小下）
    	if( n > JOB_MAX ){
    		state = error_job_max;
    		}
    }
}

