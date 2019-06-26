//小下作成

#ifdef debug_now




void debug(void){
	EzDrawIntB(50,50,score);
	EzDrawIntB(100,50,deleted_line);
	EzDrawIntB(150,50,deleted_line_flag);

}
#else

void debug(void){}

#endif
