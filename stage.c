//�����쐬
//������Ɗ֐��|�C���^�̂�����l�����ق��������B���

int delete_enemy=0;

void enemy_atk(void){//�J�E���g�ōU��
	if( cnt - ene_atk_cnt > enemy[enemy_num].atk_num ){
		ch.hp -= enemy[enemy_num].atk * ( 100- ch.def) / 100;
		ene_atk_cnt = cnt;
	}
}

//////////////////
void enemy_mag_1(void){//�u���b�N���Ƃ��ƈ�萔�ōU��
	///enemy.inte����b�_��
		if(  fall_block -  (fall_block % 10) !=  sub_fall_block ){
			ch.hp -= enemy[enemy_num].inte * ( 100 - ch.res ) / 100;
		sub_fall_block = fall_block - (fall_block % 10);
	}
	
}


void (*enemy_mag[1])(void)={
	enemy_mag_1,
};


void enemy_mgatk(void){
	int mag_dam,mag_heal;
	
	enemy_mag[0]();
	//�Ƃ肠�����P������������{�X�Œǉ����Ă��������ǕK�v�Ȃ���
	
}


void enemy_main(void){
	
	enemy_atk();
	enemy_mgatk();
	
	if( ch.hp < 0 )
	state = s_game_over;
	
}


int ch_atk(void){
	
	if(score > sub_score && deleted_line_flag == 1){
		enemy[enemy_num].hp -= (score - sub_score) *  ch.atk * (100 - enemy[enemy_num].def )  / 10000 ;//���ݏo�����Ă���G����HP�����炷
		sub_score = score;
		deleted_line_flag = 0;
		}
		
	
}


void mag_atk(int mag_pow,int need_line,int mag_num){
	
		if(  deleted_line -  (deleted_line % need_line) !=  sub_deleted_line[mag_num]){
			enemy[enemy_num].hp -= mag_pow * ch.inte * (100 - enemy[enemy_num].res) / 10000;
			sub_deleted_line[mag_num] = deleted_line - (deleted_line % need_line);
		}
}
void mag_heal(int mag_pow,int need_line,int mag_num){
		if(  deleted_line -  (deleted_line % need_line) !=  sub_deleted_line[mag_num]){
			if(ch.hp_max > ch.hp + mag_pow)
				ch.hp += mag_pow;
				else
				ch.hp = ch.hp_max;
			sub_deleted_line[mag_num] = deleted_line - (deleted_line % need_line);
		}
}
void ch_mag_0(void){
}


void ch_mag_1(void){
/*�t�@�C�A�[�A��Ԏア��
	�e�g���X���S���C���łP�Q�O�O�̊�b�_���Ȃ̂ł�����͂P���C���łQ�T�O���炢����l�q��
	*/
	mag_atk(200,1,1);
	
}

void ch_mag_2(void){
	/*�A�C�X�X�g�[���A�Q�Ԗ�*/
	mag_atk(450,2,2);
}

void ch_mag_3(void){
	mag_atk(700,3,3);
}

void ch_mag_4(void){
	mag_atk(950,4,4);
	
}

void ch_mag_5(void){
	mag_atk(3000,10,5);
	
}
void ch_mag_6(void){
}

void ch_mag_7(void){
	mag_heal(5,1,7);
}

void ch_mag_8(void){
mag_heal(12,2,8);
}

void ch_mag_9(void){
	mag_heal(19,3,9);
}

void ch_mag_10(void){
	mag_heal(26,4,10);
}
void ch_mag_11(void){
	mag_heal(100,10,11);
}

	

//�X�C�b�`���ׂ�̂߂�ǂ��̂ƍ��㖂�@���₷�\��Ȃ̂łŊ֐��|�C���^�Ŏw��
//���@�ɂ���Č��ʂ��낢�낵�����̂Ŋg������������Ń_���[�W�^�����肷��ėp���ۂ��̂͂�߂�
//���ꂼ��ɂ��Ċ֐�������悤�ɂ��Ƃ����ǂ����܂Ŏ��Ԃ��邩�s��
//���Ԃ̓s���ł���Ȃɕ��G�Ȃ͍̂�肻���ɂȂ��Ȃ�����Ɍv�Z�������ʉ����������ǉ񕜂Ƃ�����邵
//�Ȃɂ�肱�����̂����₷���̂ł��̂܂܊֐��|�C���^�Ői�s�B
//�\���̂ł��悩�������ǂ������̂��g�������邵����ł����ł���
void (*ch_mag[CH_SPE_NUM])(void) = {
	ch_mag_0,ch_mag_1,ch_mag_2,ch_mag_3,ch_mag_4,ch_mag_5,
	ch_mag_6,ch_mag_7,ch_mag_8,ch_mag_9,ch_mag_10,ch_mag_11,
};

	
	

void ch_magatk(void){//���������C�������Ŗ��@�U��
	ch_mag[ch.spe[0]]();
	ch_mag[ch.spe[1]]();
}

void ch_main(void){
	
	ch_atk();//�X�R�A�T�u�ɉ����đ����HP�����炷
	ch_magatk();//���������C���Ŗ��@
	
	if(enemy[enemy_num].hp <= 0 ){
		delete_enemy=1;
		enemy_cnt++;
		if( enemy_max != enemy_num)//���̃X�e�[�W�ɂ܂��G�����邩
			enemy_num++;
		else
			state = s_battle_clear;
	}
}

void ch_graph(void){
char st[64];	
//	EzPutB(60,500,haruka_pic);//�A�C�R��
	EzSetFontSize(25);
	int set_x,set_y;
	int sub_x,sub_y;
	set_x = 430; set_y = 350;
	//EzDrawIntB(650,385,ch.hp);
	sprintf(st,"%d / %d",ch.hp,ch.hp_max);
	EzDrawStringB(650,400,st);
	
	if(ch.hp < 25)
	EzSetColorByName("Red");
	else
	if(ch.hp < 50)
	EzSetColorByName("Yellow");
	else
	EzSetColorByName("Green");
	EzFillBoxB(560,350,560 + (ch.hp * 2),370);
	
	EzDrawStringB(430,350,ch.name);
	
	EzSetColorByName("White");
	
	set_x = 450; set_y = 430 ;
		sub_x = 100; sub_y = 20;
	EzSetFontSize(20);
	
	EzDrawStringB(set_x,set_y + sub_y,"atk");   EzDrawIntB(set_x + sub_x,set_y + sub_y,ch.atk);
	EzDrawStringB(set_x + ( 2 * sub_x),set_y + sub_y,"def"); EzDrawIntB(set_x + ( 3 * sub_x),set_y + sub_y,ch.def);
	
	EzDrawStringB(set_x,set_y + (2 * sub_y),"int");  EzDrawIntB(set_x + sub_x,set_y + ( 2 * sub_y),ch.inte);
	EzDrawStringB(set_x + ( 2 * sub_x),set_y + ( 2 * sub_y),"res"); EzDrawIntB(set_x + ( 3 * sub_x),set_y + ( 2 * sub_y),ch.res);
	
	EzDrawStringB(set_x,set_y + (3 * sub_y),mag[ch.spe[0]]);
	EzDrawStringB(set_x + 30,set_y + (4 * sub_y),mag_ac[ch.spe[0]]);
	
	EzDrawStringB(set_x,set_y + (5 * sub_y),mag[ch.spe[1]]);
	EzDrawStringB(set_x + 30,set_y + (6 * sub_y),mag_ac[ch.spe[1]]);
}

void enemy_graph(void){
	char ene_hp[64];
	
	EzPutB(0,0,enemy_pic[enemy[enemy_num].lookknd]);//�G�����G
	EzDrawStringB(530,240,enemy_name[enemy[enemy_num].lookknd]);
	sprintf(ene_hp,"%7d/%7d",enemy[enemy_num].hp, enemy[enemy_num].hp_max);
	EzDrawStringB(600,270,ene_hp);
	
}

void tet_graph(void){
	
	  EzSetFontSize(30);
	EzDrawIntB(120,540,score);
	EzDrawIntB(285,500,deleted_line);
	
	EzSetFontSize(20);
}


void battle_main(void)
{

	EzPutB(0,0,boad_pic);

	ch_main();
	/*
	if(state != deleting_enemy)
	enemy_main();
	else
	delete_enemy();
	*/
	
	if(delete_enemy == 0)
	enemy_main();
 TIMER();
  PAINT();
	tet_graph();
	

	ch_graph();
	enemy_graph();
	delete_enemy = 0;
}

