/*
#include <stdio.h>
#include <EzGraph.h>
#include <stdlib.h>
*/
#define NEXT_X (285+5)
#define NEXT_Y (80+10)
 
#define SET_WAIT (1)
 
static const int true = 1;
static const int false = 0;
 
 
/////構造体{
 
 
//ブロックの作成
typedef struct{
  int x,y;
}POSITION;
 

typedef struct{
  int form;    //回転の種類
  POSITION p[3];
}BLOCKS;
 
BLOCKS blocks[8] = {
  {1, { {0, 0}, { 0,0}, { 0,0} } }, //なし
  {2, { {0,-1}, { 0,1}, { 0,2} } }, //棒
  {4, { {0,-1}, { 0,1}, { 1,1} } }, //L字1
  {4, { {0,-1}, { 0,1}, {-1,1} } }, //L字2
  {2, { {0,-1}, { 1,0}, { 1,1} } }, //key1
  {2, { {0,-1}, {-1,0}, {-1,1} } }, //key2
  {1, { {0, 1}, { 1,0}, { 1,1} } }, //正方形
  {4, { {0,-1}, { 1,0}, { 0,1} } }, //T字
};
 
//ブロック落下中のデータ
typedef struct{
  int x;
  int y;
  int type;
  int form;
}DATA;
 
/////構造体}
 
 
 
//グローバル変数{
 
/*
int fall_block = 0;    //落ちたブロックのカウント
int deleted_line = 0;      //消したラインのカウント
int score = 0;             //スコア
*/
 
//グローバル変数}
 
EzImage blockImage[8];
int field[12][25] =  {{0}} ;   
int next_field[4][4] = {{0}};

#define USE_KEYBOAD_NUM 2
int input_wait[USE_KEYBOAD_NUM]; 

DATA current;              //ブロック落下中のデータ
DATA next; 
//CREATE{
 
   
 
//ブロックを置く、回転の関数
 
int putBlock(DATA d,int action){
 
  int dx,dy,mod,i,j,nx,ny;
  if (field[d.x][d.y] != 0) {     //ブロックを置くフィールドが0(壁じゃない)の確認、もし1(壁や床)だったらfalseを返す
    return false;
  }
 
  if (action) {                  //はじめはfalseで何もしない(置けるかの確認)がtrueだとブロックを設置する
    field[d.x][d.y] = d.type;
  }
 
  for (i = 0; i < 3; i++){      //それぞれのブロックを１パーツごとに設定
    dx = blocks[d.type].p[i].x;
    dy = blocks[d.type].p[i].y;
    mod = d.form % blocks[d.type].form;  //ブロックの回転パターン数の最大
    for (j = 0; j < mod; j++){
      nx = dx, ny = dy;
      dx = ny; dy = -nx;
    }
    if (field[d.x + dx][d.y + dy] != 0) {  //移動後のパーツが壁や床じゃないかの判定
      return false;
    }
    if (action){                    //trueだとブロックを設置する
      field[d.x + dx][d.y + dy] = d.type;
    }
  }
  if ( ! action){
    putBlock(d, true);
  }
 
//  fall_block++;
 
  return true;
}
 
void putNextBlock(){
  int dx,dy,mod,i,j,nx,ny;

  for(i = 0; i < 4; i++){
	for(j = 0; j < 4; j++){
	  next_field[i][j] = 0;
	}
  }
  next_field[1][1] = next.type;
  for (i = 0; i < 3; i++){      //それぞれのブロックを１パーツごとに設定
	dx = blocks[next.type].p[i].x;
	dy = blocks[next.type].p[i].y;
	mod = next.form % blocks[next.type].form;  //ブロックの回転パターン数の最大
	for (j = 0; j < mod; j++){
	  nx = dx, ny = dy;
	  dx = ny; dy = -nx;
	}
	next_field[1+dx][1+dy] = next.type;
  }
}

 


int deleteBlock (DATA d){
  int i,j,dx,dy,nx,ny,mod;
 
  field[d.x][d.y] = 0;      //ブロックを画面から消去
  for (i = 0; i < 3; i++){
    dx = blocks[d.type].p[i].x;
    dy = blocks[d.type].p[i].y;
    mod = d.form % blocks[d.type].form;
    for (j = 0; j < mod; j++){
      nx = dx, ny = dy;
      dx = ny; dy = -nx;
    }
    field[d.x + dx][d.y + dy] = 0;  
  }
  return true;
}

	void update_current(DATA n){
 
   if (n.x != current.x || n.y != current.y || n.form != current.form){
    deleteBlock(current);
    if(putBlock(n, false)){
      current = n;
    }
 
    else{
      putBlock(current,false);
    }
  }
}
	
		 int down_flag=0;
int processInput(){        //キー入力
  int ret = false;
  DATA n = current;
 int i;
	const int waittime = 6;

	for(i = 0; i < USE_KEYBOAD_NUM; i++){
		if(input_wait[i]){
			input_wait[i]--;
		}
	}
	if(down_flag!=0)
	down_flag--;
	
    char keys[32];
  EzQueryKeymap(keys);
 
 
 
  if (EzIsKeyPress(keys, EZ_Left) && input_wait[0] == 0){  //左
    n.x--;
  	input_wait[0] = waittime;
  }
 
  else if (EzIsKeyPress(keys, EZ_Right) && input_wait[1] == 0){   //右
    n.x++;
  	input_wait[1] = waittime;
  }
  else if(EzIsKeyPress(keys, EZ_Down) && down_flag==0){    //下
    n.y--;
    ret = true;
  	down_flag=2;
  }
	if(!EzIsKeyPress(keys,EZ_Left) && !EzIsKeyPress(keys,EZ_Right) && !EzIsKeyPress(keys,EZ_Down)){
			for(i = 0; i < USE_KEYBOAD_NUM; i++){
		if(input_wait[i]){
			input_wait[i]=0;
		}
	}
		
	}
	
	update_current(n);

 
  return ret;
}
 
 
 
int scoreCount(int n){       //スコア計算
 
  if(n == 1){
    score += 40;
  }
  else if(n == 2){
    score += 100;
  }
  else if(n == 3){
    score += 300;
  }
  else if(n == 4){
    score += 1200;
  }
 
  return (score);
}
 
 
void deleteLine(){
  int i,j,x,y;
  int deleted = false;
  for (y = 1; y < 23; y++){
    int flag = true;
    for (x = 1; x <= 10; x++){
      if (field[x][y] == 0){
        flag = false;
      }
    }
 
    if (flag){
	  deleted = true;
      for (j = y; j < 23; j++){
        for (i = 1; i <= 10; i++){
          field[i][j] = field[i][j + 1];
        }
      }
      y--;
      deleted_line++;
    }
  }
	if(deleted_line != sub_deleted_line[CH_SPE_NUM]){
		deleted_line_flag = 1;
  scoreCount(deleted_line - sub_deleted_line[CH_SPE_NUM]);
		sub_deleted_line[CH_SPE_NUM]=deleted_line;
	}
}
 
 
void gameOver(){
state= s_game_over;
}
 
 
int blockDown(void){
	static int wait = 0;
	int flag = 0;
	//printf("%d\n", wait);
  deleteBlock(current);  //動かす前のブロックを消す
  current.y--;
  if ( ! putBlock(current,false)) {
  	if ((wait+=1) < SET_WAIT) {
  		current.y++;
  		putBlock(current,false);
  	} else {
  	wait = 0;
  	flag = 1;
    current.y++;
    putBlock(current,false);   //ブロックを動かし設置する
 fall_block++;
    deleteLine();
 
	current.type = next.type;
	current.form = next.form;

	current.x = 5;
	current.y = 21;

	next.type = rand() % 7 + 1;
	next.form = rand() % 4 + 1;
	putNextBlock();

    if ( ! putBlock(current,false)){
      gameOver();   //ゲームオーバー
  	}
  	}
  }
	return(flag);
}
 
 
void CREATE(void){
  int x,y;
 
  blockImage[1] = EzReadXPM(I_xpm);
  blockImage[2] = EzReadXPM(J_xpm);
  blockImage[3] = EzReadXPM(L_xpm);
  blockImage[4] = EzReadXPM(Z_xpm);
  blockImage[5] = EzReadXPM(S_xpm);
  blockImage[6] = EzReadXPM(O_xpm);
  blockImage[7] = EzReadXPM(T_xpm);
 
  // 初期設定 壁で囲う
  for (x = 0; x < 12; x++){
    for (y = 0; y < 25; y++){
      if (x == 0 || x == 11 || y == 0){
        field[x][y] = 1; //壁:1
      }
      else{
        field[x][y] = 0; //使えるマス:0
      }
    }
  }
     
  //ブロックの初期位置
  current.x = 5;
  current.y = 21;
  current.type = rand() % 7 + 1; 
  current.form = rand() % 4 + 1;
  next.type = rand() % 7 + 1; 
  next.form = rand() % 4 + 1;
  putNextBlock();
	
  putBlock(current, false); //ブロックを置く
 
}
 
void TIMER(void){
 
  static int w = 0;
  if(w % 1 == 0){
    if(processInput()){
	  score += 1;
      w = 0;
    }
  }
  if(w % 120 == 0){
    blockDown();
  }
  w++;
 
}
 
void PAINT(void){
  int x,y,type;
 
  for(x = 1; x <= 10; x++){  //テトリス画面の各マスをオフスクリーンに描写
    for(y = 1; y <= 20; y++){
      if((type = field[x][y]) != 0){
        EzPutB((x - 1) * 20 + 50,(20 - y) * 20 + 60,blockImage[type]);
      }
    }
  }

  for(paint_x = 0; paint_x < 4; paint_x++){
	for(paint_y = 0; paint_y < 4; paint_y++){
	  if((paint_type = next_field[paint_x][paint_y]) != 0){
		EzPutB(paint_x * 20 + NEXT_X,(4 - paint_y) * 20 + NEXT_Y,blockImage[paint_type]);
	  }
	}
  }


//  EzShowBuffer();
}
/*
void timer_handler(void){
 
  TIMER();
  PAINT();
 
}
*/
    /*
int main(void){
 
  CREATE();
   
  //タイマーイベントハンドラを登録する
  EzSetTimerHandler(timer_handler,1000 / 40); 
 
  EzEventLoop();
  
  return 0;
}
    */
