# catur
Tugas Besar Alstrukdat Semester 3

variabel global :
	int poin_putih;
	int poin_hitam;
	List list_ada_putih;
	List list_ada_hitam;
	piece board[10][10];
	stack history;
	stack termakan;
	Queue giliransiapa;


ADT :
	List linier, list : (list_ada_putih ; list_ada_hitam)
	List linier, list_bisa_gerak
	List linier, list_posisi //daftar kotak yang bisa ditempati kemudian
	
	typedef struct {
			infotype info;
			address next;
		} List //untuk list_ada_putih & list_ada_hitam

	typedef struct {
			infotype info;
			address next;
			address parent;
		} List //untuk list_bisa_gerak

	typedef struct {
			infotype_posisi info;
			address next;
		} list_posisi

	typedef struct {
			int posisiR;
			int posisiC;
		} infotype_posisi
	typedef piece infotype;

	typedef struct {
			char nama;
			int player;
			int poin;
			int posisiR;
			int posisiC;
		} piece
	
	stack history;

	typedef struct {
			address Top;
			infotype_stack T[MaxEl]; //MaxEl = 40
		} stack // untuk history dan termakan

	typedef struct {
			char nama;
			int player;
			int turn;
			int posisiR;
			int posisiC;
		} infotype_stack
	
	keterangan char nama : {P:pion ; K:King ; Q:Queen ; B:Bishop ; N:Knight ; R:Rook}
	
Fungsi yang digunakan :

	PrintPapan(piece board[8][8]);
	move();
		int cekbisagerak(piece P); //cek bisa atau tidak {1:bisa ; 0:tidak} kalo bisa kita masukin ke list linier list_bisa_gerak
		void cekSemuaGerak(piece P , list_posisi *L); //print semua kotak yang bisa ditempati
		void PrintNamaBidak(char c); // ngeprint nama bidak misal Pion , Benteng
		boolean adaorang(piece board , int kolom , int row); // cek apakah di kotak itu ada orang atau tidak

	fungsi-fungsi reborn :
		void Push_reborn(Stack *S , infotype X); //infotypenya beda
		void InsVLast_reborn(List *L , infotype X); //infotypenya beda
		address Search_reborn(List L , int kolom , int row); //pencarian berdasarkan kolom dan row
		void DelP_reborn(List *L , int kolom , int row); // pencarian berdasarkan kolom dan row 
		
	
