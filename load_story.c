/* 作成者：山下大志 */






void load_story(char fname[256]){
	//ファイルネームを受け取ってそれを読むように引数付けました。あとezの仕様に少し調整しました（小下）
    int n, num, i;
   // char fname[256] = { "./tes3.csv" };
    int input[64];
    char inputc[64];
	FILE *fp;
    char str;


 
    fp = fopen(fname, "r");//ファイル読み込み
    if (fp == NULL){
       // printf("read error\n"); printfは使えない
    	state = error_read_story;
        return;
    }
    for (i = 0; i<2; i++)//最初の2行読み飛ばす
	  while ((str = fgetc(fp)) != '\n');
     n = 0, num = 0;
    while (1){
        for (i = 0; i<64; i++){
            inputc[i] = input[i] = fgetc(fp);//1文字取得する
            if (input[i] == ',' || input[i] == '\n'){//カンマか改行なら
                inputc[i] = '\0';//そこまでを文字列とし
                break;
            }
            if (input[i] == EOF){//ファイルの終わりなら
            	enemy_max = n;//敵が何体いるのか保持するように（小下）
              return ;
            }
        }

switch (num){

 case 0:  enemy[n].flag = atoi(inputc); break;
 case 1:  enemy[n].lookknd = atoi(inputc); break;
 case 2:  enemy[n].encnt = atoi(inputc); break;
 case 3:  enemy[n].state = atoi(inputc); break;
 case 4:  enemy[n].hp_max = atoi(inputc); break;
 case 5:  enemy[n].hp = atoi(inputc); break;
 case 6:  enemy[n].atk = atoi(inputc); break;
 case 7:  enemy[n].def = atoi(inputc); break;
 case 8:  enemy[n].inte = atoi(inputc); break;
 case 9:  enemy[n].res = atoi(inputc); break;
 case 10: enemy[n].hit = atoi(inputc); break;
 case 11: enemy[n].spd = atoi(inputc); break;
 case 12: enemy[n].atk_num = atoi(inputc); break;
 case 13: enemy[n].spe[0] = atoi(inputc); break;
 case 14: enemy[n].spe[1] = atoi(inputc); break;
 case 15: enemy[n].spe[2] = atoi(inputc); break;
 case 16: enemy[n].spe[3] = atoi(inputc); break;
 case 17: enemy[n].spe[4] = atoi(inputc); break;
// case 18: enemy[n].spe[5] = atoi(inputc); break;
 }
num++;
if (num == 18){
  num = 0;
  n++;
 
 }
    	//配列がそこまであるかチェックを追加（小下）
    	if( n > ENE_MAX ){
    		state = error_ene_max;
    		}
    }
}

