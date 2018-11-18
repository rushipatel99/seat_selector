#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>

using namespace std;

void user_input(int rs, char **s);
void show_seats(int rs, char **s);
int alf_to_dgt(char c);
void exe1_1();
void exe1_2();
char *delete_repeats(const char s[], int sz);
void exe_2();

typedef char* charPtr;


int main()
{

int V_var = 0;
int var_R = 0;

    do{
        cout <<"LAB_7"<<endl;
        cout<<"Select from the following:\n1.Exercise-1\n2.Exercise-2\n3.END"<<endl;
        cin >> V_var;

        if(V_var == 1)
        {

        cout<<"Exercise 1: AirPlane ticket Booking system\n----------------------------------"<<endl;
        cout<<"Select from the following:\n1.Input from the user.\n2.Input from the file."<<endl;
        cin>>var_R;

        if(var_R == 1) // USER INPUT
        {
            exe1_1();
        }

        if(var_R == 2) // FILE INPUT
        {
            exe1_2();
        }
        }

        if(V_var == 2)
        {
            char str[100] = "to be or not to be";
            int size = strlen(str);
            char *norepeat;
            norepeat = delete_repeats(str, size);

            cout << norepeat<<endl;;
        }

        if(V_var == 3)
        {
            exit(0);
        }
}while(V_var != 3);

    return 0;
}


void user_input(int rs, char **s)
{
    show_seats(rs,s);

    int num = 0;
    char alf;
    int p0 = 0;

    int k = rs*4;

    cout<<"airplane has "<<k<<" seats."<<endl;

    for(int i = 0; i < k; i++)
    {

    int var = 0;
    do{
    cout<<"Please select: 1.choose seat  2.END"<<endl;
    cin >> var;

    if(var == 1)
    {
        do{
    cout<<"Please select a seat"<<endl;
    cin >>num>>alf;
    p0 = alf_to_dgt(alf);
    }while(num < 1 || num > rs || (alf != 'A' && alf != 'B' && alf != 'C' && alf != 'D') || s[num -1][p0] == 'X');

    s[num-1][p0] = 'X';

    show_seats(rs, s);
    }

    if(var == 2)
    {
        cout<<"This is the final booking."<<endl;
        show_seats(rs, s);
        exit(0);
    }
    }while(var != 1 && var != 2);
    }
}

void show_seats(int rs, char **s)
{
    for(int i = 0; i < rs; i++)
    {
        cout<<setw(3)<<i+1;
        for(int j = 0; j < 4; j++)
        {
            cout<<" "<<s[i][j];
        }

        cout<<endl;
    }
}

int alf_to_dgt(char c)
{
    int p_new = 0;

    if(c == 'A')
    p_new = 0;

    else if(c == 'B')
    p_new = 1;

    else if(c == 'C')
    p_new = 2;

    else if(c == 'D')
    p_new = 3;

    return p_new;
}

void exe1_1()
{
    int rowsize;
        charPtr *seats;
        charPtr colA;
        charPtr colB;
        charPtr colC;
        charPtr colD;

        cout<<"How many rows?"<<endl;
        cin >> rowsize;

    colA = new char[rowsize];
    colB = new char[rowsize];
    colC = new char[rowsize];
    colD = new char[rowsize];

    seats = new charPtr[rowsize];

    for(int i = 0; i < rowsize; i++)
    {
        seats[i] = new char[4];
    }

    char a[rowsize];
    char b[rowsize];
    char c[rowsize];
    char d[rowsize];

    for(int i = 0; i < rowsize; i++)
    {
        a[i] = 'A';
        b[i] = 'B';
        c[i] = 'C';
        d[i] = 'D';
    }

    colA = a;
    colB = b;
    colC = c;
    colD = d;



    seats[rowsize][4];
    for(int i = 0; i < rowsize; i++)
    {
        seats[i][0] = a[i];
        seats[i][1] = b[i];
        seats[i][2] = c[i];
        seats[i][3] = d[i];
    }


            user_input(rowsize, seats);



            delete []colA;
            delete []colB;
            delete []colC;
            delete []colD;
}

void exe1_2()
{
    ifstream ifs;
    ofstream ofs;

    ifs.open("one.txt");
    if(ifs.fail())
    {
    	cout<<"input file open FAILED!"<<endl;
    	exit(1);
    }

    ofs.open("o_one.txt");
    if(ofs.fail())
    {
    	cout<<"output file open FAILED!!!"<<endl;
    }

    charPtr fcolA;
    charPtr fcolB;
    charPtr fcolC;
    charPtr fcolD;
    int frowsize;

ifs>>frowsize;

    fcolA = new char[frowsize];
    fcolB = new char[frowsize];
    fcolC = new char[frowsize];
    fcolD = new char[frowsize];


    charPtr *fseats;
    fseats = new charPtr[frowsize];

    for(int i = 0; i < frowsize; i++)
    {
        fseats[i] = new char[4];
    }

    char fa[frowsize];
    char fb[frowsize];
    char fc[frowsize];
    char fd[frowsize];

    for(int i = 0; i < frowsize; i++)
    {
        fa[i] = 'A';
        fb[i] = 'B';
        fc[i] = 'C';
        fd[i] = 'D';
    }

    fcolA = fa;
    fcolB = fb;
    fcolC = fc;
    fcolD = fd;



    fseats[frowsize][4];
    for(int i = 0; i < frowsize; i++)
    {
        fseats[i][0] = fa[i];
        fseats[i][1] = fb[i];
        fseats[i][2] = fc[i];
        fseats[i][3] = fd[i];
    }


    int fnum = 0;
    char falf;
    int fp0 = 0;


    while(true)
    {
    ifs >>fnum>>falf;

    fp0 = alf_to_dgt(falf);

    if((fnum != 3 && falf != 'Z') && fseats[fnum - 1][fp0] == 'X')
    {
    	ofs << fnum<<falf<<"!"<<endl;
    }

    if(fnum == 3 && falf ==  'Z')// 3Z shows end.
    {
    	show_seats(frowsize, fseats);
        exit(0);
    }

    fseats[fnum-1][fp0] = 'X';
    }

    delete []fcolA;
    delete []fcolB;
    delete []fcolC;
    delete []fcolD;

}

char *delete_repeats(const char s[],int sz)
{
    char *nR = new char[sz + 1];

    nR[0] = s[0];

    int k = 1;

    for(int i = 1; i < sz; i++)
    {
        bool repeat = false;
        for(int j = 0; j < i; j++)
        {
           if(s[i] == s[j])
           {
               repeat = true;
               break;
           }
        }

        if(!repeat)
        {
            nR[k] = s[i];
            k++;
        }
    }

    return nR;
}

void exe_2()
{
    char str[100] = "to be or not to be";
int size = strlen(str);
char *norepeat;
norepeat = delete_repeats(str, size);

cout << norepeat;

delete []str;
delete []norepeat;
}


/*
 *
 *
 * OUTPUT
 *
 * Exe-1-UserInput
 *
 * LAB_7
Select from the following:
1.Exercise-1
2.Exercise-2
3.END
1
Exercise 1: AirPlane ticket Booking system
----------------------------------
Select from the following:
1.Input from the user.
2.Input from the file.

1
How many rows?
5
  1 A B C D
  2 A B C D
  3 A B C D
  4 A B C D
  5 A B C D
airplane has 20 seats.
Please select: 1.choose seat  2.END
1
Please select a seat
3A
  1 A B C D
  2 A B C D
  3 X B C D
  4 A B C D
  5 A B C D
Please select: 1.choose seat  2.END
1
Please select a seat
2A
  1 A B C D
  2 X B C D
  3 X B C D
  4 A B C D
  5 A B C D
Please select: 1.choose seat  2.END
1
Please select a seat
3A
Please select a seat
3C
  1 A B C D
  2 X B C D
  3 X B X D
  4 A B C D
  5 A B C D
Please select: 1.choose seat  2.END
1
Please select a seat
2B
  1 A B C D
  2 X X C D
  3 X B X D
  4 A B C D
  5 A B C D
Please select: 1.choose seat  2.END
1
Please select a seat
2C
  1 A B C D
  2 X X X D
  3 X B X D
  4 A B C D
  5 A B C D
Please select: 1.choose seat  2.END
1
Please select a seat
4A
  1 A B C D
  2 X X X D
  3 X B X D
  4 X B C D
  5 A B C D
Please select: 1.choose seat  2.END
1
Please select a seat
5D
  1 A B C D
  2 X X X D
  3 X B X D
  4 X B C D
  5 A B C X
Please select: 1.choose seat  2.END
1
Please select a seat
5C
  1 A B C D
  2 X X X D
  3 X B X D
  4 X B C D
  5 A B X X
Please select: 1.choose seat  2.END
1
Please select a seat
5B
  1 A B C D
  2 X X X D
  3 X B X D
  4 X B C D
  5 A X X X
Please select: 1.choose seat  2.END
1
Please select a seat
3C
Please select a seat
3B
  1 A B C D
  2 X X X D
  3 X X X D
  4 X B C D
  5 A X X X
Please select: 1.choose seat  2.END
1
Please select a seat
1A
  1 X B C D
  2 X X X D
  3 X X X D
  4 X B C D
  5 A X X X
Please select: 1.choose seat  2.END
1
Please select a seat
1C
  1 X B X D
  2 X X X D
  3 X X X D
  4 X B C D
  5 A X X X
Please select: 1.choose seat  2.END
2
This is the final booking.
  1 X B X D
  2 X X X D
  3 X X X D
  4 X B C D
  5 A X X X
 *
 *
 * --------------
 *
 * Exe-1-FileInput
 *
 *LAB_7
Select from the following:
1.Exercise-1
2.Exercise-2
3.END
1
Exercise 1: AirPlane ticket Booking system
----------------------------------
Select from the following:
1.Input from the user.
2.Input from the file.
2
  1 A B C D
  2 X X C X
  3 X X X D
  4 X X X X
  5 X X X X
  6 X X C X
  7 X B X X
  8 A B C D
  9 X B C D
 10 A X X X
 11 A X X D
 12 X X X X
 13 X B X D
 14 X B X X
 15 A X C D
 16 X B X D
 17 A B C X
 18 X X X X
 *
 *
 *-----------------------------------
 *
 *Exe - 2
 *
 *LAB_7
Select from the following:
1.Exercise-1
2.Exercise-2
3.END
2
to bern
LAB_7
Select from the following:
1.Exercise-1
2.Exercise-2
3.END
3
 *
 *
 */

