int main(void){
	int uno;
	int due;
	const int tre = 3;

	uno = 1;
	due = (uno + 1);
	tre = due + 1;	/* ERRORE!
			 * tre è una costante (non è modificabile) non può essere usato come lvalue 
			 * di un opeatore di assegnamento.
			 */
	due = tre - 1;
}
