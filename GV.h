//小下作成

#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern
#endif
//今回はエクスターンしなくてよかった
#include "define.h"
#include <EzGraph.h>

enum STATE{s_ini_title,s_title,s_menu_title,s_select_ch,s_ini_select_ch,s_select_stage,
	s_battle,error_ene_max,error_read_story,s_ini_battle,s_battle_clear,
	s_game_over,error_job_max,error_read_job,s_hi_score,s_check_score};
enum KEYS_E {key_up,key_down,key_left,key_right,key_z,key_x,key_shift};

GLOBAL int cnt;//何フレーム目か
GLOBAL char score_c[256];//スコアを文字列にした奴入れる
GLOBAL int score;//スコア
GLOBAL enum STATE state;//現在の状態、タイトルとか云々
GLOBAL EzImage title_pic;//タイトル画像
GLOBAL EzImage logo_pic;//グループロゴ
GLOBAL EzImage press_z_key_pic;//press z key の画像
GLOBAL EzImage game_start_pic;
GLOBAL EzImage game_end_pic;
GLOBAL EzImage game_start_wait_pic;
GLOBAL EzImage game_end_wait_pic;
GLOBAL EzImage blue_title_pic;
GLOBAL EzImage boad_pic;
GLOBAL EzImage hi_score_pic;
GLOBAL EzImage enemy_pic[ENEMY_KND_NUM];
GLOBAL EzImage high_score_pic;
GLOBAL EzImage high_score_wait_pic;

GLOBAL int press_tmp=0;//press z keyの画像の点滅に使った奴
GLOBAL int press_flag=0;//同上
GLOBAL char keys[32];
GLOBAL int menu_select=0;//今のメニュー選んでる奴指定タイトルのな

GLOBAL int menu_selected=0;//０何もない１ジョブ選択中２特徴選択中
GLOBAL int ch_menu_select=0;//ジョブ選択画面のどれが文字大きくなってるか
GLOBAL int job_select=0;//ジョブをどれ選んでるか
//int job_cond=0;//実際の現在のジョブ
GLOBAL int mag_select = 0;//魔法選択画面でどれ選んでるか
GLOBAL int mag_selected[2];//実際に選ばれた魔法

GLOBAL int chara_select=0;//特徴どれを選んでるか
GLOBAL int chara_select_num = 0;//特徴をいくつ選んだか
GLOBAL int ch_chara[CHARA_MAX]; 

GLOBAL ch_t ch;//自キャラ
GLOBAL ch_t job[JOB_MAX];//ジョブデータ

GLOBAL char story_name[256];//読み込むストーリーファイル指定
GLOBAL enemy_t enemy[ENE_MAX];
GLOBAL int enemy_num;//現在のエネミー数
GLOBAL int enemy_max;//そのステージの敵が何体か記憶
GLOBAL int ene_atk_cnt;//敵の攻撃用にカウントを数える用
GLOBAL int sub_score=0;//前フレームからのスコア上昇値
GLOBAL int fall_block;//落ちたブロックの数、敵の魔法使用条件
GLOBAL int sub_fall_block;//保持用
GLOBAL int clear_score;


GLOBAL int deleted_line=0;//消したライン
GLOBAL int sub_deleted_line[CH_SPE_NUM+1];//消したライン保持用、魔法を複数用意するのでその分必要になった
GLOBAL int deleted_line_flag;
GLOBAL EzImage haruka_pic;
GLOBAL EzImage teki_pic;

GLOBAL int paint_x,paint_y,paint_type;


GLOBAL char *chara[CHARA_NUM]={
	"特に無し","体力に自信","力持ち","打たれ強い","インテリ","折れない心",};
GLOBAL char *chara_ac[CHARA_NUM]={//上の特徴の説明
	"何もなし","HP+10","atk+5","def+5","int+5","res+5",
};

GLOBAL char *mag[CH_SPE_NUM]={
	"魔法なんてなかった","ファイヤー","アイスストーム","ブレインダムド","ジュゲム","ばよえ～ん",
	"癒しなんてなかった","ホイミ","ケアル","ヒール","リカバリー","ＳＴＡＰ細胞（？）",
};
GLOBAL char *mag_ac[CH_SPE_NUM]={
	"期待しても何もない","必要ライン１:威力２００","必要ライン２：威力４５０","必要ライン３：威力７００",
	"必要ライン４：威力９５０","必要ライン１０：威力３０００",
	"癒しを求めても仕方ない","必要ライン１：回復５","必要ライン２：回復１２","必要ライン３：回復１９",
	"必要ライン４：回復２６","必要ライン１０：回復１００",
};
GLOBAL int clear;

GLOBAL char *enemy_name[ENEMY_KND_NUM]={
	"確率統計","課題マシマシ般教","落単の死者・コントウ","自主休講","出席（自習）","離散スマイル","来年もよろしくぅ！",
	"一局打たない？","悪魔神・ＴＯＥＩＣ","大学生だった物","単位を狩る者・ＮＵＬＬ瀬",
	"魔王・ＩＳ","や、僕、オタクじゃないんで。",
};

int enemy_cnt;
int con;
int non_bornus;
