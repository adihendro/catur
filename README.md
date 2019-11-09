# catur
Tugas Besar Alstrukdat Semester 3

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
	
	keterangan char nama : {P:pion ; K:King ; Q:Queen ; B:Bishop ; N:Knight ; R:Rook}
	
Fungsi yang digunakan :
	PrintPapan(piece board[8][8]);
	move();
		int cekbisagerak(piece P); //cek bisa atau tidak {1:bisa ; 0:tidak} kalo bisa kita masukin ke list linier list_bisa_gerak
		void ceksemuagerak(piece P , list_posisi *L); //print semua kotak yang bisa ditempati
		PrintNamaBidak(char c); // ngeprint nama bidak misal Pion , Benteng
	
