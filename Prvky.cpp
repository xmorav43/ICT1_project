#include "Prvky.h"
#include "Exploits.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
//char* gets(char*);
void pressEnterToContinue()
{
	printf("\n[Press Enter To End]");
	while (getchar() != '\n');
}
void postupnyVypis(char text[], int rychlost)
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		printf("%c", text[i]);
		Sleep(rychlost);
	}
}
void gameOver()
{	
	char Konec[] = "\n\n\n\t\tGAME OVER";
	char Kamo[] = " Kaaaamooooo";
	system("cls");
	postupnyVypis(Konec,100);
	postupnyVypis(Kamo,100);
	Sleep(3000);
	system("cls");
	Titulky();
}
void Titulky()
{
	char line[30] = { '\0' };
	char Titulky[] = "Vypracovali:"
		"\n\tMarian Moravcik\t[221561]"
		"\n\tVaclav Navratil\t[221310]"
		"\nV ramci tvurci skupiny s ucenim omezenym"
		"\nDo predmetu ICT1"
		"\n\tSkolniho roku 2020/2021"
		"\nVe mestech"
		"\n\tPrerov\n\tProstejov"
		"\nCerpano z:"
		"\n\tCTFs & STUFF"
		"\n\tExploit Education"
		"\n\tAcunetix"
		"\n\ta dalsi..."
		"\nZa cely team vam dekujeme\n\ta tesime se na vas zase priste."
		"\n\n######-Copyright (c) 2021 - 2022-######";
	postupnyVypis(Titulky,100);
	pressEnterToContinue();
}
void Level()
{	
	const int Zivoty = 3;
	int menu = 0;
	printf("Vitejte v level menu, kde si muzete zvolit, jaky level chcete hrat.\n\n"
		   "  1) Buffer Overflow\n"
		   "  2) Integer Overflow\n"
		   "  3) Format String\n"
		   "  4) Heap\n");
	scanf_s("%d", &menu);
	while (getchar() != '\n');
	switch (menu)
	{
	case 1:
		bufferoOverFlow(Zivoty);
		break;
	case 2:
		integerOverFlow(Zivoty);
		break;
	case 3:
		formatString(Zivoty);
		break;
	case 4:
		Heap(Zivoty);
		break;
	default:
		break;
	}
}
void Hrat(int Zivoty)
{
	boolean Vitezstvi = FALSE;
	char Konec[] = "Uz to nezvladas, tve telo i mysl jsou unavene. Uz se ti dal nechce. Vis ze ven se asi nedostanes,\n"
					"tak radsi zustanes zde, nez se trapit testy dal. Jenze myslenky na tvuj zivot te to nenechaji vzdat\n"
					"a tlaci te vpred. Jen co seberes posledni zbytky sil a vydas se vpred. Tak vidis jak se oteviraji dalsi dvere.\n"
					"Ne jedny, ne dvoje, ale desitky ruznych cest, schodist a otvoru vsude po mistnosti. To byla posledni tecka.\n"
					"Veskera tva energie, nalada a chut k nalezeni vychodu te opousti a ty padas k zemi naplnen bezmoci, beznadeji a nechuti.\n"
	 				"Chlad obepina tve telo a chce se ti spat. S halvou polozenou na rukach pomalu upadas ke spanku. Kdyz v tom slysis\n"
					"Vstavej! Vstavej!! Povidam vstej clovece!!! Kde si myslis, ze spis!?\n"
					"Jsi zapomnel ze se ta aplikace odevzdava zitra zakaznikovi a my musíme prijit na veskere\n"
					"chyby co v tom kodu mohou byt?!?!";
	do {
		if ((Zivoty = bufferoOverFlow(Zivoty))==0) { break; }
		if ((Zivoty = integerOverFlow(Zivoty)) == 0) { break; }
		if ((Zivoty = formatString(Zivoty)) == 0) { break; }
		if ((Zivoty = Heap(Zivoty)) == 0) { break; }
		Vitezstvi = TRUE;
	} while (!Vitezstvi);
	if (Zivoty == 0)
	{
		gameOver();
	}
	else { 
		system("cls");
		postupnyVypis(Konec, 25); 
		pressEnterToContinue();
		system("cls");
		Titulky();
	}

}
void Pokus(int Pokus, char bonusovaNapoveda[])
{
	if (Pokus == 1)
	{
		
		printf("Blahopreji zvladl jsi to na prvni pokus, a proto ziskavas bonusovou napovedu\n"
			   "Dobre si ji opis nebo zapamatuj, protoze uz ji znovu neuvidis.\n");
		printf("[%s]",bonusovaNapoveda);
		pressEnterToContinue();
	}
}

