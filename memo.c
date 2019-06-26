//小下作成

ピロ氏の関数ちょっと変えた

http://k-0n.com/
けいおん風ジェネレーター
http://www5d.biglobe.ne.jp/~gakai/
きまぐれアフター
http://www.squarespace.com/logo
Squarespace Logo

http://hmq.pos.to/gallery/
HMQ
http://hmq.pos.to/log/08spring.html
背景のいい感じの




main(){
		/*
	優先順位
		必須
			・テトリス本体
			・ステージ最低一つ
			・スタートとエンドのみのタイトル
		無いとかなり寂しい
			・ジョブ選択
			・選べなくてもせめて数ステージ（多分ステージ一つ作ったら簡単に増やせる、マリオでいうワールド１作る）
			・ジョブの固有効果の処理
			・ハイスコア
		無いと寂しそう
			・ジョブごとのボムと特殊エフェクト（簡単なのでいいから）
			・ステージ選択、マリオでいうワールド選択
			・ジョブ以外にもプレイヤーに選ばせる特殊効果、特徴
		欲しい
			・クリアのたびにポイント入って購入、簡単な引き継ぎ要素みたいなの
			
	これも下のループも適当に書いてるからいろいろ抜けてそう、目安程度に
	*/
	while(){//メインループ、今回はタイムハンドラーかなんかがこれになるっぽい
		switch(state){
		case 初回のみの処理、よくあるのはメーカー名出るとこみたいなの
			load_ini()//データのロード、画像とか
			first_ini()//初回の初期化
			state=タイトル
			break;
	case タイトル、メニュー選ばせる
		title_load_ini()//タイトルの初期化、画像とか読んだりハンドル与える,load_iniにまとめてもいいかも
		title_menu()//メニューの表示と選んだメニューに応じてstateを変える
		graph_title//タイトル描写
		break;
	case ゲーム開始準備、ジョブ選択とか
		job_menu//ジョブ選択とかのメニュー表示、選択、決定
		break;
	case ステージの選択
		stage_menu;//ステージの選択、決定
	case ステージ開始の瞬間
		load_stage//ステージのデータを読み込む、敵の出るタイミングやらパラメータやら次のステージないしラストかとか
		load_ch//選択された自キャラを登録する
	case ステージ本番（テトリス）
		calc_tet//テトリスの計算、スコアを返す	
	  /*	ch_main//自キャラの計算、スコアに応じて攻撃とかボムとか
			enemy_main//敵キャラの計算、攻撃とか敵の入れ替わりとか云々 */
	  battle_main()
	graph_tet//テトリスの描写、スコア表示
	graph_main//描写メイン、自キャラ敵キャラ
	  break;
	case ステージ終了
		calc_end_stage//ステージのスコア等の取得、
		//現在のステージから次のステージないし最終スコアとかも計算
				if(ステージクリアして次のステージあるなら）{
				graph_next_stage_menu;//次のステージの表示とか選ばせてみたりとかスコア表示とか
				state=ステージ開始の瞬間
				}
				if(ステージがそこで終わりないしゲームオーバーなら）{
				graph_end_stage//描写、ステージが終わる時用、スコアとかスコア登録するならニックネーム入力とか
				state=終了後のおまけみたいなの（実装するなら）
				}
		break;
	case ゲーム終了後のおまけ
			//なんか取得スコアからポイント獲得してジョブ解放とか入れたら楽しいかもね
			state=タイトル
			break;
		default:不明な状態、エラー表示
		break;
		}
	}
}

int sub_score=0;
int deleted_line=0;
		
		
void ch_main(void){


  ch_atk();//スコアサブに応じて相手のHPを減らす
  ch_mag();//消したラインに応じてどーん、相手のHPを減らす
  deleted_enemy();//もし敵がHP死んでたらフラグをゼロにしてstate=deleting_enemyにする
}
battle_state


battle_main{


  sub_score = score - sub_score;//前フレームからのスコアの上昇値
  sub_deleted_line = deleted_line - sub_deleted_line;//前フレームからの消したライン


  ch_main();
  if(state !=  deleting_enemy)
	enemy_main();
  else
	delete_enemy();
}


int fall_block_num;

enemy_main(void){


  enemy_atk();//一定フレーム経過で攻撃、フレームはint cnt;に保持、主人公のHPを減らすンゴ
  enemy_mag();//一定数ブロック落とすと攻撃、主人公のHPを減らすンゴ
  if(主人公のHPが０以下になっていたらんごごごご）
	ゲームオーバーうい;

}








