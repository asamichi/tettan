# てとたん　テトリスX単位取得を巡る戦い<br>
大学１年生の際に、友人らと３人チームで作成したゲームです。<br>
動作環境はlinuxです<br>
tettanが実行ファイルなので、それを実行してください。<br>
<br>
本プログラムのコンパイルには以下のライブラリが必要です。<br>
http://www.arch.info.mie-u.ac.jp/~sasaki/hobby/software/EzGraph/<br>
ライブラリ導入方法等は上記リンクを参照してください。<br>
<br>
担当<br>
自分：企画、プログラム設計、UI設計、画像素材作成、戦闘処理等のテトリス本体以外の実装等<br>
甘い物好きな友人:テトリス部分の実装<br>
麻雀好きな友人:一部ファイル読み込み処理の実装、フレーバーテキスト<br>
<br>
ファイルが散らかってるの等は、<br>
当時の思い出としてあえてそのままおいてあります。<br>

## 概要
各教科の単位を取得するべく奮闘するテトリスです。最後まで生き残れればめでたく単位を取得できます。<br>
ゲームを起動するとタイトル画面が表示され、ステージ開始前に職業と学科、アピールポイントを選択し、個性豊かなプレイヤーキャラで敵に立ち向かいましょう。<br>
テトリミノを操作して課題をこなして行き、道中の敵（講義やレポート）を倒していきましょう。先生方の思いやりに答えてすべてのレポートやテストをこなしましょう（消してこなしましょう）<br>
見事すべての試練を乗り越え、単位を取らせてあげましょう。<br>
テトリス初心者も楽しめるように、スコアからのダメージ計算だけでなく（スコアからの算出だとテトリス連続が大きく有利になる）、消したラインの数からもダメージを与えられるようになっています（一列ずつ消していっても割とダメージがでる）<br>
ちなみにスコア計算は物理、ライン計算は魔法です。<br>
回復魔法はステータスに影響されません。<br>
あと敵は大学生の勉強を妨げる誘惑や厳しいレポート、講義です<br>
<br>
## ざっくり内容
起動後はタイトル画面が表示されます。<br>
ハイスコアを選ぶと今までのハイスコアが上位１０位まで表示されます。<br>
ゲームエンドを選べばプログラムが終了します。<br>
ゲームスタートを押すとキャラクター作成画面に入ります。<br>
ジョブを選んで基本パラメータを決定し、アピールポイントで好みのパラメータに調整しましょう。<br>
ジョブはそれぞれステータスに個性があるのでプレイスタイルに応じたものを選ぶと有利です（テトリスぶっぱは物理系、ちょこちょこ消すなら魔法系）<br>
次に攻撃魔法を一つ選びます。<br>
基本的に必要ラインが多いほど１ライン当たりのダメージは多くなります。<br>
回復魔法も同様です。<br>
また、特徴、魔法は選ばないことも可能なので自身のある方は試してみるといいかもしれません。職業も「１２年目」に関しては意図的に弱く調整してあります。<br>
<br>
テトリスはｚで←、ｘで→回転です<br>
↑を押すとクイックドロップができます。<br>
敵は一定時間ごとに物理攻撃、一定数テトリミノを落とすと魔法攻撃を仕掛けてきます。<br>
<br>
＊デバッグ用として、jで消したライン増加、kで敵のHPを１００減らします。


以下スクリーンショット<br><br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/1.jpg"><br>
グループのロゴ<br>
雰囲気を出しつつ、画像の読み込み時間をごまかしてます。<br>
<br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/2.jpg"><br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/3.jpg"><br>
タイトル。文字の影とかは自作。<br><br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/4.jpg"><br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/5.jpg"><br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/6.jpg"><br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/7.jpg"><br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/8.jpg"><br>
キャラクリエイト。<br>
友人のフレーバーテキストは、自分では思いつかないような勢いがある。<br>
<br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/9.jpg"><br>
ゲーム画面。<br>
敵は単位やら<br>
<br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/10.jpg"><br>
教授の名言（？）やら<br>
<br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/11.jpg"><br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/12.jpg"><br>
特定の教授を思い出す名前の敵もいる。<br>
<br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/13.jpg"><br>
クリア後の画面。<br>
弱いビルドにはボーナススコア等もある。<br>
<br>
<img src="https://github.com/asamichi/tettan/blob/master/screenshot/14.jpg"><br>
ランキング画面。<br>
<br>
<br>
あとになって思うことなど<br>
コードの綺麗さとかはさておき、
#includeをおまじないで済まさず勉強したせいで、<br>
Cファイルをincludeする暴挙に出ている<br>
あと、ファイル構成がよろしくない。<br>
どちらも、コンパイルコマンドが長くなる等の手間を省く目的のせいだが、<br>
初学者＋短期間開発ゆえ仕方ないか。<br>
シェルスクリプト時代を経て、<br>
今の自分ならMakefileできれいにするのにとか、<br>、
コメント量やらコーディング面等、<br>
改善点が多く見えるのは成長の証かもしれない。<br>






