#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<fstream>
#include<conio.h>
#include<windows.h>

using namespace std;

int numeroPreguntas = 15;
int numeroOpciones = 5;

void borrar(int a, int b)
{
    fflush(stdin);
    for(int i=a; i<=b; i++)
    {
        gotoxy(1, i);
        clreol();
    }
    fflush(stdin);
}

void cargando()
{
	clrscr();
	int segundos=5;
    for(int i=0; i<=21; i++)
    gotoxy(1, 10);
    cout << "\t\t\t\t   CARGANDO...";
    gotoxy(1, 11);
    for(int i=0; i<=79; i++)
        cout << "_";
    for(int i=0; i<=79; i++)
    {
        cout<<char(219);
        Sleep(segundos*1000/80);
    }
    cout<<"\nCompletado!";
}

string* guardarDato(string buffer, int size, int partes)
{
    string *dato=new string[size];
    char *aux = new char[buffer.length() + 1];
    strcpy(aux, buffer.c_str());
    int i=0;
    dato[i] = strtok(aux, ",");
    for(int j=0; j<=partes-1; j++)
    {
        dato[++i] = strtok(NULL, ",");
    }
    return dato;
}

int* vectorAleatorio(int size, int a, int b)
{
    int *vector=new int[size], aux;
    for(int i=0; i<=size-1; i++)
    {
        aux = (a+(rand()%(b - a + 1)));
        if(i > 0)
        {
            for(int j=0; j<i; j++)
            {
                if(vector[j] == aux)
                {
                    aux = (a+(rand()%(b - a + 1)));
                    j=-1;
                }
            }
        }
        vector[i] = aux;
    }
    return vector;
}

char* convertir(string *datos)
{
	char *resp=new char[numeroPreguntas];
	for(int i=0; i<=numeroPreguntas-1; i++)
	{
		resp[i] = datos[i].at(0);
	}
	return resp;
}

bool comprobarLetra(char letra)
{
	if(letra=='a' || letra=='b'	|| letra=='c' || letra=='d')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool comprobarResp(char op, char respuesta)
{
	if(op == respuesta)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void espacioResp(int pos)
{
	if(pos == 1)
	{
		gotoxy(17, 8);
	}
	else if(pos == 2)
	{
		gotoxy(50, 8);
	}
	else if(pos == 3)
	{
		gotoxy(17, 11);
	}
	else if(pos == 4)
	{
		gotoxy(50, 11);
	}
}

void mostrar(string datos[])
{
	for(int j=0; j<=4; j++)
    {
        if(j==0)
        {
        	gotoxy(4, 5);
            cout<<datos[0];
        }
        else
        {
        	espacioResp(j);
            cout<<datos[j];
        }
    }
}

int ubicar(string resp[], char op)
{
	int i=0;
	if(op == 'a')
	{
		i = 1;
	}
	else if(op == 'b')
	{
		i = 2;
	}
	else if(op == 'c')
	{
		i = 3;
	}
	else if(op == 'd')
	{
		i = 4;
	}
	return i;
}

void seleccionarRespuesta(string res[], char op)
{
	int i=ubicar(res, op);
	textcolor(2);
	espacioResp(i);
	cout<<res[i];
	Sleep(250);
	textcolor(4);
	espacioResp(i);
	cout<<res[i];
	Sleep(250);
}

void mostrarCorrecta(bool res, string resp[], char op)
{
	int i=ubicar(resp, op);
	borrar(8, 11);
	espacioResp(i);
	if(res)
	{
		textcolor(2);
	}
	else
	{
		textcolor(4);
	}
	cout<<resp[i]<<endl;
}

void mostrarResultado(bool op, int dineroC, int dineroI)
{
	if(op)
	{
		borrar(21, 24);
		gotoxy(22, 20);
		cout<<"\tR E S P U E S T A   C O R R E C T A  ! ! ! ";
		gotoxy(22, 21);
		cout<<"\t C O N T I N U A   E L   J U E G O  ! ! !";
		gotoxy(22, 22);
		cout<<"\t   D I N E R O   G A N A D O :   "<<dineroC;
	}
	else
	{
		borrar(21, 24);
		gotoxy(22, 20);
		cout<<"\tR E S P U E S T A   I N C O R R E C T A  ! ! !";
		gotoxy(22, 21);
		cout<<"\t    F I N   D E L    J U E G O  ! ! ! ";
		gotoxy(22, 22);
		cout<<"\t   D I N E R O   G A N A D O :   "<<dineroI;
	}
	fflush(stdin);
	cin.get();
}

void mostrarComodines(string com[])
{
	borrar(12, 24);
	gotoxy(1, 14);
	cout<<"D E S E A   U S A R   U N   C O M O D I N   ? ? ? (s/n)";
	gotoxy(17, 17);
	cout<<com[0];
	gotoxy(50, 17);
	cout<<com[1];
	gotoxy(40, 20);
	cout<<com[2];
	gotoxy(57, 14);
}

char leerComodines(char correcta, int op)
{
	string com[3] = {"**1) LLAMADA TELEFONICA**", "**2) AYUDA DEL PUBLICO**", "**3) 50 / 50**"};
	char opciones[4]={'a', 'b', 'c', 'd'}, final, opFinal;
	int opinion[4], sum=0, numFinal=0;
	borrar(13, 24);
	gotoxy(1, 14);
	cout<<"H A   S E L E C C I O N A D O :  "<<com[op-1];
	if(op == 1)
	{
		for(int i=0; i<=4; i++)
		{
			borrar(15, 24);
			gotoxy(5, 16);
			cout<<"M A R C A N D O";
			for(int i=0; i<=3; i++)
			{
				cout<<'.';
				Sleep(250);
			}
		}
		gotoxy(3, 18);
		final = opciones[0+(rand()%(3 - 0 + 1))];
		cout<<"NO ESTOY MUY SEGURO, OPINO QUE ES LA "<<final;
	}
	else if(op == 2)
	{
		for(int i=0; i<=4; i++)
		{
			borrar(15, 24);
			gotoxy(5, 16);
			cout<<"R E A L I Z A N D O   E N C U E S T A";
			for(int i=0; i<=3; i++)
			{
				cout<<'.';
				Sleep(250);
			}
		}
		gotoxy(3, 18);
		for(int i=0; i<=3; i++)
		{
			if(i==3)
			{
				opinion[i] = 100-sum;
			}
			else
			{
				opinion[i] = 1+(rand()%(33 - 1 + 1));
				sum = sum+opinion[i];
			}
			if(opinion[i] > numFinal)
			{
				numFinal = i;
			}
		}
		cout<<"EL PUBLICO HA OPINADO :"<<endl;
		for(int i=0; i<=3; i++)
		{
			cout<<"\t"<<opciones[i]<<" : "<<opinion[i]<<" %"<<endl;
		}
		final = opciones[numFinal];
	}
	else if(op == 3)
	{
		borrar(15, 24);
		if(correcta == 'a' || correcta == 'd')
		{
			gotoxy(50, 8);
			cout<<"                     ";
			gotoxy(17, 11);
			cout<<"                     ";
		}
		else if(correcta == 'b' || correcta == 'c')
		{
			gotoxy(17, 8);
			cout<<"                     ";
			gotoxy(50, 11);
			cout<<"                     ";
		}
		gotoxy(1, 15);
		return '0';
	}
	do
	{
		if(op != 2)
		{
			borrar(19, 24);
			gotoxy(1, 20);
		}
		else
		{
			borrar(24, 24);
			gotoxy(1, 24);
		}
		cout<<"D E S E A   T O M A R    E S T A   O P C I O N  ? ? ? (s/n)";
		cin>>opFinal;
	}while(opFinal != 's' && opFinal != 'n');
	if(opFinal == 's')
	{
		return final;
	}
	else
	{
		return '0';
	}
}

/*
 *
 */
int main(int argc, char** argv) {
    srand(time(NULL));


    //VARIABLES
    string nombre, *preguntas[numeroPreguntas], buffer, *aux;
    char *respuestas, op, sn, opcom, comFinal, juego;
    ifstream archivoP("/root/Descargas/Millonario/preguntas.txt"), archivoR("/root/Descargas/Millonario/respuestas.txt");
    bool flag;
    int i=0, *numPreg, *numResp, p, opC,
            dinero[16] = {0, 1000, 2500, 4000, 7000, 10000, 15000, 25000, 50000,
                        70000, 100000, 200000, 500000, 700000, 900000, 1000000};

	do
    {
    	string comodines[3] = {"**1) LLAMADA TELEFONICA**", "**2) AYUDA DEL PUBLICO**", "**3) 50 / 50**"};
	    //INICIO Y NOMBRE
	    clrscr();
		gotoxy(25, 8);
		cout<<"QUIEN QUIERE SER MILLONARIO"<<endl<<endl;
		gotoxy(20, 10);
		cout<<"INGRESE SU NOMBRE: "<<endl;
		gotoxy(20, 12);
		cout<<"\t";
	    cin>>nombre;
	    cout<<"ENTER PARA INICIAR"<<endl;
	    getch();
	    cargando();
	    clrscr();


	    //LEER ARCHIVOS Y GUARDAR DATOS
	    while(getline(archivoP, buffer))
	    {
	        preguntas[i] = guardarDato(buffer, numeroPreguntas, numeroOpciones-1);
	        i++;
	    }
	    getline(archivoR, buffer);
	    aux = guardarDato(buffer, numeroPreguntas, numeroPreguntas-1);
	    respuestas = convertir(aux);/****************************/


    //JUEGO

	    i = 0;
	    p = 1;
	    numPreg = vectorAleatorio(numeroPreguntas, 0, numeroPreguntas-1);
	    do
	    {
	    	textcolor(7);
	    	gotoxy(1, 1);
	    	cout<<"\tP R E G U N T A   #  "<<p<<"   P O R   U N   T O T A L   D E   : $$$  "<<dinero[p]<<endl<<endl;

	    	gotoxy(1, 3);
	    	cout<<nombre<<", ";



	    	do
	    	{
	    		textcolor(7);
	    		flag = true;

	    		if(comodines[0]=="" && comodines[1]=="" && comodines[2]=="")
	    		{
	    			opcom == 'n';
		    		mostrar(preguntas[numPreg[i]]);
	    		}
				else
				{
		    		mostrar(preguntas[numPreg[i]]);

		    		do
		    		{
			    		mostrarComodines(comodines);
			    		cin>>opcom;
			    	}while(opcom != 's' && opcom != 'n');
		    		if(opcom == 's')
		    		{
						do
						{
							borrar(15, 15);
							gotoxy(1, 15);
							cout<<"C O M O D I N   N U M E R O : ";
							cin>>opC;
						}while(opC!=1 && opC!=2 && opC!=3);
						comodines[opC-1] = "";
			    		comFinal = leerComodines(respuestas[numPreg[i]], opC);
			    		cin.get();
		    		}
		    	}

	    		if(comFinal == '0' || opcom != 's')
	    		{
	    			borrar(14, 24);
		    		gotoxy(1, 14);
			        cout<<"S U   R E S P U E S T A  :   ";
			        cin>>op;
		    	}
		    	else
		    	{
		    		op = comFinal;
		    	}


		        while(!comprobarLetra(op))
		        {
		        	borrar(14, 24);
		        	gotoxy(1, 14);
			        cout<<"OPCION INVALIDA"<<endl<<endl<<"S U   R E S P U E S T A  :   ";
			        cin>>op;
			        fflush(stdin);
			        cin.get();
		        }
		        do
		        {
		        	borrar(14, 24);
		        	gotoxy(1, 17);
		        	textcolor(7);
		        	cout<<"U L T I M A   P A L A B R A ? ? ?:  (ESP/ESC) ";
		        	seleccionarRespuesta(preguntas[numPreg[i]], op);
		        	if(GetAsyncKeyState(27))
		        	{
		        		flag = false;
		        		break;
		        	}
		        }while(!GetAsyncKeyState(32));
		    }while(!flag);


	        mostrarCorrecta(respuestas[numPreg[i]]==op, preguntas[numPreg[i]], op);

	        mostrarResultado(respuestas[numPreg[i]]==op, dinero[p], dinero[p-1]);


	        clrscr();
	    	i++;
	    	p++;
	    }while(i != 15 && respuestas[numPreg[i-1]]==op);

	textcolor(7);
    cout<<"(s) P A R A   J U G A R   N U E V A M E N T E ? ? ? ? ";
    cin>>juego;
    }while(juego == 's');



    return 0;
}


