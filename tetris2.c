/*
#include <stdio.h>
#include <EzGraph.h>
#include <stdlib.h>
*/


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
DATA current;              //ブロック落下中のデータ

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

  fall_block++;

  return true;
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



int processInput(){        //キー入力
  int ret = false;
  DATA n = current;

 // char keys[32];
  EzQueryKeymap(keys); 



  if (EzIsKeyPress(keys, EZ_Left)){  //左
	n.x--;
  }

  else if (EzIsKeyPress(keys, EZ_Right)){   //右
	n.x++;
  }

  else if(EzIsKeyPress(keys, EZ_Up)){     //Zで回転
	n.form++;
  }

  else if(EzIsKeyPress(keys, EZ_Down)){    //下
	n.y--;
	ret = true;
  }

  if (n.x != current.x || n.y != current.y || n.form != current.form){
	deleteBlock(current);
	if(putBlock(n, false)){
	  current = n;
	}

	else{
	  putBlock(current,false);
	}
  }

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
  for (y = 1; y < 23; y++){
	int flag = true;
	for (x = 1; x <= 10; x++){
	  if (field[x][y] == 0){
		flag = false;
	  }
	}

	if (flag){
	  for (j = y; j < 23; j++){
		for (i = 1; i <= 10; i++){
		  field[i][j] = field[i][j + 1];
		}
	  }
	  y--;
	  deleted_line++;
	}
  }
  scoreCount(deleted_line);
}


void gameOver(){
state= s_game_over;
}


void blockDown(){
  deleteBlock(current);  //動かす前のブロックを消す
  current.y--;
  if ( ! putBlock(current,false)) {
	current.y++;
	putBlock(current,false);   //ブロックを動かし設置する

	deleteLine();

	current.x = 5;
	current.y = 21;
	current.type = rand() % 7 + 1;
	current.form = rand() % 4 + 1;
	if ( ! putBlock(current,false)){
	  gameOver();	//ゲームオーバー
	}
  }
}


void CREATE(void){
  int x,y;

  blockImage[1] = EzReadXPM(S_xpm);
  blockImage[2] = EzReadXPM(T_xpm);
  blockImage[3] = EzReadXPM(I_xpm);
  blockImage[4] = EzReadXPM(Z_xpm);
  blockImage[5] = EzReadXPM(J_xpm);
  blockImage[6] = EzReadXPM(L_xpm);
  blockImage[7] = EzReadXPM(O_xpm);

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
	
  putBlock(current, false); //ブロックを置く

}

void TIMER(void){

  static int w = 0;
  if(w % 2 == 0){
	if(processInput()){
	  w = 0;
	}
  }
  if(w % 5 == 0){
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

